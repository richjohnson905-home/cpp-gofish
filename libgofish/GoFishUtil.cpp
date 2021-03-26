#include "GoFishUtil.h"
#include "Player.h"

#include <algorithm>
#include <iostream>

using namespace std;

vector<IPlayer*> GoFishUtil::removePlayer(const vector<IPlayer*>& players, IPlayer* player) {
    vector<IPlayer*> result;
    vector<IPlayer*>::const_iterator iter;
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
