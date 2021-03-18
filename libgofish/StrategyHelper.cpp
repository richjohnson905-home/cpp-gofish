#include "StrategyHelper.h"
#include "Log.h"
#include "Player.h"
#include "Deck.h"

#include <vector>
#include <iostream>

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
    // bool done = false;
    // int choice;

    // for (std::string line;
    //     std::cout << "Enter a choice: " && std::getline(std::cin, line); )
    // {
    //     std::istringstream iss(line);
    //     if (iss >> choice >> std::ws && iss.get() == EOF) { done = true; break; }
    //     std::cerr << "Failed to parse input '" << line << "', please try again.\n";
    // }

    // if (!done) { std::cerr << "Premature end of input.\n"; }
    // else       { std::cout << "Choice: " << choice << "\n";   }
}

