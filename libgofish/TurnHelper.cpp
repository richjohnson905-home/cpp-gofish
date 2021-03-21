//
// Created by Richard Johnson on 3/21/21.
//

#include "TurnHelper.h"
#include "Log.h"

using namespace std;

TurnHelper::TurnHelper(StrategyHelper &helper, Player& me)
:m_helper(helper),
m_me(me){

}

bool TurnHelper::easyFish(std::vector<Player *> &players)
{
    optional<pair<Player*, int>> optPlayerAndBait = m_helper.goEasyFishing(&m_me, players);
    if (optPlayerAndBait.has_value())
    {
        L_(ldebug1) << "Fishing the easy way";
        optional<vector<Card*>> optCards = askPlayer(optPlayerAndBait);
        if (optCards.has_value())
        {
            L_(ldebug1) << " LIKE FISHING IN A BARRELL " << optCards.value().size();
            acceptCards(optCards.value());
            return true;
        }
        else
        {
            L_(lerror) << "DEV ERROR: This should never happen.";
        }
    }
    return false;
}

bool TurnHelper::hardFish(std::vector<Player *> &players, Deck& deck)
{
    if( auto p = m_helper.getFishPlayer(players))
    {
        L_(ldebug1) << "Fishing the hard way";
        int bait = m_helper.getBaitCard(&m_me);
        m_me.pushEasyFish(bait);
        optional<pair<Player*, int>> optPlayerAndBait = make_pair(p.value(), bait);
        vector<Card*> cards = askPlayer(optPlayerAndBait);
        if (cards.size() > 0)
        {
            L_(ldebug1) << " Hard-won cards size: " << cards.size();
            acceptCards(cards);
            return true;
        } else {
            return deckFish(deck, bait);
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
        return c->getValue() == bait;
    } else {
        L_(ldebug1) << m_me.getName() << " Deck empty!";
        return false;
    }
}

vector<Card*> TurnHelper::askPlayer(std::optional<std::pair<Player*, int>>& optPair)
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
    for(vector<Card*>::const_iterator it = fishedCards.begin(); it != fishedCards.end(); ++it) {
        ss << (*it)->getValue() << " ";
    }
    L_(ldebug1) << " caught cards " << ss.str();

    if (fishedCards.size() > 0) {
        L_(ldebug1) << m_me.getName() << " RECEIVED " << fishedCards.size();
        m_me.pushHand(fishedCards);
    }
}