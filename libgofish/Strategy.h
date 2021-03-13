#ifndef GOFISH_STRATEGEY_H
#define GOFISH_STRATEGEY_H

#include "IStrategy.h"
// #include "StrategyHelper.h"
#include "Deck.h"
#include "CardCompare.h"

#include <vector>
#include <set>

class Player;
class StrategyHelper;

class Strategy : public IStrategy {
public:
    virtual ~Strategy() {}
    Strategy(StrategyHelper& helper, Player& myPlayer, Deck& deck);

    void takeTurn(std::vector<Player*>& players);
 private:
    Player& m_me;
    Deck& m_deck;
    StrategyHelper& m_helper;

    bool doTakeTurn(std::vector<Player*>& players);
    bool doTurnCompletion(std::vector<Card*> cards, int fish); 
 };

#endif