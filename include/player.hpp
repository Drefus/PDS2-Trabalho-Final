#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "gameStatus.hpp"

class player
{
private:
    std::string name;
    std::string nickname;
    std::vector<gameStatus> gameStatics;
public:
    player(std::string playerLine);
    player(std::string name,std::string nickname);
    ~player();
    void printPlayer();
    void globalWinRate();
    void win();
    void lose();
    std::string playerToString();
    std::string getName();
    std::string getNick();
};


#endif