#include "HumanStrategy.h"
#include "Log.h"
#include "Player.h"
#include "StrategyHelper.h"

#include <iostream>

using namespace std;

HumanStrategy::HumanStrategy(IPlayer* myPlayer, Deck& deck, IStrategyHelper& helper)
:m_me(myPlayer), m_helper(helper), m_deck(deck) {

}

void HumanStrategy::takeTurn(vector<IPlayer*>& players) {
    L_(ldebug1) << m_me->getName() << " making first move";
    while (doTakeTurn(players)) {
        L_(ldebug1) << m_me->getName() << " making another move";
    }
}
bool HumanStrategy::doTakeTurn(vector<IPlayer*>& players) {
    int choice = m_helper.getHumansPlayerChoice(players);
    L_(ldebug1) << "Human chose: " << players.at(choice - 1)->getName();
    int baitChoice = m_helper.getHumansBaitChoice(m_me);
    int bait = m_me->getHand()->at(baitChoice - 1)->getValue();
    L_(ldebug1) << "Human fishing with " << bait;
    vector<Card*> cards = goFishing(players.at(choice - 1), bait);
    return doTurnCompletion(cards, bait);
}

bool HumanStrategy::doTurnCompletion(vector<Card*> fishedCards, int bait) {
    std::stringstream ss;
    for(vector<Card*>::const_iterator it = fishedCards.begin(); it != fishedCards.end(); ++it) {
        ss << (*it)->getValue() << " ";
    }
    L_(ldebug1) << "Turn with bait " << bait << " caught cards " << ss.str(); 

    if (fishedCards.size() > 0) {
        L_(ldebug1) << m_me->getName() << " RECEIVED " << fishedCards.size();
        m_me->pushHand(fishedCards);
        
        if (fishedCards.at(0)->getValue() != bait) {
            L_(linfo) << m_me->getName() << " move over";
            return false;
        } else {
            L_(linfo) << "Boom - go again player";
            return true;
        }
    } else {
        return false;
    }    
}

vector<Card*> HumanStrategy::goFishing(IPlayer* other, int bait) {
    vector<Card*> cards = m_me->askPlayerForCards(other, bait);
    // ask player
    // int randomPlayer = m_util.getRandomNumber(0, players.size());
    // Player* otherPlayer = players.at(randomPlayer);
    if (cards.size() == 0) {
        if (m_deck.getDeckSize() > 0) {
            L_(ldebug1) << "\t" << other->getName() << " told " << m_me->getName() << " to GO FISH!";
            cards.push_back(m_deck.dealCard());
        } else {
            L_(ldebug1) << m_me->getName() << " Deck empty!";
        }
    }
    return cards; 
}
