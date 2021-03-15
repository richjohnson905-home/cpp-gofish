#ifndef GOFISH_HUMANSTRATEGEY_H
#define GOFISH_HUMANSTRATEGEY_H

#include "IStrategy.h"
#include "Deck.h"
#include "Player.h"
#include "StrategyHelper.h"

#include <vector>

class HumanStrategy : public IStrategy {
public:
    HumanStrategy(Player* myPlayer, Deck& deck, StrategyHelper& helper);

    void takeTurn(std::vector<Player*>& players);
    bool doTakeTurn(std::vector<Player*>& players);

private:
    Player* m_me;
    StrategyHelper& m_helper;
    Deck& m_deck;

    bool doTurnCompletion(std::vector<Card*> fishedCards, int bait);
    std::vector<Card*> goFishing(Player* other, int bait);
};

#endif