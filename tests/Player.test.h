//
// Created by Richard Johnson on 3/25/21.
//

#ifndef GOFISH_PLAYER_TEST_H
#define GOFISH_PLAYER_TEST_H

// The fixture for testing class Foo.
class PlayerTest {

protected:
    Deck m_deck;
    std::unique_ptr<Player> m_testObject;

public:
    PlayerTest(){}

    virtual ~PlayerTest(){}

    void setTestObject(std::string name, Deck& deck);

};
#endif //GOFISH_PLAYER_TEST_H
