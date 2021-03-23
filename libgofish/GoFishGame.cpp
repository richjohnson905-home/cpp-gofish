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
    for (auto & m_player : m_players) {
        vector<Player*> playersMinusMe = m_util.removePlayer(m_players, m_player);
        if (m_player->getHandSize()) {
            m_player->takeTurn(playersMinusMe);
        }
    }
    sortHands();
}

void GoFishGame::deal() {
    for (int i = 0; i < m_cardCount; ++i) {
        for (auto & m_player : m_players) {
            m_player->pushHandCard(m_deck.dealCard());
        }
    }
}

void GoFishGame::showHands() {
    for (auto & m_player : m_players) {
        m_player->showHand();
        
        vector<int> books = m_player->getBooks();
        cout << "\t\tBOOKS: ";
        if (!books.empty()) {
            for (int & book : books) {
                std::cout << book << ' ';
            }
            cout << endl;
        } else {
            cout << "None" << endl;
        }
    }
}

void GoFishGame::sortHands() {
    for (auto & m_player : m_players) {
        m_player->sortHand();
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
    for (auto & m_player : m_players) {
        if (m_player->getHandSize() != 0) {
            return false;
        }
    }
    return true;
}
