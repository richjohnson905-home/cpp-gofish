
#include "Strategy.test.h"
#include "Strategy.h"
#include "Log.h"
#include "catch.hpp"
#include "catch2/trompeloeil.hpp"

#include <vector>
#include <optional>

using namespace std;
using trompeloeil::_;

StrategyTest::StrategyTest()
{
    
}

StrategyTest::~StrategyTest() {};

void StrategyTest::SetUp() {
    m_otherPlayers.push_back(&m_otherPlayer);
};

void StrategyTest::TearDown() {};

using trompeloeil::_;

TEST_CASE_METHOD(StrategyTest, "TakeTurn-EasyFishing")
{
    MockStrategyHelper mockStrategyHelper;
    MockTurnHelper mockTurnHelper;
    Strategy testObject(mockTurnHelper, m_me, m_deck);
    ALLOW_CALL(m_me, getName()).RETURN("TestMe");
    REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers)).RETURN(false);
    REQUIRE_CALL(mockTurnHelper, hardFish(m_otherPlayers, _)).RETURN(false);

    testObject.takeTurn(m_otherPlayers);
}

TEST_CASE_METHOD(StrategyTest, "EasyFishing2")
{
    trompeloeil::sequence seq;
    MockStrategyHelper mockStrategyHelper;
    MockTurnHelper mockTurnHelper;
    Strategy testObject(mockTurnHelper, m_me, m_deck);
    ALLOW_CALL(m_me, getName()).RETURN("TestMe");
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
    MockTurnHelper mockTurnHelper;
    Strategy testObject(mockTurnHelper, m_me, m_deck);
    ALLOW_CALL(m_me, getName()).RETURN("TestMe");
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
    MockTurnHelper mockTurnHelper;
    Strategy testObject(mockTurnHelper, m_me, m_deck);
    ALLOW_CALL(m_me, getName()).RETURN("TestMe");
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
