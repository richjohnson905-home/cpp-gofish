#ifndef GOFISH_GAME_H
#define GOFISH_GAME_H

#include "Player.h"
#include "Deck.h"
#include "GoFishUtil.h"
#include "MvcController.h"

#include <vector>

class GoFishGame {
private:
    GoFishUtil m_util;
    std::vector<IPlayer*>& m_players;
    Deck& m_deck;
    int m_cardCount;
    MvcController& m_mvcController;

    IPlayer* winner();
    bool allDone();
    void doPlayRound();

public:
    GoFishGame(std::vector<IPlayer*>& playerVec, int cardCount, Deck& deck, MvcController& controller);
    void deal();
    void sortHands();
    void playRound(int round);
    void showHands(MvcController& controller);
    bool checkWinner(int round);


};

#endif