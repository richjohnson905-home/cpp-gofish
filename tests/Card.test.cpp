#include <catch2/catch_test_macros.hpp>

#include "Card.h"

TEST_CASE("CardTest Init") {
    Card card(2, Card::hearts);
    CHECK(2 == card.getValue());
}

TEST_CASE("CardTest InitSuit") {
    Card card(2, Card::hearts);
    CHECK(Card::hearts == card.getSuit());
}

TEST_CASE("CardTest - CardValue") {
    Card jack(11, Card::hearts);
    CHECK("J" == jack.getCardValue());
    Card queen(12, Card::hearts);
    CHECK("Q" == queen.getCardValue());
    Card king(13, Card::hearts);
    CHECK("K" == king.getCardValue());
    Card ace(14, Card::hearts);
    CHECK("A" == ace.getCardValue());
}
