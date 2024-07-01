#include <game.hpp>

/// @brief Initiate game class
/// @param _rows
/// @param _cols
game::game(int _rows, int _cols) : rows(_rows), cols(_cols)
{
    tabuleiro.resize(rows, std::vector<char>(cols, ' '));
}
game::~game()
{
}

void game::changeElement(int x, int y, char element)
{
}

void game::winAndLose(std::string winner, std::string loser)
{
    this->management.addWin(this->name, winner);
    this->management.addLose(this->name, loser);
}
