#include "GoFishUtil.h"
#include "Card.h"
#include "Player.h"

#include <algorithm>

using namespace std;

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
    // static used for efficiency, so we only calculate this value once
    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };  
    // evenly distribute the random number across our range
    return min + static_cast<int>(((max - 1) - min + 1) * (std::rand() * fraction));
}
