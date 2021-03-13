#ifndef DECK_CARD_H
#define DECK_CARD_H

#include <string>

class Card
{
public:
    enum suit { hearts, diamonds, clubs, spades };

    Card(int value, suit mySuit);

    suit getSuit() const;
    int getValue() const;
    std::string getCardValue() const;
    std::string getSuitValue() const;
    std::string show() const;
    
private:
    int value_;
    suit suit_;
};



#endif