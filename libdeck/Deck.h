#ifndef DECK_DECK_H
#define DECK_DECK_H

#include "Card.h"

#include <vector>

class Deck
{
public:

    Deck();

    int getDeckSize();
    void showDeck();
    Card* dealCard();
    void initDeck(std::vector<Card*>& cards);
    
private:
    std::vector<Card*> cards;
    
};

#endif