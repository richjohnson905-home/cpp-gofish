
#include "Strategy.test.h"
#include "Strategy.h"
#include "Log.h"
#include "doctest.h"
#include "fakeit.hpp"

#include <vector>

using namespace std;
using namespace fakeit;

StrategyTestFixture::StrategyTestFixture():
    m_me("TestUser", m_deck),
    m_otherPlayer("TEST_OTHER_PLAYER", m_deck),
    m_testObject(m_helper, m_me, m_deck)
{
    
}

StrategyTestFixture::~StrategyTestFixture() {};

void StrategyTestFixture::SetUp() {
    m_otherplayers.push_back(&m_otherPlayer);
    // ON_CALL(m_me, getHandSize()).WillByDefault(Return(5));
};

void StrategyTestFixture::TearDown() {};

TEST_CASE_FIXTURE(StrategyTestFixture, "doTakeTurn_WithEmptyHand") {
    Mock<Player> spy(m_me);
    auto mock = spy.get();
    When(Method(spy, getHandSize)).AlwaysReturn(0);
    m_testObject.takeTurn(m_otherplayers);
    //VerifyNoOtherInvocations(spy);
}

/*
TEST_F(StrategyTest, doTakeTurn_WithEmptyHand) {
    
    
    ON_CALL(m_me, getHandSize()).WillByDefault(Return(0));
    EXPECT_CALL(m_helper, goEasyFishing(_, _, _)).Times(0);
    m_testObject.takeTurn(m_otherplayers);
}

TEST_F(StrategyTest, doTakeTurn_EasyFish) {
    vector<Card*> twoThrees = {
        new Card(3, Card::hearts),
        new Card(3, Card::diamonds)
    };
    vector<Card*> emptyCards = {};
    int bait3 = 3;
    int bait4 = 4;
    
    EXPECT_CALL(m_helper, goEasyFishing(_, _, _))
        .WillOnce(DoAll(SetArgReferee<2>(bait3), Return(twoThrees)))
        .WillOnce(DoAll(SetArgReferee<2>(bait4), Return(emptyCards)));
    EXPECT_CALL(m_me, getHandSize())
        .WillRepeatedly(Return(5));

    m_testObject.takeTurn(m_otherplayers);
}

TEST_F(StrategyTest, doTakeTurn_HardFish) {
    vector<Card*> twoThrees = {
        new Card(3, Card::hearts),
        new Card(3, Card::diamonds)
    };
    vector<Card*> emptyCards = {};
    vector<Card*> deckCard = {new Card(6, Card::hearts)};
    int bait3 = 3;
    int bait4 = 4;
    
    EXPECT_CALL(m_me, getHandSize())
        .WillRepeatedly(Return(5));
    EXPECT_CALL(m_helper, goEasyFishing(_, _, _))
        .WillRepeatedly(Return(emptyCards));
    EXPECT_CALL(m_helper, getBaitCard(_))
        .WillOnce(Return(bait3))
        .WillOnce(Return(bait4));
    EXPECT_CALL(m_me, pushEasyFish(bait3)).Times(1);    
    EXPECT_CALL(m_me, pushEasyFish(bait4)).Times(1);    
    
    EXPECT_CALL(m_helper, goFishing(_, _, _, _))
        .WillOnce(Return(twoThrees))
        .WillOnce(Return(deckCard));

    m_testObject.takeTurn(m_otherplayers);
}
*/