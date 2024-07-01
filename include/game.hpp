#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <vector>
#include "playersManagement.hpp"
class game
{
private:
    std::string name;
    int rows;
    int cols;
    std::vector<std::vector<char>> tabuleiro;
    playersManagement management;

public:
    game(int _x, int _y);
    ~game();
    virtual void changeElement(int x, int y, char element);
    virtual void winAndLose(std::string winner, std::string loser);
};

#endif