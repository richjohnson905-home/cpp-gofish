#include "GoFishGame.h"
#include "Log.h"

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

GoFishGame::GoFishGame(vector<Player*>& playerVec, int cardCount, Deck& deck):
    m_players(playerVec), 
    m_cardCount(cardCount),
    m_deck(deck) {

}

void GoFishGame::playRound(int round) {
    L_(linfo) << "ROUND " << round;
    cout << "==================== ROUND " << round << "====================" << endl;
    sortHands();
    showHands();
    for (vector<Player*>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
        vector<Player*> playersMinusMe = m_util.removePlayer(m_players, *it);
        (*it)->takeTurn(playersMinusMe);
    }
    sortHands();
}

void GoFishGame::deal() {
    for (int i = 0; i < m_cardCount; ++i) {
        for (vector<Player*>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
            (*it)->pushHand(m_deck.dealCard());
        }
    }
}

void GoFishGame::showHands() {
    for (vector<Player*>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
        (*it)->showHand();
        
        vector<int> books = (*it)->getBooks();
        cout << "\t\tBOOKS: ";
        if (books.size()) {
            for (auto i = books.begin(); i != books.end(); ++i) {
                std::cout << *i << ' ';
            }
            cout << endl;
        } else {
            cout << "None" << endl;
        }
    }
}

void GoFishGame::sortHands() {
    for (vector<Player*>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
        (*it)->sortHand();
    }
}

bool GoFishGame::checkWinner(int round) {
    if (allDone()) {
        Player* w = winner();
        cout << "\n\nWE HAVE A ROUND " << round << " WINNER: " << w->getName() << endl;
        return true;
    }
    return false;
}

Player* GoFishGame::winner() {
    auto max_val = max_element(
        begin(m_players), 
        end(m_players),
        [](const Player* a, const Player* b)
        {
            return a->getBooks().size() < b->getBooks().size();
        });
    return *max_val;
}

bool GoFishGame::allDone() {
    for (vector<Player*>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
        if ((*it)->getHandSize() != 0) {
            return false;
        }
    }
    return true;
}
