#include <game.hpp>
#include <iostream>

/// @brief Inicializa a classe game
/// @param _rows
/// @param _cols
game::game(int _rows, int _cols, std::string _name) : rows(_rows), cols(_cols), name(_name)
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

void game::loadPlayers()
{
    do
    {
        std::cout << "Digite o apelido do jogador 1:" << std::endl;

        while (std::getline(std::cin, jogador1))
            if (jogador1 != "")
            {
                break;
            }
        if (management.existPlayer(jogador1) == 1)
        {
            break;
        }
    } while (true);

    do
    {
        std::cout << "Digite o apelido do jogador 2:" << std::endl;

        while (std::getline(std::cin, jogador2))
            if (jogador2 != "")
            {
                break;
            }
        if (management.existPlayer(jogador2) == 1)
        {
            break;
        }
    } while (true);
}
