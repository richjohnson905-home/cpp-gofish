#include "catch.hpp"

#include "GoFishUtil.h"
#include "Player.h"
#include "Deck.h"

#include <vector>

using namespace std;

TEST_CASE("GoFishUtilTest", "RemovePlayer") {
    Deck deck;
    Player p1("one", deck);
    p1.pushHandCard(deck.dealCard());
    Player p2("two", deck);
    p2.pushHandCard(deck.dealCard());
    Player p3("three", deck);
    p3.pushHandCard(deck.dealCard());
    vector<Player*> players = {&p1, &p2, &p3};

    GoFishUtil testObject;
    vector<Player*> withoutP2 = testObject.removePlayer(players, &p2);
    CHECK(2 == withoutP2.size());
}