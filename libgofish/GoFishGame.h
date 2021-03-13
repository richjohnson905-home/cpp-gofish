#ifndef GOFISH_GAME_H
#define GOFISH_GAME_H

#include "Player.h"
#include "Deck.h"
#include "GoFishUtil.h"

#include <vector>

class GoFishGame {
public:
    GoFishGame(std::vector<Player*>& playerVec, int cardCount, Deck& deck);
    void deal();
    void sortHands();
    void playRound(int round);
    void showHands();
    bool checkWinner(int round);

private:
    GoFishUtil m_util;
    std::vector<Player*>& m_players;
    Deck& m_deck;
    
    int m_cardCount;

    Player* winner();
    bool allDone();
};

#endif