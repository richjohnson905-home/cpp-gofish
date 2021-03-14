#include "gtest/gtest.h"

#include "StrategyHelper.h"
#include "MockPlayer.h"

using namespace std;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::_;
using ::testing::SetArgReferee;
using ::testing::DoAll;

TEST(StrategyHelperTest, GoEasyFishing) {
    Deck deck;
    StrategyHelper testObject;
    NiceMock<MockPlayer> me("TestObj", deck);
    NiceMock<MockPlayer> other1("Other1", deck);
    NiceMock<MockPlayer> other2("Other2", deck);
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
    ON_CALL(me, getHand()).WillByDefault(Return(&myCards));
    EXPECT_CALL(other1, hasEasyFish(3)).WillOnce(Return(true));
    ON_CALL(other2, hasEasyFish(_)).WillByDefault(Return(false));
    EXPECT_CALL(me, otherHasCards(&other1, _, 3))
        .WillOnce(DoAll(SetArgReferee<1>(othersCards), Return(true)));

    vector<Card*> actual = testObject.goEasyFishing(&me, otherPlayers, bait);

    EXPECT_EQ(2, actual.size());
}

TEST(StrategyHelperTest, goFishing_goFish) {
    Deck deck;
    StrategyHelper testObject;
    NiceMock<MockPlayer> me("TestObj", deck);
    NiceMock<MockPlayer> other1("Other1", deck);
    vector<Player*> otherPlayers = {&other1};
    int bait = 3;

    EXPECT_CALL(me, otherHasCards(&other1, _, bait))
        .WillOnce(Return(false));

    vector<Card*> actual = testObject.goFishing(&me, deck, otherPlayers, bait);

    EXPECT_EQ(1, actual.size());

}

TEST(StrategyHelperTest, getBaitCard) {
    Deck deck;
    StrategyHelper testObject;
    NiceMock<MockPlayer> me("TestObj", deck);
    vector<Card*> myCards = {
        new Card(3, Card::hearts),
        new Card(3, Card::diamonds),
        new Card(4, Card::diamonds),
        new Card(4, Card::clubs)
    };

    EXPECT_CALL(me, getHand()).WillRepeatedly(Return(&myCards));

    int bait = testObject.getBaitCard(&me);

    EXPECT_TRUE(bait == 3 || bait == 4);

}