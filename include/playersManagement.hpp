#ifndef PLAYER_MANAGEMENT_H
#define PLAYER_MANAGEMENT_H
#include <vector>
#include "player.hpp"

class playersManagement
{
private:
    std::vector<player> players;
public:
    playersManagement();
    ~playersManagement();
    void loadData();
    void saveData();
    int addPlayer(std::string name,std::string nickname);
    std::string listPlayers();
    int addLose(std::string game,std::string nickname);
    int addWin(std::string game,std::string nickname);
};


#endif