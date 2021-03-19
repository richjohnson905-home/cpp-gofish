
#include "GoFishUtil.h"
#include "Player.h"
#include "Deck.h"
#include "doctest.h"

#include <vector>

using namespace std;

TEST_CASE("RemovePlayer") {
    Deck deck;
    Player p1("one", deck);
    p1.pushHand(deck.dealCard());
    Player p2("two", deck);
    p2.pushHand(deck.dealCard());
    Player p3("three", deck);
    p3.pushHand(deck.dealCard());
    vector<Player*> players = {&p1, &p2, &p3};

    GoFishUtil testObject;
    vector<Player*> withoutP2 = testObject.removePlayer(players, &p2);
    CHECK_EQ(2, withoutP2.size());
}