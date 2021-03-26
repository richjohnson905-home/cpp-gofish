#ifndef GOFISH_STRATEGEYHELPER_H
#define GOFISH_STRATEGEYHELPER_H

#include "GoFishUtil.h"
#include "CardCompare.h"

#include <set>
#include <map>
#include <vector>
#include <functional>

class Card;
class IPlayer;
class Deck;

class IStrategyHelper {
public:
    virtual std::optional<std::pair<IPlayer*, int>> goEasyFishing(IPlayer* me, std::vector<IPlayer*>& players) = 0;
    virtual std::optional<IPlayer*> getFishPlayer(std::vector<IPlayer*>& players) const = 0;
    virtual int getBaitCard(IPlayer* me) const = 0;
    virtual std::set<Card*, CardCompare> getPossibleBaitCards(IPlayer* me) const = 0;
    virtual int getHumansPlayerChoice(std::vector<IPlayer*>& players) const = 0;
    virtual int getHumansBaitChoice(IPlayer* me) const = 0;
};

class StrategyHelper : public IStrategyHelper {
private:
    GoFishUtil m_util;

    static int getChoice(int maxInput);

public:
    std::optional<std::pair<IPlayer*, int>> goEasyFishing(IPlayer* me, std::vector<IPlayer*>& players) override;
    std::optional<IPlayer*> getFishPlayer(std::vector<IPlayer*>& players) const override;
    int getBaitCard(IPlayer* me) const override;
    std::set<Card*, CardCompare> getPossibleBaitCards(IPlayer* me) const override;
    int getHumansPlayerChoice(std::vector<IPlayer*>& players) const override;
    int getHumansBaitChoice(IPlayer* me) const override;
};

#endif