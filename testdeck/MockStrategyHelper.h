#include "trompeloeil.hpp"
#include "CardCompare.h"
#include "../libgofish/StrategyHelper.h"
#include "Card.h"

class MockStrategyHelper : public IStrategyHelper
{
public:
    typedef std::set<Card*, CardCompare> CardCompareType;
    typedef std::optional<std::pair<IPlayer*, int>> optionalPandB;

    MAKE_MOCK2(goEasyFishing, optionalPandB(IPlayer*, std::vector<IPlayer*>&), override);
    MAKE_CONST_MOCK1(getFishPlayer, std::optional<IPlayer*>(std::vector<IPlayer*>&), override);
    MAKE_CONST_MOCK1(getBaitCard, int(IPlayer*), override);
    MAKE_CONST_MOCK1(getPossibleBaitCards, CardCompareType(IPlayer*), override);
    MAKE_CONST_MOCK1(getHumansPlayerChoice, int(std::vector<IPlayer*>&), override);
    MAKE_CONST_MOCK1(getHumansBaitChoice, int(IPlayer*), override);
};