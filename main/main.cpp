#include <iostream>
#include <vector>
#include <MvcGameView.h>
#include <MvcController.h>

#include "GoFishGame.h"
#include "Player.h"
#include "Strategy.h"
#include "StrategyHelper.h"
#include "TurnHelper.h"
#include "HumanStrategy.h"
#include "Log.h"

int main(int argc, char *argv[]) {
    initLogger( "mylogfile.log", ldebug1);
    GoFishUtil util(true);
    //util.printMsgEnd("GoFish Game time");

    //util.printMsgEnd("Players: Eva, Jarvis and Rich");
    MvcModel model;
    MvcGameView view(model);
    MvcController controller(view, model);

    Deck deck;
    std::vector<Player*> players;
    Player ai1("Eva", deck);
    Player ai2("Jarvis", deck);
    Player h("Rich", deck);

    int order = util.getRandomNumber(0, 3);
    if (order == 0) {
        players.push_back(&ai1);
        players.push_back(&ai2);
        players.push_back(&h);
        controller.setNames("Eva", "Jarvis", "Rich");
    } else if (order == 1) {
        players.push_back(&ai2);
        players.push_back(&h);
        players.push_back(&ai1);
        controller.setNames("Jarvis", "Rich", "Eva");
    } else {
        players.push_back(&h);
        players.push_back(&ai1);
        players.push_back(&ai2);
        controller.setNames("Rich", "Eva", "Jarvis");
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

    GoFishGame g(players, 7, deck, controller);
    g.deal();

    for (int i = 0; i < 20; ++i) {
        g.playRound(i + 1);
        if (g.checkWinner(i + 1)) {
            break;
        }
    }

    endLogger();
    return 0;
}
