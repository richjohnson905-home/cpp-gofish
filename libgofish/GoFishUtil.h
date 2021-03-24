#ifndef GOFISH_UTIL_H
#define GOFISH_UTIL_H

#include <vector>

class Player;
class Card;

class GoFishUtil {
private:
    bool m_verbose;
public:
    GoFishUtil(bool verbose);
    std::vector<Player*> removePlayer(const std::vector<Player*>& players, Player* player);
    int getRandomNumber(int min, int max) const;
    void printMsg(const std::string& msg);
    void printMsgEnd(const std::string& msg);
};

#endif