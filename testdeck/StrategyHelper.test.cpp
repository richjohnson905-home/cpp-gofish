#include "gtest/gtest.h"

#include "StrategyHelper.h"
#include "MockPlayer.h"


using namespace std;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;
using ::testing::SetArgReferee;

TEST(StrategyHelperTest, GoEasyFishing) {
    StrategyHelper testObject;
    NiceMock<MockPlayer> me;
    NiceMock<MockPlayer> other1;
    NiceMock<MockPlayer> other2;
    vector<Player*> otherPlayers = {&other1, &other2};
    vector<Card*> myCards = {
        new Card(3, Card::hearts),
        new Card(4, Card::diamonds)
    };
    int bait;
    vector<Card*> othersCards = {
        new Card(3, Card::diamonds),
        new Card(7, Card::diamonds)
    };
    ON_CALL(me, getHand()).WillByDefault(Return(myCards));
    EXPECT_CALL(other1, hasEasyFish(3)).WillOnce(Return(true));
    EXPECT_CALL(other1, hasEasyFish(4)).WillOnce(Return(false));
    ON_CALL(other2, hasEasyFish(_)).WillByDefault(Return(false));
    EXPECT_CALL(me, otherHasCards(&other1, _, _))
        .WillOnce(SetArgReferee<1>(othersCards));

    vector<Card*> actual = testObject.goEasyFishing(&me, otherPlayers, bait);
}
/*
TEST_F(StrategyTest, getFishableCards) {
    Deck d;
    StrategyHelper testObject(m_me, d);
    
    vector<Card*> myCards = {
        new Card(2, Card::hearts), 
        new Card(2, Card::hearts),
        new Card(3, Card::hearts),
        new Card(4, Card::hearts),
        new Card(5, Card::hearts),
        new Card(6, Card::hearts),
        new Card(8, Card::hearts)
        };
    ON_CALL(m_me, getHand()).WillByDefault(Return(&myCards));

    set<Card*, CardCompare> fishableCards = testObject.getPossibleBaitCards();

    EXPECT_EQ(6, fishableCards.size());
}
*/