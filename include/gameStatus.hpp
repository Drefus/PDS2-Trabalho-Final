#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include <string>

class gameStatus
{
private:
    std::string name;
    int wins;
    int loses;
public:
    gameStatus(std::string _name,int _wins,int _loses);
    ~gameStatus();
    double winRate();
    double loseRate();
    std::string gameStatics();
    std::string winsAndLoses();
    std::string getName();
};

#endif