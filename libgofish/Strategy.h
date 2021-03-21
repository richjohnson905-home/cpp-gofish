#ifndef GOFISH_STRATEGEY_H
#define GOFISH_STRATEGEY_H

#include "IStrategy.h"
#include "Deck.h"
#include "CardCompare.h"
#include "TurnHelper.h"

#include <vector>
#include <set>

class Player;
class StrategyHelper;

class Strategy : public IStrategy {
public:
    virtual ~Strategy() {}
    Strategy(TurnHelper& turnHelper, Player& myPlayer, Deck& deck);

    void takeTurn(std::vector<Player*>& players);
 private:
    Player& m_me;
    Deck& m_deck;
    TurnHelper& m_turnHelper;
 };

#endif