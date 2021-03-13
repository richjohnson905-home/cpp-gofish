#ifndef GOFISH_HUMANSTRATEGEY_H
#define GOFISH_HUMANSTRATEGEY_H

#include "IStrategy.h"
#include "Deck.h"
#include "Player.h"

#include <vector>

class HumanStrategy : public IStrategy {
public:
    HumanStrategy(Player* myPlayer, Deck& deck);

    void takeTurn(std::vector<Player*>& players);

    // void makeMove(std::vector<Player*>& players);
    // virtual void doYouHave(int fish, std::vector<Card*>& cards);

private:
    // std::vector<Player*>& players_;
    Player* me_;
};

#endif