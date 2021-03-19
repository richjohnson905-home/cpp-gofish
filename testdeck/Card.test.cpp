#include "Card.h"
#include "doctest.h"

TEST_CASE("init") {
    Card card(2, Card::hearts);
    CHECK_EQ(2, card.getValue());
}

TEST_CASE("InitSuit") {
    Card card(2, Card::hearts);
    CHECK_EQ(Card::hearts, card.getSuit());
}

TEST_CASE("CardValue") {
    Card jack(11, Card::hearts);
    CHECK_EQ("J", jack.getCardValue());
    Card queen(12, Card::hearts);
    CHECK_EQ("Q", queen.getCardValue());
    Card king(13, Card::hearts);
    CHECK_EQ("K", king.getCardValue());
    Card ace(14, Card::hearts);
    CHECK_EQ("A", ace.getCardValue());
}
