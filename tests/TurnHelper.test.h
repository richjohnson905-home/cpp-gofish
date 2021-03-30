//
// Created by Richard Johnson on 3/30/21.
//

#ifndef GOFISH_TURNHELPER_TEST_H
#define GOFISH_TURNHELPER_TEST_H

class TurnHelperTest {

protected:
    std::unique_ptr<TurnHelper> testObject;
    Deck deck;
    MockStrategyHelper mockStrategyHelper;
    MockPlayer mockMe;
    MockPlayer mockOther;

public:
    TurnHelperTest(){}

    virtual ~TurnHelperTest(){}

    void setTestObject(IStrategyHelper& helper, IPlayer& me);

};

#endif //GOFISH_TURNHELPER_TEST_H
