#ifndef GOFISH_STRATEGEY_H
#define GOFISH_STRATEGEY_H

#include "Deck.h"
#include "CardCompare.h"
#include "TurnHelper.h"

#include <vector>
#include <set>

class IPlayer;

class IStrategy {
public:
    virtual void takeTurn(std::vector<IPlayer*>& players) = 0;
};

class Strategy : public IStrategy {
private:
    IPlayer& m_me;
    Deck& m_deck;
    ITurnHelper& m_turnHelper;

public:
    virtual ~Strategy() {}
    Strategy(ITurnHelper& turnHelper, IPlayer& myPlayer, Deck& deck);

    virtual void takeTurn(std::vector<IPlayer*>& players);

 };

#endif