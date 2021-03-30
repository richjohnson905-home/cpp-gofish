#include "GoFishUtil.h"
#include "Player.h"

#include <algorithm>
#include <random>

using std::vector;

vector<IPlayer*> GoFishUtil::removePlayer(const vector<IPlayer*>& players, IPlayer* player) {
    vector<IPlayer*> result;
    vector<IPlayer*>::const_iterator iter;
    for (iter = players.begin(); iter != players.end(); ++iter) {
        if (*iter != player) {
            result.push_back(*iter);
        }
    }
    return result;
}

int GoFishUtil::getRandomNumber(int min, int max)
{
    using namespace std;
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.0, max);
    return dist(mt);
}
