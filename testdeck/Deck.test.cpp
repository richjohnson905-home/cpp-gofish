
#include "Deck.h"
#include "Deck.test.h"
#include "doctest.h"

using namespace std;

DeckTestFixture::DeckTestFixture() {
    // Have qux return true by default
    //ON_CALL(m_bar,qux()).WillByDefault(Return(true));
    // Have norf return false by default
    //ON_CALL(m_bar,norf()).WillByDefault(Return(false));
}

DeckTestFixture::~DeckTestFixture() {};

void DeckTestFixture::SetUp() {};

void DeckTestFixture::TearDown() {};


TEST_CASE_FIXTURE(DeckTestFixture, "Deck works correctly") {
    
    SUBCASE("size") {
        CHECK_EQ(52, m_deck.getDeckSize());
    }
    SUBCASE("deal") {
        MESSAGE("Deal some cards");
        Card* c1 = m_deck.dealCard();

        CHECK_LT(1, c1->getValue());
        CHECK_GT(15, c1->getValue());
        CHECK_EQ(51, m_deck.getDeckSize());

        Card* c2 = m_deck.dealCard();
        CHECK_LT(1, c2->getValue());
        CHECK_GT(15, c2->getValue());
        CHECK_EQ(50, m_deck.getDeckSize());
    }

    GIVEN("A deck with 52 cards") {
        REQUIRE(m_deck.getDeckSize() == 52);
        WHEN("5 cards are dealt") {
            m_deck.dealCard();
            m_deck.dealCard();
            m_deck.dealCard();
            m_deck.dealCard();
            m_deck.dealCard();

            THEN ("There are 47 card remaining") {
                CHECK(m_deck.getDeckSize() == 47);
            }
        }
    }
}

