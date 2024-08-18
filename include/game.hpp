#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <vector>
#include "playersManagement.hpp"

/// @brief Abstract class game
class game
{
protected:
    std::string name;
    int rows;
    int cols;
    std::vector<std::vector<char>> tabuleiro;
    playersManagement management;

public:
    /// @brief Construtor da game
    /// @param _rows
    /// @param _cols
    game(int _rows, int _cols);
    /// @brief Destrutor da game
    ~game();
    /// @brief Troca o elemento na posicao x,y para element
    /// @param x
    /// @param y
    /// @param element
    virtual void changeElement(int x, int y, char element);
    virtual void winAndLose(std::string winner, std::string loser);
};

#endif