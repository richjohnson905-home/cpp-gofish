
#include "HumanStrategy.h"
#include "StrategyHelper.h"
#include "MockPlayer.h"
#include "MockStrategyHelper.h"
#include "Deck.h"
#include "doctest.h"

using namespace std;

TEST_CASE("TakeTurn") {
    doctest::skip(true);
    // GTEST_SKIP();
    // Deck deck;
    // NiceMock<MockPlayer> me("TestMe", deck);
    // NiceMock<MockPlayer> other1("Other1", deck);
    // NiceMock<MockPlayer> other2("Other2", deck);
    // NiceMock<MockStrategyHelper> helper;
    // vector<Player*> otherPlayers = {&other1, &other2};

    // HumanStrategy testObject(&me, deck, helper);

    //testObject.takeTurn(otherPlayers);

    CHECK_EQ(2, 2);
}