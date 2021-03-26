//
// Created by Richard Johnson on 3/25/21.
//

#ifndef GOFISH_PLAYER_TEST_H
#define GOFISH_PLAYER_TEST_H

// The fixture for testing class Foo.
class PlayerTest {

protected:

    // You can do set-up work for each test here.
    PlayerTest();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~PlayerTest();

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor (right
    // before each test).
    virtual void SetUp();

    // Code here will be called immediately after each test (right
    // before the destructor).
    virtual void TearDown();

    // The mock bar library shared by all tests
    MockMvcController m_mockController;
//    MockPlayer m_me;
//    MockPlayer m_otherPlayer;
//    MockTurnHelper m_turnHelper;
//    std::vector<Player*> m_otherPlayers;
    Deck m_deck;
//    Strategy m_testObject;
};
#endif //GOFISH_PLAYER_TEST_H
