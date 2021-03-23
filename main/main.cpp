#include <iostream>
#include <vector>

#include "GoFishGame.h"
#include "Player.h"
#include "Strategy.h"
#include "StrategyHelper.h"
#include "TurnHelper.h"
#include "HumanStrategy.h"
#include "Log.h"

int main(int argc, char *argv[]) {
    initLogger( "mylogfile.log", ldebug1);
    std::cout << "GoFish Game time" << std::endl;

    Deck deck;
    std::vector<Player*> players;
    Player ai1("Eva", deck);
    Player ai2("Jarvis", deck);
    Player h("Rich", deck);

    GoFishUtil util;
    int order = util.getRandomNumber(0, 3);
    std::cout << "ORDER: " << order << std::endl;
    if (order == 0) {
        players.push_back(&ai1);
        players.push_back(&ai2);
        players.push_back(&h);
    } else if (order == 1) {
        players.push_back(&ai2);
        players.push_back(&h);
        players.push_back(&ai1);
    } else {
        players.push_back(&h);
        players.push_back(&ai1);
        players.push_back(&ai2);
    }

    StrategyHelper helper;
    TurnHelper turnHelper1(helper, ai1);
    TurnHelper turnHelper2(helper, ai2);
    TurnHelper turnHelperH(helper, h);
    Strategy goFishStrategyAi1(turnHelper1, ai1, deck);
    Strategy goFishStrategyAi2(turnHelper2, ai2, deck);
    if (argc > 1) {
        HumanStrategy humanStrategy(&h, deck, helper);
        h.setStrategy(&humanStrategy);
    } else {
        Strategy goFishStrategyAi3(turnHelperH, h, deck);
        h.setStrategy(&goFishStrategyAi3);
    }
    // Strategy goFishStrategyAi3(helper, h, deck);
    //HumanStrategy humanStrategy(&h, deck, helper);

    ai1.setStrategy(&goFishStrategyAi1);
    ai2.setStrategy(&goFishStrategyAi2);
    //h.setStrategy(&humanStrategy);

    GoFishGame g(players, 7, deck);
    g.deal();

    for (int i = 0; i < 20; ++i) {
        g.playRound(i + 1);
        if (g.checkWinner(i + 1)) {
            g.showHands();
            break;
        }
    }

    std::cout << "GAME EXIT" << std::endl;
    endLogger();
    return 0;
}
