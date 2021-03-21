
#include "Strategy.test.h"
#include "Strategy.h"
#include "Log.h"
#include "catch.hpp"
#include "catch2/trompeloeil.hpp"

#include <vector>
#include <optional>

using namespace std;
using trompeloeil::_;

StrategyTest::StrategyTest():
    m_me("TEST_ME", m_deck),
    m_otherPlayer("TEST_OTHER_PLAYER", m_deck)
{
    
}

StrategyTest::~StrategyTest() {};

void StrategyTest::SetUp() {
    m_otherPlayers.push_back(&m_otherPlayer);
    //ON_CALL(m_me, getHandSize()).WillByDefault(Return(5));
};

void StrategyTest::TearDown() {};

using trompeloeil::_;

TEST_CASE_METHOD(StrategyTest, "EasyFishing")
{
    MockStrategyHelper mockStrategyHelper;
    MockTurnHelper mockTurnHelper(mockStrategyHelper, m_me);
    Strategy testObject(mockTurnHelper, m_me, m_deck);
    REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers)).RETURN(false);
    REQUIRE_CALL(mockTurnHelper, hardFish(m_otherPlayers, _)).RETURN(false);

    testObject.takeTurn(m_otherPlayers);
}

TEST_CASE_METHOD(StrategyTest, "EasyFishing2")
{
    trompeloeil::sequence seq;
    MockStrategyHelper mockStrategyHelper;
    MockTurnHelper mockTurnHelper(mockStrategyHelper, m_me);
    Strategy testObject(mockTurnHelper, m_me, m_deck);
    REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers))
        .RETURN(true)
        .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers))
            .RETURN(false)
            .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, hardFish(m_otherPlayers, _))
        .RETURN(false)
        .IN_SEQUENCE(seq);

    testObject.takeTurn(m_otherPlayers);
}

TEST_CASE_METHOD(StrategyTest, "hardFishing1")
{
    trompeloeil::sequence seq;
    MockStrategyHelper mockStrategyHelper;
    MockTurnHelper mockTurnHelper(mockStrategyHelper, m_me);
    Strategy testObject(mockTurnHelper, m_me, m_deck);
    REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers))
            .RETURN(false)
            .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, hardFish(m_otherPlayers, _))
            .RETURN(true)
            .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers))
            .RETURN(false)
            .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, hardFish(m_otherPlayers, _))
            .RETURN(false)
            .IN_SEQUENCE(seq);
    testObject.takeTurn(m_otherPlayers);
}
TEST_CASE_METHOD(StrategyTest, "hardFishing2")
{
    trompeloeil::sequence seq;
    MockStrategyHelper mockStrategyHelper;
    MockTurnHelper mockTurnHelper(mockStrategyHelper, m_me);
    Strategy testObject(mockTurnHelper, m_me, m_deck);
    REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers))
            .RETURN(false)
            .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, hardFish(m_otherPlayers, _))
            .RETURN(true)
            .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers))
            .RETURN(false)
            .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, hardFish(m_otherPlayers, _))
            .RETURN(true)
            .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers))
            .RETURN(false)
            .IN_SEQUENCE(seq);
    REQUIRE_CALL(mockTurnHelper, hardFish(m_otherPlayers, _))
            .RETURN(false)
            .IN_SEQUENCE(seq);
    testObject.takeTurn(m_otherPlayers);
}

/*
TEST_CASE_METHOD(StrategyTest, "doTakeTurn_WithEmptyHand") {
    vector<Player*> otherPlayers = {&m_otherPlayer};
    MockPlayer mockMe("TestUser", m_deck);
    Strategy testObject(m_turnHelper, mockMe, m_deck);
    REQUIRE_CALL(mockMe, getHandSize()).RETURN(0);
    FORBID_CALL(m_turnHelper, goEasyFishing(_, _));
    testObject.takeTurn(otherPlayers);
}

TEST_CASE_METHOD(StrategyTest, "doTakeTurn_EasyFish") {
    vector<Card*> twoThrees = {
        new Card(3, Card::hearts),
        new Card(3, Card::diamonds)
    };
    vector<Card*> emptyCards = {};
    int bait3 = 3;
    int bait4 = 4;
    optional<pair<Player*, int>> easyPlay3 = make_pair(&m_otherPlayer, bait3);

    ALLOW_CALL(m_me, getHandSize())
        .RETURN(5);
    trompeloeil::sequence seq;
    REQUIRE_CALL(m_helper, goEasyFishing(&m_me, m_otherPlayers))
        .IN_SEQUENCE(seq)
        .RETURN(easyPlay3);
    REQUIRE_CALL(m_helper, goEasyFishing(&m_me, m_otherPlayers))
            .IN_SEQUENCE(seq)
            .RETURN(nullptr);
    REQUIRE_CALL(m_helper, getFishPlayer(_))
        .RETURN(m_otherPlayer);
    REQUIRE_CALL(m_helper, getBaitCard(&m_me))
        .RETURN(bait4);
    REQUIRE_CALL(m_me, pushEasyFish(bait4));

//    REQUIRE_CALL(m_helper, goFishing(&m_me, _, m_otherPlayers, _))
//        .RETURN(emptyCards);

    m_testObject.takeTurn(m_otherPlayers);
}
 */
/*
TEST_F(StrategyTest, doTakeTurn_HardFish) {
    vector<Card*> twoThrees = {
        new Card(3, Card::hearts),
        new Card(3, Card::diamonds)
    };
    vector<Card*> emptyCards = {};
    vector<Card*> deckCard = {new Card(6, Card::hearts)};
    int bait3 = 3;
    int bait4 = 4;
    
    EXPECT_CALL(m_me, getHandSize())
        .WillRepeatedly(Return(5));
    EXPECT_CALL(m_helper, goEasyFishing(_, _, _))
        .WillRepeatedly(Return(emptyCards));
    EXPECT_CALL(m_helper, getBaitCard(_))
        .WillOnce(Return(bait3))
        .WillOnce(Return(bait4));
    EXPECT_CALL(m_me, pushEasyFish(bait3)).Times(1);    
    EXPECT_CALL(m_me, pushEasyFish(bait4)).Times(1);    
    
    EXPECT_CALL(m_helper, goFishing(_, _, _, _))
        .WillOnce(Return(twoThrees))
        .WillOnce(Return(deckCard));

    m_testObject.takeTurn(m_otherplayers);
}
*/