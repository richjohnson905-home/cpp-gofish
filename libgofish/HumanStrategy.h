#ifndef GOFISH_HUMANSTRATEGEY_H
#define GOFISH_HUMANSTRATEGEY_H

#include "Strategy.h"
#include "Deck.h"

#include <vector>

class IPlayer;
class IStrategyHelper;

class HumanStrategy : public IStrategy {
public:
    HumanStrategy(IPlayer* myPlayer, Deck& deck, IStrategyHelper& helper);

    void takeTurn(std::vector<IPlayer*>& players);
    bool doTakeTurn(std::vector<IPlayer*>& players);

private:
    IPlayer* m_me;
    IStrategyHelper& m_helper;
    Deck& m_deck;

    bool doTurnCompletion(std::vector<Card*> fishedCards, int bait);
    std::vector<Card*> goFishing(IPlayer* other, int bait);
};

#endif