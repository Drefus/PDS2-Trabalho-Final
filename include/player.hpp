#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "gameStatus.hpp"

/// @brief Classe jogador
class player
{
private:
    std::string name;
    std::string nickname;
    std::vector<gameStatus> gameStatics;

public:
    player(std::string playerLine);
    player(std::string name, std::string nickname);
    ~player();
    std::string playerToString();
    std::string getName();
    std::string getNick();
    std::vector<gameStatus> getGameStatics();
    void setGameStatics(std::vector<gameStatus> newVector);
};

#endif