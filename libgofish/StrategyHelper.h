#ifndef GOFISH_STRATEGEYHELPER_H
#define GOFISH_STRATEGEYHELPER_H

#include "GoFishUtil.h"
#include "CardCompare.h"

#include <set>
#include <vector>
#include <functional>

class Card;
class Player;
class Deck;

class StrategyHelper {
public:
    virtual std::optional<std::pair<Player*, int>> goEasyFishing(Player* me, std::vector<Player*>& players);
    virtual std::optional<Player*> getFishPlayer(std::vector<Player*>& players) const;
    virtual int getBaitCard(Player* me) const;
    virtual std::set<Card*, CardCompare> getPossibleBaitCards(Player* me) const;
    virtual int getHumansPlayerChoice(std::vector<Player*>& players) const;
    virtual int getHumansBaitChoice(Player* me) const;
private:
    GoFishUtil m_util;

    int getChoice(int maxInput) const;
};

#endif