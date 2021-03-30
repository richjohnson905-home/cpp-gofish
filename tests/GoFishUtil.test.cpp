#include <catch2/catch_test_macros.hpp>

#include "GoFishUtil.h"
#include "Player.h"
#include "Deck.h"
#include "mocks/MockMvcController.h"

#include <vector>

#include <iostream>

using namespace std;

TEST_CASE("GoFishUtilTest-RemovePlayer") {
    MockMvcController m_mockController;
    Deck deck;
    Player p1("one", deck);
    p1.pushHandCard(deck.dealCard());
    Player p2("two", deck);
    p2.pushHandCard(deck.dealCard());
    Player p3("three", deck);
    p3.pushHandCard(deck.dealCard());
    vector<IPlayer*> players = {&p1, &p2, &p3};

    GoFishUtil testObject;
    vector<IPlayer*> withoutP2 = testObject.removePlayer(players, &p2);
    CHECK(2 == withoutP2.size());
}

TEST_CASE("GoFishUtilTest-Random") {
    GoFishUtil testObject;
    cout << "Order: " << testObject.getRandomNumber(0, 3) << endl;
    cout << "Order: " << testObject.getRandomNumber(0, 3) << endl;
    cout << "Order: " << testObject.getRandomNumber(0, 3) << endl;
    cout << "Order: " << testObject.getRandomNumber(0, 3) << endl;
    cout << "Order: " << testObject.getRandomNumber(0, 3) << endl;
    cout << "Order: " << testObject.getRandomNumber(0, 3) << endl;
    cout << "Order: " << testObject.getRandomNumber(0, 3) << endl;
    cout << "Order: " << testObject.getRandomNumber(0, 3) << endl;

    printf ("First number: %d\n", rand()%3);
    srand (time(NULL));
    printf ("Random number: %d\n", rand()%3);
    srand (1);
    printf ("Again the first number: %d\n", rand()%3);

}