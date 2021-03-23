//
// Created by Richard Johnson on 3/21/21.
//

#ifndef GOFISH_MOCKTURNHELPER_H
#define GOFISH_MOCKTURNHELPER_H

#include "TurnHelper.h"

class MockTurnHelper : public TurnHelper
{
public:
    MockTurnHelper(StrategyHelper& helper, Player& me):TurnHelper(helper, me){}
    MAKE_MOCK1(easyFish, bool(std::vector<Player*>&), override);
    MAKE_MOCK2(hardFish, bool(std::vector<Player*>&, Deck&), override);
};

#endif //GOFISH_MOCKTURNHELPER_H
