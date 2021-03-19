
#include "Strategy.h"
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "doctest.h"

using namespace std;

TEST_CASE("PushCards") {
    Deck d;
    Player p1("dummy1", d);
    
    p1.pushHand(d.dealCard());
    p1.pushHand(d.dealCard());
    p1.pushHand(d.dealCard());
    p1.pushHand(d.dealCard());
    p1.pushHand(d.dealCard());
    CHECK_EQ(5, p1.getHandSize());
}

TEST_CASE("SortHand") {
    Deck d;
    Player p1("dummy1", d);
    
    Card c1(2, Card::hearts);
    Card c2(9, Card::diamonds);
    Card c3(3, Card::spades);
    Card c4(10, Card::spades);
    Card c5(6, Card::spades);
    p1.pushHand(&c1);
    p1.pushHand(&c2);
    p1.pushHand(&c3);
    p1.pushHand(&c4);
    p1.pushHand(&c5);

    p1.sortHand();
    CHECK_EQ(2, p1.getHand()->at(0)->getValue());
    CHECK_EQ(3, p1.getHand()->at(1)->getValue());
    CHECK_EQ(6, p1.getHand()->at(2)->getValue());
    CHECK_EQ(9, p1.getHand()->at(3)->getValue());
    CHECK_EQ(10, p1.getHand()->at(4)->getValue());
}

TEST_CASE("DoYouHaveTwos") {
    Deck d;
    Player testObject("dummy", d);

    Card c1(2, Card::hearts);
    Card c2(9, Card::diamonds);
    Card c3(3, Card::spades);
    Card c4(10, Card::spades);
    Card c5(6, Card::spades);
    testObject.pushHand(&c1);
    testObject.pushHand(&c2);
    testObject.pushHand(&c3);
    testObject.pushHand(&c4);
    testObject.pushHand(&c5);
    CHECK_EQ(5, testObject.getHandSize());
    vector<Card*> actual;

    testObject.doYouHave(2, actual);

    CHECK_EQ(1, actual.size());
    CHECK_EQ(2, actual.at(0)->getValue());
    CHECK_EQ(4, testObject.getHandSize());
}

TEST_CASE("MakeMove_AsksOthersForCardsOnce") {
    Deck d;
    Player testObject("testObject", d);
    Card c1(2, Card::hearts);
    Card c2(9, Card::diamonds);
    Card c3(3, Card::spades);
    Card c4(10, Card::spades);
    Card c5(6, Card::spades);
    testObject.pushHand(&c1);
    testObject.pushHand(&c2);
    testObject.pushHand(&c3);
    testObject.pushHand(&c4);
    testObject.pushHand(&c5);
    Player p1("dummy2", d);
    Card c6(2, Card::diamonds);
    Card c7(4, Card::spades);
    p1.pushHand(&c6);
    p1.pushHand(&c7);
    //vector<Player*> m_otherplayers{&p1};
    vector<Card*> cards;
    testObject.otherHasCards(&p1, cards, 2);

    CHECK_EQ(5, testObject.getHandSize());
    CHECK_EQ(1, p1.getHandSize());
}

TEST_CASE("MakeBooks") {
    Deck d;
    Player testObject("testObject", d);
    testObject.pushEasyFish(4);
    Card c1(2, Card::hearts);
    Card c2(4, Card::diamonds);
    Card c3(4, Card::hearts);
    Card c4(4, Card::spades);
    Card c5(4, Card::clubs);
    testObject.pushHand(&c1);
    testObject.pushHand(&c2);
    testObject.pushHand(&c3);
    testObject.pushHand(&c4);
    testObject.pushHand(&c5);
    testObject.makeBooks();
    CHECK_EQ(1, testObject.getBooks().size());
    CHECK_EQ(1, testObject.getHandSize());
    CHECK_FALSE(testObject.hasEasyFish(4));
}

TEST_CASE("easyFish") {
    Deck d;
    Player testObject("testObject", d);
    testObject.pushEasyFish(6);
    testObject.pushEasyFish(9);
    CHECK_EQ(2, testObject.getEasyFish().size());
    CHECK(testObject.hasEasyFish(6));
    CHECK(testObject.hasEasyFish(9));
    testObject.popEasyFish(6);
    CHECK_EQ(1, testObject.getEasyFish().size());
    CHECK_FALSE(testObject.hasEasyFish(6));
    CHECK(testObject.hasEasyFish(9));
    testObject.popEasyFish(9);
    CHECK_EQ(0, testObject.getEasyFish().size());
    CHECK_FALSE(testObject.hasEasyFish(6));
    CHECK_FALSE(testObject.hasEasyFish(9));
}