#ifndef GOFISH_UTIL_H
#define GOFISH_UTIL_H

#include <vector>

class IPlayer;
class Card;

class GoFishUtil {
private:

public:
    std::vector<IPlayer*> removePlayer(const std::vector<IPlayer*>& players, IPlayer* player);
    int getRandomNumber(int min, int max) const;
};

#endif