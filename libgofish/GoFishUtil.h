#ifndef GOFISH_UTIL_H
#define GOFISH_UTIL_H

#include <vector>

class IPlayer;

class GoFishUtil {
private:

public:
    static std::vector<IPlayer*> removePlayer(const std::vector<IPlayer*>& players, IPlayer* player);
    static int getRandomNumber(int min, int max) ;
};

#endif