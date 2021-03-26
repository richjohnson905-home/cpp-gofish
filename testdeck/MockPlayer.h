#include "trompeloeil.hpp"
#include "Player.h"

class MockPlayer : public IPlayer
{
public:
    MAKE_CONST_MOCK0(getHand, const std::vector<Card*>*(), override);
    MAKE_MOCK1(pushEasyFish, void(int), override);
    MAKE_CONST_MOCK1(hasEasyFish, bool(int), override);
    MAKE_CONST_MOCK0(getHandSize, int(), override);
    MAKE_MOCK2(askPlayerForCards, std::vector<Card*>(IPlayer*, int), override);
    MAKE_MOCK1(pushHand, void(std::vector<Card*>), override);
    MAKE_MOCK1(pushHandCard, void(Card*), override);
    MAKE_MOCK0(makeBooks, void(), override);
    MAKE_MOCK0(getName, std::string(), override);
    MAKE_MOCK1(doYouHave, std::vector<Card*>(int), override);
    MAKE_MOCK1(takeTurn, void(std::vector<IPlayer*>&), override);
    MAKE_MOCK0(sortHand, void(), override);
    MAKE_CONST_MOCK0(getBooks, std::vector<int>(), override);

};