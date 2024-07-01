#include "playersManagement.hpp"
#include <string>
#include<fstream>
#include <iostream>

playersManagement::playersManagement()
{
    this->loadData();
}

playersManagement::~playersManagement()
{
}

void playersManagement::loadData()
{
    try
    {
        std::ifstream in("./data/playersStatics.txt", std::fstream::in);
        std::string playerLine;
        while(std::getline(in,playerLine)){
        this->players.push_back(player(playerLine));
        }
        in.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "ERRO: Arquivo corrompido" << '\n';
    }
    
}

void playersManagement::saveData()
{
    std::ofstream out("./data/playersStatics.txt", std::fstream::out);
    for(auto it : this->players){
        out << it.playerToString() << std::endl;
    }
    out.close();
}

int playersManagement::addPlayer(std::string name, std::string nickname)
{
    for(auto it : this->players){
        if(it.getName() == name){
            std::cout << "ERRO : nome de jogador ja esta em uso." << std::endl;
            return -1;
        }
        if(it.getNick() == nickname){
             std::cout << "ERRO : nickname de jogador ja esta em uso." << std::endl;
            return -2;
        }
    }
    this->players.push_back(player(name,nickname));
    this->saveData();
    return 0;
}

std::string playersManagement::listPlayers()
{
    return std::string();
}

int playersManagement::addLose(std::string game, std::string nickname)
{
    for(auto &it : this->players){
        if(it.getNick() == nickname){
            std::vector<gameStatus> temp = it.getGameStatics();
            for (auto &gameStatus:temp)
            {
                if(gameStatus.getName() == game){
                    gameStatus.addLose();
                    it.setGameStatics(temp);
                    this->saveData();
                    return 0;
                }
            }
            temp.push_back(gameStatus(game,0,1));
            it.setGameStatics(temp);
            this->saveData();
            return 1;
        }
    }
    std::cout << "ERRO: Não foi encontrado nenhum jogador com esse nickname." << std::endl;
    return -1;
}

int playersManagement::addWin(std::string game, std::string nickname)
{
     for(auto &it : this->players){
        if(it.getNick() == nickname){
            std::vector<gameStatus> temp = it.getGameStatics();
            for (auto &gameStatus:temp)
            {
                if(gameStatus.getName() == game){
                    gameStatus.addWin();
                    it.setGameStatics(temp);
                    this->saveData();
                    return 0;
                }
            }
            temp.push_back(gameStatus(game,1,0));
            it.setGameStatics(temp);
            this->saveData();
            return 1;
        }
    }
    std::cout << "ERRO: Não foi encontrado nenhum jogador com esse nickname." << std::endl;
    return -1;
}
