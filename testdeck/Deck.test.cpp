
#include "Deck.h"
#include "Deck.test.h"

//using ::testing::Return;

DeckTest::DeckTest() {
    // Have qux return true by default
    //ON_CALL(m_bar,qux()).WillByDefault(Return(true));
    // Have norf return false by default
    //ON_CALL(m_bar,norf()).WillByDefault(Return(false));
}

DeckTest::~DeckTest() {};

void DeckTest::SetUp() {};

void DeckTest::TearDown() {};


TEST_CASE("DeckSize") {
    Deck d;
    CHECK(52 == d.getDeckSize());
}

TEST_CASE("deal") {
    Deck d;
    Card* c1 = d.dealCard();
    CHECK(c1->getValue() > 1);
    CHECK(c1->getValue() < 15);
    CHECK(51 == d.getDeckSize());

    Card* c2 = d.dealCard();
    CHECK(c2->getValue() > 1);
    CHECK(c2->getValue() < 15);
    CHECK(50 == d.getDeckSize());
}
