#ifndef DECK_ISTRATEGEY_H
#define DECK_ISTRATEGEY_H

#include <vector>

class Card;
class Player;

class IStrategy {
public:
    virtual void takeTurn(std::vector<Player*>& players) = 0;
    
};

#endif