
#include "Strategy.test.h"
#include <catch2/catch_test_macros.hpp>

#include <optional>

using namespace std;
using trompeloeil::_;

void StrategyTest::setTestObject(ITurnHelper& turnHelper, IPlayer& myPlayer, Deck& deck) {
    testObject.reset(new Strategy(mockTurnHelper, m_me, m_deck));
}

TEST_CASE_METHOD(StrategyTest, "TakeTurn-EasyFishing", "[easy]")
{
    SECTION("zero easy, zero hard")
    {
        ALLOW_CALL(m_me, getName()).RETURN("TestMe");
        REQUIRE_CALL(mockTurnHelper, easyFish(m_otherPlayers)).RETURN(false);
        REQUIRE_CALL(mockTurnHelper, hardFish(m_otherPlayers, _)).RETURN(false);

        setTestObject(mockTurnHelper, m_me, m_deck);
        testObject->takeTurn(m_otherPlayers);
    }
    SECTION("one easy, zero hard")
    {
        trompeloeil::sequence seq;
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

        setTestObject(mockTurnHelper, m_me, m_deck);
        testObject->takeTurn(m_otherPlayers);
    }
}

TEST_CASE_METHOD(StrategyTest, "hardFishing1")
{
    SECTION("no easy, one hard")
    {
        trompeloeil::sequence seq;
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
        setTestObject(mockTurnHelper, m_me, m_deck);
        testObject->takeTurn(m_otherPlayers);
    }
    SECTION("no easy, two hard")
    {
        trompeloeil::sequence seq;
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
        setTestObject(mockTurnHelper, m_me, m_deck);
        testObject->takeTurn(m_otherPlayers);
    }
}

