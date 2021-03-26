#include "catch.hpp"

#include "../libgofish/Player.h"
#include "Deck.h"
#include "mocks/MockMvcController.h"
#include "Player.test.h"

using namespace std;

PlayerTest::PlayerTest()
{

}

PlayerTest::~PlayerTest() {};

void PlayerTest::SetUp() {};

void PlayerTest::TearDown() {};

TEST_CASE_METHOD(PlayerTest, "PushCards") {
    
    Player p1("dummy1", m_deck, &m_mockController);
    
    p1.pushHandCard(m_deck.dealCard());
    p1.pushHandCard(m_deck.dealCard());
    p1.pushHandCard(m_deck.dealCard());
    p1.pushHandCard(m_deck.dealCard());
    p1.pushHandCard(m_deck.dealCard());
    CHECK(5 == p1.getHandSize());
}

TEST_CASE_METHOD(PlayerTest, "PushHand") {
    Deck d;
    Player p1("dummy1", m_deck, &m_mockController);
    
    Card c1(2, Card::hearts);
    Card c2(9, Card::diamonds);
    Card c3(3, Card::spades);
    Card c4(10, Card::spades);
    Card c5(6, Card::spades);
    p1.pushHandCard(&c1);
    p1.pushHandCard(&c2);
    p1.pushHandCard(&c3);
    p1.pushHandCard(&c4);
    p1.pushHandCard(&c5);

    p1.sortHand();

    CHECK(2 == p1.getHand()->at(0)->getValue());
    CHECK(3 == p1.getHand()->at(1)->getValue());
    CHECK(6 == p1.getHand()->at(2)->getValue());
    CHECK(9 == p1.getHand()->at(3)->getValue());
    CHECK(10 == p1.getHand()->at(4)->getValue());
}

TEST_CASE_METHOD(PlayerTest, "DoYouHaveTwos") {
    Player testObject("testObject", m_deck, &m_mockController);

    Card c1(2, Card::hearts);
    Card c2(9, Card::diamonds);
    Card c3(3, Card::spades);
    Card c4(10, Card::spades);
    Card c5(6, Card::spades);
    testObject.pushHandCard(&c1);
    testObject.pushHandCard(&c2);
    testObject.pushHandCard(&c3);
    testObject.pushHandCard(&c4);
    testObject.pushHandCard(&c5);
    CHECK(5 == testObject.getHandSize());
    vector<Card*> actual;

    actual = testObject.doYouHave(2);

    CHECK(1 == actual.size());
    CHECK(2 == actual.at(0)->getValue());
    CHECK(4 == testObject.getHandSize());
}

TEST_CASE_METHOD(PlayerTest, "MakeMove_AsksOthersForCardsOnce") {
    Player testObject("testObject", m_deck, &m_mockController);
    Card c1(2, Card::hearts);
    Card c2(9, Card::diamonds);
    Card c3(3, Card::spades);
    Card c4(10, Card::spades);
    Card c5(6, Card::spades);
    testObject.pushHandCard(&c1);
    testObject.pushHandCard(&c2);
    testObject.pushHandCard(&c3);
    testObject.pushHandCard(&c4);
    testObject.pushHandCard(&c5);
    Player p1("dummy2", m_deck, &m_mockController);
    Card c6(2, Card::diamonds);
    Card c7(4, Card::spades);
    p1.pushHandCard(&c6);
    p1.pushHandCard(&c7);
    //vector<Player*> m_otherplayers{&p1};
    vector<Card*> cards = testObject.askPlayerForCards(&p1, 2);

    CHECK(5 == testObject.getHandSize());
    CHECK(1 == p1.getHandSize());
}

TEST_CASE_METHOD(PlayerTest, "MakeBooks") {
    Player testObject("testObject", m_deck, &m_mockController);
    testObject.pushEasyFish(4);
    Card c1(2, Card::hearts);
    Card c2(4, Card::diamonds);
    Card c3(4, Card::hearts);
    Card c4(4, Card::spades);
    Card c5(4, Card::clubs);
    testObject.pushHandCard(&c1);
    testObject.pushHandCard(&c2);
    testObject.pushHandCard(&c3);
    testObject.pushHandCard(&c4);
    testObject.pushHandCard(&c5);
    testObject.makeBooks();
    CHECK(1 == testObject.getBooks().size());
    CHECK(1 == testObject.getHandSize());
    CHECK_FALSE(testObject.hasEasyFish(4));
}

TEST_CASE_METHOD(PlayerTest, "easyFish") {
    Player testObject("testObject", m_deck, &m_mockController);
    testObject.pushEasyFish(6);
    testObject.pushEasyFish(9);
    CHECK(2 == testObject.getEasyFish().size());
    CHECK(testObject.hasEasyFish(6));
    CHECK(testObject.hasEasyFish(9));
    testObject.popEasyFish(6);
    CHECK(1 == testObject.getEasyFish().size());
    CHECK_FALSE(testObject.hasEasyFish(6));
    CHECK(testObject.hasEasyFish(9));
    testObject.popEasyFish(9);
    CHECK(0 == testObject.getEasyFish().size());
    CHECK_FALSE(testObject.hasEasyFish(6));
    CHECK_FALSE(testObject.hasEasyFish(9));
}
