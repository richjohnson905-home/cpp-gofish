#include "Strategy.h"
#include "Player.h"
#include "Log.h"
#include "StrategyHelper.h"

#include <iostream>

using namespace std;

Strategy::Strategy(StrategyHelper& helper, Player& myPlayer, Deck& deck)
:m_me(myPlayer), 
m_deck(deck), 
m_helper(helper) {

}

void Strategy::takeTurn(vector<Player*>& players) {
    L_(ldebug1) << m_me.getName() << " making first move";
    while (doTakeTurn(players)) {
        // nothing
        L_(ldebug1) << m_me.getName() << " making another move";
    }
}

bool Strategy::doTakeTurn(vector<Player*>& players) {
    if (m_me.getHandSize() > 0) {
        int bait;
        vector<Card*> cards = m_helper.goEasyFishing(&m_me, players, bait);
        if (cards.size() == 0) {
            L_(ldebug1) << "Fishing the hard way";
            bait = m_helper.getBaitCard(&m_me);
            m_me.pushEasyFish(bait);
            cards = m_helper.goFishing(&m_me, m_deck, players, bait);
        } else {
            L_(ldebug1) << "Fishing the easy way";
        }
        return doTurnCompletion(cards, bait);
    } else {
        L_(ldebug1) << m_me.getName() << " out of cards";
        return false;
    }
}

bool Strategy::doTurnCompletion(vector<Card*> fishedCards, int bait) {
    std::stringstream ss;
    for(vector<Card*>::const_iterator it = fishedCards.begin(); it != fishedCards.end(); ++it) {
        ss << (*it)->getValue() << " ";
    }
    L_(ldebug1) << "Turn with bait " << bait << " caught cards " << ss.str(); 

    if (fishedCards.size() > 0) {
        L_(ldebug1) << m_me.getName() << " RECEIVED " << fishedCards.size();
        m_me.pushHand(fishedCards);
        
        if (fishedCards.at(0)->getValue() != bait) {
            L_(linfo) << m_me.getName() << " move over";
            return false;
        } else {
            L_(linfo) << "Boom - go again player";
            return true;
        }
    } else {
        return false;
    }    
}


