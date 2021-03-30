//
// Created by Richard Johnson on 3/21/21.
//

#include <catch2/catch_test_macros.hpp>

#include "mocks/MockStrategyHelper.h"
#include "mocks/MockPlayer.h"
#include "../libgofish/TurnHelper.h"
#include "TurnHelper.test.h"

#include <iostream>

using namespace std;
using trompeloeil::_;

void TurnHelperTest::setTestObject(IStrategyHelper& helper, IPlayer& me) {
    testObject.reset(new TurnHelper(helper, me));
}

TEST_CASE_METHOD(TurnHelperTest, "easyFish", "[easy][player][strategy]")
{
    SECTION("no players")
    {
        setTestObject(mockStrategyHelper, mockMe);
        vector<IPlayer *> otherPlayers = {&mockOther};
        optional<pair<Player *, int>> pb = {};
        optional<vector<Card *>> optCards = {};
        REQUIRE_CALL(mockStrategyHelper, goEasyFishing(&mockMe, otherPlayers)).TIMES(1).RETURN(pb);
        FORBID_CALL(mockMe, askPlayerForCards(_, _));

        testObject->easyFish(otherPlayers);
    }
    SECTION("with players")
    {
        setTestObject(mockStrategyHelper, mockMe);
        int bait = 3;
        vector<IPlayer*> otherPlayers = {&mockOther};
        optional<pair<IPlayer*, int>> pb = make_pair(&mockOther, bait);
        vector<Card*> twoThrees = {
                new Card(3, Card::hearts),
                new Card(3, Card::diamonds)
        };
        optional<vector<Card*>> optCards = twoThrees;
        ALLOW_CALL(mockMe, getName()).RETURN("TestMe");
        ALLOW_CALL(mockMe, makeBooks());
        REQUIRE_CALL(mockStrategyHelper, goEasyFishing(&mockMe, otherPlayers))
                .TIMES(1)
                .RETURN(pb);
        REQUIRE_CALL(mockMe, askPlayerForCards(&mockOther, bait))
                .TIMES(1)
                .RETURN(optCards.value());
        REQUIRE_CALL(mockMe, pushHand(twoThrees))
        .TIMES(1);

        testObject->easyFish(otherPlayers);
    }
}

TEST_CASE_METHOD(TurnHelperTest, "hardFish-NoPlayers")
{
    SECTION("no players")
    {
        setTestObject(mockStrategyHelper, mockMe);
        vector<IPlayer *> otherPlayers = {&mockOther};
        optional<Player *> p = {};
        optional<vector<Card *>> optCards = {};
        REQUIRE_CALL(mockStrategyHelper, getFishPlayer(otherPlayers)).TIMES(1).RETURN(p);
        FORBID_CALL(mockStrategyHelper, getBaitCard(_));

        testObject->hardFish(otherPlayers, deck);
    }
    SECTION("with players")
    {
        setTestObject(mockStrategyHelper, mockMe);
        int bait = 3;
        vector<IPlayer*> otherPlayers = {&mockOther};
        optional<IPlayer*> p = make_optional(&mockOther);
        vector<Card*> twoThrees = {
                new Card(3, Card::hearts),
                new Card(3, Card::diamonds)
        };
        optional<vector<Card*>> optCards = {twoThrees};
        ALLOW_CALL(mockMe, makeBooks());
        ALLOW_CALL(mockMe, getName()).RETURN("TestMe");
        ALLOW_CALL(mockOther, getName()).RETURN("TestOther");
        REQUIRE_CALL(mockStrategyHelper, getFishPlayer(otherPlayers)).TIMES(1).RETURN(p);
        REQUIRE_CALL(mockStrategyHelper, getBaitCard(&mockMe))
                .TIMES(1)
                .RETURN(bait);
        REQUIRE_CALL(mockMe, pushEasyFish(bait))
        .TIMES(1);
        REQUIRE_CALL(mockMe, askPlayerForCards(&mockOther, bait))
                .TIMES(1)
                .RETURN(optCards.value());
        REQUIRE_CALL(mockMe, pushHand(twoThrees))
        .TIMES(1);
        testObject->hardFish(otherPlayers, deck);
    }
}

TEST_CASE_METHOD(TurnHelperTest, "deckFish-Yes")
{
    setTestObject(mockStrategyHelper, mockMe);
    int bait = 3;
    vector<IPlayer*> otherPlayers = {&mockOther};
    optional<IPlayer*> p = make_optional(&mockOther);
    vector<Card*> emptyCards;
    ALLOW_CALL(mockMe, getName()).RETURN("TestMe");
    ALLOW_CALL(mockOther, getName()).RETURN("TestOther");
    REQUIRE_CALL(mockStrategyHelper, getFishPlayer(otherPlayers)).TIMES(1).RETURN(p);
    REQUIRE_CALL(mockStrategyHelper, getBaitCard(&mockMe))
            .TIMES(1)
            .RETURN(bait);
    REQUIRE_CALL(mockMe, askPlayerForCards(&mockOther, bait))
            .TIMES(1)
            .RETURN(emptyCards);
    REQUIRE_CALL(mockMe, pushEasyFish(bait)).TIMES(1);
    ALLOW_CALL(mockMe, makeBooks());
    REQUIRE_CALL(mockMe, pushHandCard(_)).TIMES(1);
    testObject->hardFish(otherPlayers, deck);
}