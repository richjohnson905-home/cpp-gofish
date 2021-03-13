#ifndef GOFISH_UTIL_H
#define GOFISH_UTIL_H

#include <vector>

class Player;
class Card;

class GoFishUtil {
public:
    std::vector<Player*> removePlayer(const std::vector<Player*>& players, Player* player);
    int getRandomNumber(int min, int max) const;

};

#endif