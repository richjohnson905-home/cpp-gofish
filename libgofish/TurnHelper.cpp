//
// Created by Richard Johnson on 3/21/21.
//

#include "TurnHelper.h"
#include "Log.h"
#include "MvcController.h"

using std::pair;
using std::vector;
using std::optional;
using std::make_pair;

TurnHelper::TurnHelper(IStrategyHelper &helper, IPlayer& me)
:m_helper(helper),
m_me(me){

}

bool TurnHelper::easyFish(std::vector<IPlayer *> &players)
{
    optional<pair<IPlayer*, int>> optPlayerAndBait = m_helper.goEasyFishing(&m_me, players);
    if (optPlayerAndBait.has_value())
    {
        L_(ldebug1) << "Fishing the easy way";
        optional<vector<Card*>> optCards = askPlayer(optPlayerAndBait);
        if (optCards.has_value())
        {
            L_(ldebug1) << " LIKE FISHING IN A BARRELL " << optCards.value().size();
            acceptCards(optCards.value());
            m_me.makeBooks();
            return true;
        }
        else
        {
            L_(lerror) << "DEV ERROR: This should never happen.";
        }
    }
    return false;
}

bool TurnHelper::hardFish(std::vector<IPlayer *> &players, Deck& deck)
{
    if( auto p = m_helper.getFishPlayer(players))
    {
        if (p.has_value()) {
            L_(ldebug1) << "Fishing the hard way with: " << p.value()->getName();
            int bait = m_helper.getBaitCard(&m_me);
            m_me.pushEasyFish(bait);
            optional<pair<IPlayer *, int>> optPlayerAndBait = make_pair(p.value(), bait);
            vector<Card *> cards = askPlayer(optPlayerAndBait);
            if (!cards.empty()) {
                L_(ldebug1) << " Hard-won cards size: " << cards.size();
                acceptCards(cards);
                m_me.makeBooks();
                return true;
            } else {
                return deckFish(deck, bait);
            }
        } else {
            L_(linfo) << "THERE ARE NO MORE PLAYERS";
        }
    }
    return false;
}

bool TurnHelper::deckFish(Deck& deck, int bait)
{
    if (deck.getDeckSize() > 0) {
        Card* c = deck.dealCard();
        L_(ldebug1) << "\t" << m_me.getName() << " told to GO FISH. Deck card: " << c->getValue();
        m_me.pushHandCard(c);
        m_me.makeBooks();
        return c->getValue() == bait;
    } else {
        L_(ldebug1) << m_me.getName() << " Deck empty!";
        return false;
    }
}

vector<Card*> TurnHelper::askPlayer(std::optional<std::pair<IPlayer*, int>>& optPair)
{
    if(optPair.has_value())
    {
        return m_me.askPlayerForCards(optPair.value().first, optPair.value().second);
    }
    return vector<Card*>();
}

void TurnHelper::acceptCards(std::vector<Card *> &fishedCards)
{
    std::stringstream ss;
    for(auto it = fishedCards.begin(); it != fishedCards.end(); ++it) {
        ss << (*it)->getValue() << " ";
    }
    L_(ldebug1) << " caught cards " << ss.str();

    if (!fishedCards.empty()) {
        L_(ldebug1) << m_me.getName() << " RECEIVED " << fishedCards.size();
        m_me.pushHand(fishedCards);
    }
}