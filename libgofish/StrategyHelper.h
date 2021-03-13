#ifndef GOFISH_STRATEGEYHELPER_H
#define GOFISH_STRATEGEYHELPER_H

#include "GoFishUtil.h"
#include "CardCompare.h"

#include <set>
#include <vector>

class Card;
class Player;
class Deck;

class StrategyHelper {
public:

    virtual std::vector<Card*> goEasyFishing(Player* me, std::vector<Player*>& players, int& bait);
    virtual std::vector<Card*> goFishing(Player* me, Deck& deck, std::vector<Player*>& players, int bait);
    virtual int getBaitCard(Player* me) const;
    virtual std::set<Card*, CardCompare> getPossibleBaitCards(Player* me) const;

private:
    GoFishUtil m_util;
};

#endif