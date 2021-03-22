#include "catch.hpp"

#include "StrategyHelper.h"
#include "MockPlayer.h"

using namespace std;
using trompeloeil::_;

TEST_CASE("GoEasyFishing-No-Returns-NullOpt") {
    Deck deck;
    StrategyHelper testObject;
    MockPlayer me("TestMe", deck);
    MockPlayer other1("Other1", deck);
    MockPlayer other2("Other2", deck);
    vector<Player*> otherPlayers = {&other1, &other2};
    vector<Card*> myCards = {
            new Card(3, Card::hearts),
            new Card(4, Card::diamonds)
    };
    ALLOW_CALL(me, getHand()).RETURN(&myCards);
    REQUIRE_CALL(other1, hasEasyFish(3)).RETURN(false);
    ALLOW_CALL(other1, hasEasyFish(4)).RETURN(false);
    ALLOW_CALL(other2, hasEasyFish(_)).RETURN(false);

    optional<pair<Player*, int>> actual = testObject.goEasyFishing(&me, otherPlayers);

    CHECK_FALSE(actual.has_value());
}

TEST_CASE("GoEasyFishing-Yes-ReturnsPlayerAndBait") {
    Deck deck;
    StrategyHelper testObject;
    MockPlayer me("TestMe", deck);
    MockPlayer other1("Other1", deck);
    MockPlayer other2("Other2", deck);
    vector<Player*> otherPlayers = {&other1, &other2};
    vector<Card*> myCards = {
        new Card(3, Card::hearts),
        new Card(4, Card::diamonds)
    };
    ALLOW_CALL(me, getHand()).RETURN(&myCards);
    REQUIRE_CALL(other1, hasEasyFish(3)).RETURN(true);
    ALLOW_CALL(other2, hasEasyFish(_)).RETURN(false);

    optional<pair<Player*, int>> actual = testObject.goEasyFishing(&me, otherPlayers);

    CHECK(actual.has_value());
    Player* actualPlayer = actual.value().first;
    CHECK(&other1 == actualPlayer);
    CHECK(3 == actual.value().second);
}

TEST_CASE("StrategyHelperTest-getBaitCard") {
    Deck deck;
    StrategyHelper testObject;
    MockPlayer me("TestObj", deck);
    vector<Card*> myCards = {
        new Card(3, Card::hearts),
        new Card(3, Card::diamonds),
        new Card(4, Card::diamonds),
        new Card(4, Card::clubs)
    };

    ALLOW_CALL(me, getHand()).RETURN(&myCards);

    int bait = testObject.getBaitCard(&me);

    CHECK(bait >= 3);
    CHECK(bait <= 4);
}
