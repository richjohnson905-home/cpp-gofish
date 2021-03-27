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

    // You can do set-up work for each test here.
    StrategyTest();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~StrategyTest();

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor (right
    // before each test).
    virtual void SetUp();

    // Code here will be called immediately after each test (right
    // before the destructor).
    virtual void TearDown();

    // The mock bar library shared by all tests
    MockTurnHelper mockTurnHelper;
    MockPlayer m_me;
    MockPlayer m_otherPlayer;
    std::vector<IPlayer*> m_otherPlayers;
    Deck m_deck;
    Strategy testObject;
};
