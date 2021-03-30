#include "GoFishGame.h"
#include "Log.h"

#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;

GoFishGame::GoFishGame(vector<IPlayer*>& playerVec, int cardCount, Deck& deck, MvcController& controller):
    m_players(playerVec), 
    m_cardCount(cardCount),
    m_deck(deck),
    m_mvcController(controller){

}

void GoFishGame::playRound(int round) {
    L_(linfo) << "ROUND " << round;
    m_mvcController.setRound(round);
    sortHands();
    showHands(m_mvcController);
    m_mvcController.updateView(cout);
    doPlayRound();
}

void GoFishGame::doPlayRound() {
    for (auto & m_player : m_players) {
        vector<IPlayer*> playersMinusMe = m_util.removePlayer(m_players, m_player);
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

void GoFishGame::showHands(MvcController& controller) {
    controller.setHand1(m_players.at(0)->getHand());
    controller.setHand2(m_players.at(1)->getHand());
    controller.setHand3(m_players.at(2)->getHand());
    controller.setBook1(m_players.at(0)->getBooks());
    controller.setBook2(m_players.at(1)->getBooks());
    controller.setBook3(m_players.at(2)->getBooks());
}

void GoFishGame::sortHands() {
    for (auto & m_player : m_players) {
        m_player->sortHand();
    }
}

bool GoFishGame::checkWinner(int round) {
    if (allDone()) {
        IPlayer* w = winner();
        sortHands();
        showHands(m_mvcController);
        m_mvcController.setWinner(w->getName());
        m_mvcController.updateView(cout);
        return true;
    }
    return false;
}

IPlayer* GoFishGame::winner() {
    auto max_val = max_element(
        begin(m_players), 
        end(m_players),
        [](const IPlayer* a, const IPlayer* b)
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
