#include "StrategyHelper.h"
#include "Log.h"
#include "Player.h"
#include "Deck.h"

#include <vector>
#include <iostream>

using std::pair;
using std::make_pair;
using std::nullopt;
using std::optional;
using std::cout;
using std::endl;
using std::cin;
using std::set;
using std::vector;

optional<pair<IPlayer*, int>> StrategyHelper::goEasyFishing(IPlayer* me, std::vector<IPlayer*>& players) {
    vector<Card*>::const_iterator cit;
    for(auto & player : players) {
        for (cit = me->getHand()->begin(); cit != me->getHand()->end(); ++cit) {
            if (player->hasEasyFish((*cit)->getValue())) {
                L_(ldebug1) << "Easy Fish found: " << player->getName() << " with " << (*cit)->getValue();
                return make_pair(player, (*cit)->getValue());
            }
        }
    }
    return nullopt;
}

std::optional<IPlayer*> StrategyHelper::getFishPlayer(std::vector<IPlayer*>& players) const {
    vector<IPlayer*> playersWithCards;
    playersWithCards.reserve(players.size());
    for (auto & player : players) {
        if (!player->getHand()->empty()) {
            playersWithCards.push_back(player);
        }
    }
    if (playersWithCards.empty()) {
        L_(linfo) << "NO FISH PLAYERS REMAIN";
        return nullopt;
    } else if (playersWithCards.size() == 1) {
        L_(linfo) << "ONE OTHER FISH PLAYER REMAINS: " << playersWithCards.front()->getName();
        return playersWithCards.front();
    } else {
        L_(ldebug1) << "MULTIPLE PLAYERS REMAIN";
        int randomPlayer = m_util.getRandomNumber(0, players.size());
        return optional<IPlayer*>(players.at(randomPlayer));
    }

}

// This strategy can be improved.  Best card to use as bait?  Not random
int StrategyHelper::getBaitCard(IPlayer* me) const {
    set<Card*, CardCompare> fishableCards = getPossibleBaitCards(me);
    if (fishableCards.size() > 1) {
        int randomFishCard = m_util.getRandomNumber(0, fishableCards.size());
        auto first = fishableCards.begin(); // get iterator to 1st element
        advance(first, randomFishCard);
        return (*first)->getValue();
    } else {
        return (*fishableCards.cbegin())->getValue();
    }

}

set<Card*, CardCompare> StrategyHelper::getPossibleBaitCards(IPlayer* me) const {
    set<Card*, CardCompare> setOfCards;
    vector<Card*>::const_iterator it;
    for (it = me->getHand()->begin(); it != me->getHand()->end(); ++it) { 
        setOfCards.insert(*it); 
    } 
    return setOfCards;
}

int StrategyHelper::getHumansPlayerChoice(vector<IPlayer*>& players) const {
    int i = 1;
    cout << "Select player to fish:" << endl;
    for (auto & player : players) {
        cout << i++ << ". " << player->getName() << endl;
    }
    int choice = getChoice(players.size());
    return choice;
}

int StrategyHelper::getHumansBaitChoice(IPlayer* me) const {
    int i = 1;
    cout << "Select card to fish:" << endl;
    Card* c;
    for (auto & it : *me->getHand()) {
        cout << i++ << ". " << it->show() << endl;
    }
    int choice = getChoice(me->getHandSize());
    return choice;
}

int StrategyHelper::getChoice(int maxInput) {
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
    } while (!validInput);
    return choice;
}

