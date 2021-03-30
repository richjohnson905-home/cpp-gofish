//
// Created by Richard Johnson on 3/21/21.
//

#ifndef GOFISH_MOCKTURNHELPER_H
#define GOFISH_MOCKTURNHELPER_H

#include "TurnHelper.h"

class MockTurnHelper : public ITurnHelper
{
public:
    MAKE_MOCK1(easyFish, bool(std::vector<IPlayer*>&), override);
    MAKE_MOCK2(hardFish, bool(std::vector<IPlayer*>&, Deck&), override);
};

#endif //GOFISH_MOCKTURNHELPER_H
