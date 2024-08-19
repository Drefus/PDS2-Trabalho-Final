#include "player.hpp"
#include "stringUtils.hpp"
#include <string>
#include <vector>
#include <gameStatus.hpp>
#include <player.hpp>
#include <iostream>
/// @brief Crie a classe do jogador com base na linha do jogador.
/// @param playerLine
player::player(std::string playerLine)
{
    std::vector<std::string> infos = stringUtils::split(playerLine, ';');
    for (auto it : infos)
    {
        std::vector<std::string> data = stringUtils::splitInTwo(it, ':');
        if (data[0] == "name")
        {
            this->name = data[1];
            continue;
        }
        if (data[0] == "nickname")
        {
            this->nickname = data[1];
            continue;
        }
        std::vector<std::string> statics = stringUtils::splitInTwo(data[1], ',');
        this->gameStatics.push_back(gameStatus(data[0], std::stoi(statics[0]), std::stoi(statics[1])));
    }
}
/// @brief Crie um jogador baseado no nome e apelido;
/// @param name
/// @param nickname
player::player(std::string name, std::string nickname)
{
    this->name = name;
    this->nickname = nickname;
    std::vector<gameStatus> temp;
}
/// @brief Deconstructor
player::~player()
{
}
/// @brief Player to string;
/// @return Stringify the player data.
std::string player::playerToString()
{
    std::string gameStaticsString = "name:" + this->name + ";" + "nickname:" + this->nickname + ";";
    for (auto it : this->gameStatics)
    {
        gameStaticsString += it.getName() + ":" + it.winsAndLoses() + ";";
    }
    return gameStaticsString;
}
/// @brief Get Name
/// @return Player name
std::string player::getName()
{
    return this->name;
}
/// @brief Get Nick
/// @return Player nickname.
std::string player::getNick()
{
    return this->nickname;
}
/// @brief Get Game Statics
/// @return Getter of the player game statics.
std::vector<gameStatus> player::getGameStatics()
{
    return this->gameStatics;
}
/// @brief Setter game statics
/// @param newVector
void player::setGameStatics(std::vector<gameStatus> newVector)
{
    this->gameStatics = newVector;
}
