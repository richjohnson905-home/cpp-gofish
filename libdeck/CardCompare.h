#ifndef DECK_CARDCOMPARE_H
#define DECK_CARDCOMPARE_H

#include "Card.h"

struct CardCompare
{
    bool operator()(const int& lhs, const int& rhs) const
    {
        return lhs < rhs;
    }

    bool operator()(const Card* lhs, const Card* rhs) const
    {
        return lhs->getValue() < rhs->getValue();
    }
};

#endif