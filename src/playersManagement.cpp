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
        std::cout << "Erro ao ler o arquivo" << '\n';
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
            return -1;
        }
        if(it.getNick() == nickname){
            return -2;
        }
    }
    this->players.push_back(player(name,nickname));
    return 0;
}

std::string playersManagement::listPlayers()
{
    return std::string();
}
