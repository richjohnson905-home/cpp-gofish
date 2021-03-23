#include "trompeloeil.hpp"
#include "CardCompare.h"
#include "../libgofish/StrategyHelper.h"
#include "Card.h"

class MockStrategyHelper : public StrategyHelper
{
public:
    typedef std::set<Card*, CardCompare> CardCompareType;
    typedef std::optional<std::pair<Player*, int>> optionalPandB;

    MAKE_MOCK2(goEasyFishing, optionalPandB(Player*, std::vector<Player*>&), override);
    MAKE_CONST_MOCK1(getFishPlayer, std::optional<Player*>(std::vector<Player*>&), override);
    MAKE_CONST_MOCK1(getBaitCard, int(Player*), override);
    MAKE_CONST_MOCK1(getPossibleBaitCards, CardCompareType(Player*), override);
    MAKE_CONST_MOCK1(getHumansPlayerChoice, int(std::vector<Player*>&), override);
    MAKE_CONST_MOCK1(getHumansBaitChoice, int(Player*), override);
};