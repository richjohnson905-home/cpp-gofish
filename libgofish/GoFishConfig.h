//
// Created by Richard Johnson on 3/29/21.
//

#ifndef GOFISH_GOFISHCONFIG_H
#define GOFISH_GOFISHCONFIG_H


#include <Deck.h>
#include "GoFishUtil.h"
#include "MvcGameView.h"
#include "MvcController.h"
#include "Player.h"
#include "StrategyHelper.h"
#include "TurnHelper.h"
#include "Strategy.h"
#include "GoFishGame.h"

class GoFishConfig {
private:
    GoFishUtil m_util;
    MvcModel m_model;
    MvcGameView m_view;
    MvcController m_controller;
    Deck m_deck;
    std::vector<IPlayer*> m_players;
    Player m_ai1;
    Player m_ai2;
    Player m_ai3;
    StrategyHelper m_helper;
    TurnHelper m_turnHelper1;
    TurnHelper m_turnHelper2;
    TurnHelper m_turnHelper3;
    Strategy m_goFishStrategyAi1;
    Strategy m_goFishStrategyAi2;
    Strategy m_goFishStrategyAi3;
    GoFishGame m_game;
public:
    GoFishConfig();

    GoFishGame getGame() const;
};


#endif //GOFISH_GOFISHCONFIG_H
