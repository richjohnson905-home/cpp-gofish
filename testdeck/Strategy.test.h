
// #include "MockPlayer.h"
// #include "MockStrategyHelper.h"
#include "Card.h"
#include "Deck.h"
#include "Strategy.h"
#include "StrategyHelper.h"
#include "Player.h"

// The fixture for testing class Foo.
class StrategyTestFixture {

protected:

    // You can do set-up work for each test here.
    StrategyTestFixture();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~StrategyTestFixture();

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor (right
    // before each test).
    virtual void SetUp();

    // Code here will be called immediately after each test (right
    // before the destructor).
    virtual void TearDown();

    // The mock bar library shared by all tests
    Player m_me;
    Player m_otherPlayer;
    StrategyHelper m_helper;
    std::vector<Player*> m_otherplayers;
    Deck m_deck;
    Strategy m_testObject;
};
