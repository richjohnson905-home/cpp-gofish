//
// Created by Richard Johnson on 3/21/21.
//

#ifndef GOFISH_TURNHELPER_H
#define GOFISH_TURNHELPER_H

#include "Player.h"
#include "Deck.h"
#include "StrategyHelper.h"
#include "MvcController.h"

#include <vector>

class ITurnHelper {
public:
    virtual bool easyFish(std::vector<IPlayer*>& players) = 0;
    virtual bool hardFish(std::vector<IPlayer*>& players, Deck& deck) = 0;
};

class TurnHelper : public ITurnHelper {
private:
    IStrategyHelper& m_helper;
    IPlayer& m_me;

    std::vector<Card*> askPlayer(std::optional<std::pair<IPlayer*, int>>& optPair);
    void acceptCards(std::vector<Card*>& cards);
    bool deckFish(Deck& deck, int bait);

public:
    TurnHelper(IStrategyHelper& helper, IPlayer& me);
    virtual bool easyFish(std::vector<IPlayer*>& players);
    virtual bool hardFish(std::vector<IPlayer*>& players, Deck& deck);


};


#endif //GOFISH_TURNHELPER_H
