#include "StrategyHelper.h"
#include "Log.h"
#include "Player.h"
#include "Deck.h"

#include <vector>
#include <iostream>

using namespace std;

optional<pair<Player*, int>> StrategyHelper::goEasyFishing(Player* me, std::vector<Player*>& players) {
    optional<pair<Player*, int>> optionalResult;
    vector<Card*> cards;
    for(vector<Player*>::iterator it = players.begin(); it != players.end(); ++it) {
        for (vector<Card*>::iterator cit = me->getHand()->begin(); cit != me->getHand()->end(); ++cit) {
            if ((*it)->hasEasyFish((*cit)->getValue())) {
                pair<Player*, int> result = make_pair((*it), (*cit)->getValue());
                optionalResult = result;
            }
        }
    }
    return optionalResult;
}

std::optional<Player*> StrategyHelper::getFishPlayer(std::vector<Player*>& players) const {
    int randomPlayer = m_util.getRandomNumber(0, players.size());
    return optional<Player*>(players.at(randomPlayer));
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

int StrategyHelper::getHumansPlayerChoice(vector<Player*>& players) const {
    int i = 1;
    cout << "Select player to fish:" << endl;
    for (vector<Player*>::iterator it = players.begin(); it != players.end(); ++it) {
        cout << i++ << ". " << (*it)->getName() << endl; 
    }
    int choice = getChoice(players.size());
    return choice;
}

int StrategyHelper::getHumansBaitChoice(Player* me) const {
    int i = 1;
    cout << "Select card to fish:" << endl;
    Card* c;
    for (vector<Card*>::const_iterator it = me->getHand()->begin(); it != me->getHand()->end(); ++it) {
        cout << i++ << ". " << (*it)->show() << endl;
    }
    int choice = getChoice(me->getHandSize());
    return choice;
}

int StrategyHelper::getChoice(int maxInput) const {
    bool validInput = false;
    int choice;
    do
    {
        cin >> choice;
        if (choice <= maxInput && choice > 0) {
            cout << "Good input" << endl;
            validInput = true;
        } else {
            cout << "Bad input, try again" << endl;;
        }
    } while (validInput == false);
    return choice;
}

