#ifndef GAME_HPP
#define GAME_HPP
#include<string>
#include<vector>
class game
{
private:
    int rows;
    int cols;
    std::vector<std::vector<char>> tabuleiro;
public:
    game(int _x,int _y);
    ~game();
    virtual void changeElement(int x,int y,char element);


    
};

#endif