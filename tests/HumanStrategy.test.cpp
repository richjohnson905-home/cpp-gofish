#include <catch2/catch_test_macros.hpp>

#include "HumanStrategy.h"
#include "StrategyHelper.h"
#include "mocks/MockPlayer.h"
#include "mocks/MockStrategyHelper.h"
#include "Deck.h"

using namespace std;

TEST_CASE("HumanStrategyTest", "TakeTurn") {
//    GTEST_SKIP();
//    Deck deck;
//    NiceMock<MockPlayer> me("TestMe", deck);
//    NiceMock<MockPlayer> other1("Other1", deck);
//    NiceMock<MockPlayer> other2("Other2", deck);
//    NiceMock<MockStrategyHelper> helper;
//    vector<Player*> otherPlayers = {&other1, &other2};
//
//    HumanStrategy testObject(&me, deck, helper);
//
//    testObject.takeTurn(otherPlayers);
//
//    EXPECT_EQ(2, 2);
}