#include <iostream>
#include <vector>

#include "GoFishGame.h"
#include "Player.h"
#include "Strategy.h"
#include "StrategyHelper.h"
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
    players.push_back(&ai1);
    players.push_back(&ai2);
    players.push_back(&h);

    StrategyHelper helper;
    Strategy goFishStrategyAi1(helper, ai1, deck);
    Strategy goFishStrategyAi2(helper, ai2, deck);
    if (argc > 1) {
        HumanStrategy humanStrategy(&h, deck, helper);
        h.setStrategy(&humanStrategy);
    } else {
        Strategy goFishStrategyAi3(helper, h, deck);
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
