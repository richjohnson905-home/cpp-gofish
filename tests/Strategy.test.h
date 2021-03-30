#include "Card.h"
#include "Deck.h"
#include "Strategy.h"
#include "mocks/MockStrategyHelper.h"
#include "mocks/MockPlayer.h"

#include "trompeloeil.hpp"
#include "mocks/MockTurnHelper.h"
#include "mocks/MockMvcController.h"

// The fixture for testing class Foo.
class StrategyTest {

protected:
    MockTurnHelper mockTurnHelper;
    MockPlayer m_me;
    MockPlayer m_otherPlayer;
    std::vector<IPlayer*> m_otherPlayers;
    Deck m_deck;
    std::unique_ptr<Strategy> testObject;

public:
    // You can do set-up work for each test here.
    StrategyTest(){}

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~StrategyTest(){}

    void setTestObject(ITurnHelper& turnHelper, IPlayer& myPlayer, Deck& deck);

};
