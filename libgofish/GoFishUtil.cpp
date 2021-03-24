#include "GoFishUtil.h"
#include "Player.h"

#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

GoFishUtil::GoFishUtil(bool verbose):m_verbose(verbose) {

}

vector<Player*> GoFishUtil::removePlayer(const vector<Player*>& players, Player* player) {
    vector<Player*> result;
    vector<Player*>::const_iterator iter;
    for (iter = players.begin(); iter != players.end(); ++iter) {
        if (*iter != player) { //} && (*iter)->getHandSize() > 0) {
            result.push_back(*iter);
        }
    }
    return result;
}

int GoFishUtil::getRandomNumber(int min, int max) const
{
    srand (time(NULL));
    int myRandomNumber = rand() % max;
    return myRandomNumber;
}

void GoFishUtil::printMsg(const string& msg) {
    if (m_verbose) {
        int x = 0;
        while (msg[x] != '\0') {
            cout << msg[x] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            x++;
        };
    } else {
        cout << msg;
    }
}

void GoFishUtil::printMsgEnd(const std::string &msg) {
    printMsg(msg);
    printMsg("\n");
}