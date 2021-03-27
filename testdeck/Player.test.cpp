#include "catch.hpp"

#include "../libgofish/Player.h"
#include "Deck.h"
#include "mocks/MockMvcController.h"
#include "Player.test.h"

using namespace std;
using trompeloeil::_;

PlayerTest::PlayerTest():
        m_testObject("TestObj", m_deck, &m_mockController)
{

}

PlayerTest::~PlayerTest() {};

void PlayerTest::SetUp() {};

void PlayerTest::TearDown() {};

TEST_CASE_METHOD(PlayerTest, "PushCards") {
    m_testObject.pushHandCard(m_deck.dealCard());
    m_testObject.pushHandCard(m_deck.dealCard());
    m_testObject.pushHandCard(m_deck.dealCard());
    m_testObject.pushHandCard(m_deck.dealCard());
    m_testObject.pushHandCard(m_deck.dealCard());
    CHECK(5 == m_testObject.getHandSize());
}

TEST_CASE_METHOD(PlayerTest, "PushHand") {
    Card c1(2, Card::hearts);
    Card c2(9, Card::diamonds);
    Card c3(3, Card::spades);
    Card c4(10, Card::spades);
    Card c5(6, Card::spades);
    m_testObject.pushHandCard(&c1);
    m_testObject.pushHandCard(&c2);
    m_testObject.pushHandCard(&c3);
    m_testObject.pushHandCard(&c4);
    m_testObject.pushHandCard(&c5);

    m_testObject.sortHand();

    CHECK(2 == m_testObject.getHand()->at(0)->getValue());
    CHECK(3 == m_testObject.getHand()->at(1)->getValue());
    CHECK(6 == m_testObject.getHand()->at(2)->getValue());
    CHECK(9 == m_testObject.getHand()->at(3)->getValue());
    CHECK(10 == m_testObject.getHand()->at(4)->getValue());
}

TEST_CASE_METHOD(PlayerTest, "DoYouHaveTwos") {
    ALLOW_CALL(m_mockController, updatePlayAction(_));
    ALLOW_CALL(m_mockController, setPlayAction(_));
    Card c1(2, Card::hearts);
    Card c2(9, Card::diamonds);
    Card c3(3, Card::spades);
    Card c4(10, Card::spades);
    Card c5(6, Card::spades);
    m_testObject.pushHandCard(&c1);
    m_testObject.pushHandCard(&c2);
    m_testObject.pushHandCard(&c3);
    m_testObject.pushHandCard(&c4);
    m_testObject.pushHandCard(&c5);
    CHECK(5 == m_testObject.getHandSize());
    vector<Card*> actual;

    actual = m_testObject.doYouHave(2);

    CHECK(1 == actual.size());
    CHECK(2 == actual.at(0)->getValue());
    CHECK(4 == m_testObject.getHandSize());
}

TEST_CASE_METHOD(PlayerTest, "MakeMove_AsksOthersForCardsOnce") {
    ALLOW_CALL(m_mockController, setPlayAction(_));
    ALLOW_CALL(m_mockController, updatePlayAction(_));
    Card c1(2, Card::hearts);
    Card c2(9, Card::diamonds);
    Card c3(3, Card::spades);
    Card c4(10, Card::spades);
    Card c5(6, Card::spades);
    m_testObject.pushHandCard(&c1);
    m_testObject.pushHandCard(&c2);
    m_testObject.pushHandCard(&c3);
    m_testObject.pushHandCard(&c4);
    m_testObject.pushHandCard(&c5);
    Player otherPlayer("dummy2", m_deck, &m_mockController);
    Card c6(2, Card::diamonds);
    Card c7(4, Card::spades);
    otherPlayer.pushHandCard(&c6);
    otherPlayer.pushHandCard(&c7);
    vector<Card*> cards = m_testObject.askPlayerForCards(&otherPlayer, 2);

    CHECK(5 == m_testObject.getHandSize());
    CHECK(1 == otherPlayer.getHandSize());
}

TEST_CASE_METHOD(PlayerTest, "MakeBooks") {
    m_testObject.pushEasyFish(4);
    Card c1(2, Card::hearts);
    Card c2(4, Card::diamonds);
    Card c3(4, Card::hearts);
    Card c4(4, Card::spades);
    Card c5(4, Card::clubs);
    m_testObject.pushHandCard(&c1);
    m_testObject.pushHandCard(&c2);
    m_testObject.pushHandCard(&c3);
    m_testObject.pushHandCard(&c4);
    m_testObject.pushHandCard(&c5);
    m_testObject.makeBooks();
    CHECK(1 == m_testObject.getBooks().size());
    CHECK(1 == m_testObject.getHandSize());
    CHECK_FALSE(m_testObject.hasEasyFish(4));
}

TEST_CASE_METHOD(PlayerTest, "easyFish") {
    m_testObject.pushEasyFish(6);
    m_testObject.pushEasyFish(9);
    CHECK(2 == m_testObject.getEasyFish().size());
    CHECK(m_testObject.hasEasyFish(6));
    CHECK(m_testObject.hasEasyFish(9));
    m_testObject.popEasyFish(6);
    CHECK(1 == m_testObject.getEasyFish().size());
    CHECK_FALSE(m_testObject.hasEasyFish(6));
    CHECK(m_testObject.hasEasyFish(9));
    m_testObject.popEasyFish(9);
    CHECK(0 == m_testObject.getEasyFish().size());
    CHECK_FALSE(m_testObject.hasEasyFish(6));
    CHECK_FALSE(m_testObject.hasEasyFish(9));
}
