#include "gmock/gmock.h"
#include "Player.h"

class MockPlayer : public Player
{
public:
    MockPlayer(std::string name, Deck& deck):Player(name, deck){}

    MOCK_METHOD0(getHand, std::vector<Card*>*());
    MOCK_METHOD1(pushEasyFish, void(int));
    MOCK_CONST_METHOD1(hasEasyFish, bool(int));
    MOCK_CONST_METHOD0(getHandSize, int());
    MOCK_METHOD3(otherHasCards, bool(Player*, std::vector<Card*>&, int));

};