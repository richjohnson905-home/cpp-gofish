//
// Created by Richard Johnson on 3/21/21.
//

#ifndef GOFISH_TURNHELPER_H
#define GOFISH_TURNHELPER_H

#include "Player.h"
#include "Deck.h"
#include "StrategyHelper.h"

#include <vector>

class TurnHelper {
public:
    TurnHelper(StrategyHelper& helper, Player& me);
    virtual bool easyFish(std::vector<Player*>& players);
    virtual bool hardFish(std::vector<Player*>& players, Deck& deck);

private:
    StrategyHelper& m_helper;
    Player& m_me;

    std::vector<Card*> askPlayer(std::optional<std::pair<Player*, int>>& optPair);
    void acceptCards(std::vector<Card*>& cards);
    bool deckFish(Deck& deck, int bait);
};


#endif //GOFISH_TURNHELPER_H
