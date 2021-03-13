#include "gmock/gmock.h"
#include "Strategy.h"
#include "Deck.h"
#include "StrategyHelper.h"

class MockStrategy : public Strategy
{
public:
    MockStrategy(StrategyHelper& helper, Player& myPlayer, Deck& d):Strategy(helper, myPlayer, d){}

    // MOCK_METHOD2(doYouHave, void(int, std::vector<Card*>&));
    
};