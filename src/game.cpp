#include <game.hpp>

/// @brief Inicializa a classe game
/// @param _rows
/// @param _cols
game::game(int _rows, int _cols) : rows(_rows), cols(_cols)
{
    tabuleiro.resize(rows, std::vector<char>(cols, ' '));
}
/// @brief Destrutor
game::~game()
{
}
/// @brief Mude o elemento na posição x,y para o elemento;
/// @param x
/// @param y
/// @param element
void game::changeElement(int x, int y, char element)
{
}
/// @brief Adicione uma vitória ao vencedor e uma derrota ao perdedor
/// @param winner
/// @param loser
void game::winAndLose(std::string winner, std::string loser)
{
    this->management.addWin(this->name, winner);
    this->management.addLose(this->name, loser);
}
