#include "catch.hpp"

#include "StrategyHelper.h"
#include "mocks/MockPlayer.h"
#include "mocks/MockMvcController.h"

using namespace std;
using trompeloeil::_;

TEST_CASE("GoEasyFishing-No-Returns-NullOpt") {
    MockMvcController m_mockController;
    Deck deck;
    StrategyHelper testObject;
    MockPlayer me;
    MockPlayer other1;
    MockPlayer other2;
    vector<IPlayer*> otherPlayers = {&other1, &other2};
    vector<Card*> myCards = {
            new Card(3, Card::hearts),
            new Card(4, Card::diamonds)
    };
    ALLOW_CALL(me, getHand()).RETURN(&myCards);
    REQUIRE_CALL(other1, hasEasyFish(3)).RETURN(false);
    ALLOW_CALL(other1, hasEasyFish(4)).RETURN(false);
    ALLOW_CALL(other2, hasEasyFish(_)).RETURN(false);

    optional<pair<IPlayer*, int>> actual = testObject.goEasyFishing(&me, otherPlayers);

    CHECK_FALSE(actual.has_value());
}

TEST_CASE("GoEasyFishing-Yes-ReturnsPlayerAndBait") {
    MockMvcController m_mockController;
    Deck deck;
    StrategyHelper testObject;
    MockPlayer me;
    MockPlayer other1;
    MockPlayer other2;
    vector<IPlayer*> otherPlayers = {&other1, &other2};
    vector<Card*> myCards = {
        new Card(3, Card::hearts),
        new Card(4, Card::diamonds)
    };
    ALLOW_CALL(me, getName()).RETURN("TestMe");
    ALLOW_CALL(other1, getName()).RETURN("TestOther1");
    ALLOW_CALL(other2, getName()).RETURN("TestOther2");
    ALLOW_CALL(me, getHand()).RETURN(&myCards);
    REQUIRE_CALL(other1, hasEasyFish(3)).RETURN(true);
    ALLOW_CALL(other2, hasEasyFish(_)).RETURN(false);

    optional<pair<IPlayer*, int>> actual = testObject.goEasyFishing(&me, otherPlayers);

    CHECK(actual.has_value());
    IPlayer* actualPlayer = actual.value().first;
    CHECK(&other1 == actualPlayer);
    CHECK(3 == actual.value().second);
}

TEST_CASE("StrategyHelperTest-getBaitCard") {
    MockMvcController m_mockController;
    Deck deck;
    StrategyHelper testObject;
    MockPlayer me;
    vector<Card*> myCards = {
        new Card(3, Card::hearts),
        new Card(3, Card::diamonds),
        new Card(4, Card::diamonds),
        new Card(4, Card::clubs)
    };

    ALLOW_CALL(me, getHand()).RETURN(&myCards);

    int bait = testObject.getBaitCard(&me);

    bool actual = bait >= 3 && bait <= 4;
    CHECK(actual);
}
