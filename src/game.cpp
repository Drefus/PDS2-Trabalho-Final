#include <game.hpp>

/// @brief Initiate game class
/// @param _rows
/// @param _cols
game::game(int _rows, int _cols) : rows(_rows), cols(_cols)
{
    tabuleiro.resize(rows, std::vector<char>(cols, ' '));
}
/// @brief Destructor
game::~game()
{
}
/// @brief Change the element in position x,y to the element;
/// @param x
/// @param y
/// @param element
void game::changeElement(int x, int y, char element)
{
}
/// @brief Add one win to the winner and one lose for the loser
/// @param winner
/// @param loser
void game::winAndLose(std::string winner, std::string loser)
{
    this->management.addWin(this->name, winner);
    this->management.addLose(this->name, loser);
}
