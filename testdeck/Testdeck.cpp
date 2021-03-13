
#include "Deck.h"
#include "Testdeck.h"

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


TEST(DeckTest, DeckSize) {
    Deck d;
    EXPECT_EQ(52, d.getDeckSize());
}

TEST(DeckTest, deal) {
    Deck d;
    Card* c1 = d.dealCard();
    EXPECT_TRUE(c1->getValue() > 1 && c1->getValue() < 15);
    EXPECT_EQ(51, d.getDeckSize());

    Card* c2 = d.dealCard();
    EXPECT_TRUE(c2->getValue() > 1 && c2->getValue() < 15);
    EXPECT_EQ(50, d.getDeckSize());
}
