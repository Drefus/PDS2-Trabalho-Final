#include "player.hpp"
#include "stringUtils.hpp"
#include <string>
#include <vector>
#include <gameStatus.hpp>
#include <player.hpp>
#include <iostream>

player::player(std::string playerLine)
{
    std::vector<std::string> infos =  stringUtils::split(playerLine,';');
    for(auto it : infos){
      std::vector<std::string> data = stringUtils::splitInTwo(it,':');
        if(data[0] == "name"){
            this->name = data[1];
            continue;
        }
        if(data[0] == "nickname"){
            this->nickname = data[1];
            continue;
        }
       std::vector<std::string> statics =  stringUtils::splitInTwo(data[1],',');
       this->gameStatics.push_back(gameStatus(data[0],std::stoi(statics[0]),std::stoi(statics[1])));
    }

}

player::player(std::string name, std::string nickname)
{
    this->name = name;
    this->nickname = nickname;
    std::vector<gameStatus> temp;
}

player::~player()
{
}

void player::printPlayer()
{
}

void player::globalWinRate()
{
}

void player::win()
{
}

void player::lose()
{
}

std::string player::playerToString()
{
    std::string gameStaticsString = "name:" + this->name + ";" + "nickname:" + this->nickname + ";";
    for(auto it:this->gameStatics){
        gameStaticsString += it.getName() + ":" + it.winsAndLoses() + ";";
    }
    return gameStaticsString;
}

std::string player::getName()
{
    return this->name;
}

std::string player::getNick()
{
    return this->nickname;
}

std::vector<gameStatus> player::getGameStatics()
{
    return this->gameStatics;
}

void player::setGameStatics(std::vector<gameStatus> newVector)
{
    this->gameStatics = newVector;
}
