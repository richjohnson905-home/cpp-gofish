#include "trompeloeil.hpp"
#include "Player.h"

class MockPlayer : public Player
{
public:
    MockPlayer(std::string name, Deck& deck):Player(name, deck){}

    MAKE_MOCK0(getHand, std::vector<Card*>*(), override);
    MAKE_MOCK1(pushEasyFish, void(int), override);
    MAKE_CONST_MOCK1(hasEasyFish, bool(int), override);
    MAKE_CONST_MOCK0(getHandSize, int(), override);
    MAKE_MOCK2(askPlayerForCards, std::vector<Card*>(Player*, int), override);
    MAKE_MOCK1(pushHand, void(std::vector<Card*>), override);
    MAKE_MOCK1(pushHandCard, void(Card*), override);
};