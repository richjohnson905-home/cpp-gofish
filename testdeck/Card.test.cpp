#include "catch.hpp"

#include "Card.h"

TEST_CASE("CardTest Init") {
    Card card(2, Card::hearts);
    CHECK(2 == card.getValue());
}

TEST_CASE("CardTest InitSuit") {
    Card card(2, Card::hearts);
    CHECK(Card::hearts == card.getSuit());
}
/*
TEST(CardTest, CardValue) {
    Card jack(11, Card::hearts);
    EXPECT_EQ("J", jack.getCardValue());
    Card queen(12, Card::hearts);
    EXPECT_EQ("Q", queen.getCardValue());
    Card king(13, Card::hearts);
    EXPECT_EQ("K", king.getCardValue());
    Card ace(14, Card::hearts);
    EXPECT_EQ("A", ace.getCardValue());
}
 */