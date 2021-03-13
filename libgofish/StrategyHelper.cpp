#include "StrategyHelper.h"
#include "Log.h"
#include "Player.h"
#include "Deck.h"

#include <vector>

using namespace std;

vector<Card*> StrategyHelper::goEasyFishing(Player* me, std::vector<Player*>& players, int& bait) {
    vector<Card*> cards; 
    for(vector<Player*>::iterator it = players.begin(); it != players.end(); ++it) {
        for (vector<Card*>::iterator cit = me->getHand()->begin(); cit != me->getHand()->end(); ++cit) {
            if ((*it)->hasEasyFish((*cit)->getValue())) {
                bait = (*cit)->getValue();
                me->otherHasCards(*it, cards, bait);
                L_(ldebug1) << " LIKE FISHING IN A BARRELL " << cards.size();
                return cards;
            }
        }
    }
    return cards;
}

vector<Card*> StrategyHelper::goFishing(Player* me, Deck& deck, vector<Player*>& players, int bait) {
    vector<Card*> cards; 
    // ask player
    int randomPlayer = m_util.getRandomNumber(0, players.size());
    Player* otherPlayer = players.at(randomPlayer);
    if (!me->otherHasCards(otherPlayer, cards, bait)) {
        if (deck.getDeckSize() > 0) {
            L_(ldebug1) << "\t" << otherPlayer->getName() << " told " << me->getName() << " to GO FISH!";
            cards.push_back(deck.dealCard());
        } else {
            L_(ldebug1) << me->getName() << " Deck empty!";
        }
    }
    return cards; 
}

int StrategyHelper::getBaitCard(Player* me) const {
    set<Card*, CardCompare> fishableCards = getPossibleBaitCards(me);
    int randomFishCard = m_util.getRandomNumber(0, fishableCards.size());
    auto first = fishableCards.begin(); // get iterator to 1st element
    advance(first, randomFishCard); 
    return (*first)->getValue();
}


set<Card*, CardCompare> StrategyHelper::getPossibleBaitCards(Player* me) const {
    set<Card*, CardCompare> setOfCards; 
    vector<Card*>::const_iterator it;
    for (it = me->getHand()->begin(); it != me->getHand()->end(); ++it) { 
        setOfCards.insert(*it); 
    } 
    return setOfCards;
}
