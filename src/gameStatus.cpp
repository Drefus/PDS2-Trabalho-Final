#include <gameStatus.hpp>
#include <iostream>
#include <iomanip>
/// @brief Comece a classe com o nome, ganha e perde.
/// @param _name
/// @param _wins
/// @param _loses
gameStatus::gameStatus(std::string _name, int _wins, int _loses) : name(_name), wins(_wins), loses(_loses)
{
}
/// @brief Destructor
gameStatus::~gameStatus()
{
}
/// @brief Taxa de vitórias neste jogo
/// @return Calcule a taxa de vitória do jogador neste jogo.
double gameStatus::winRate()
{
    double media = static_cast<double>(this->wins) / (this->wins + this->loses);
    return media * 100;
}
/// @brief Taxa de perda neste jogo
/// @return Calcule a taxa de perdas do jogador neste jogo.
double gameStatus::loseRate()
{
    double media = static_cast<double>(this->loses) / (this->wins + this->loses);
    return media * 100;
}
/// @brief Mostre no console a estática do jogador neste jogo.
void gameStatus::gameStatics()
{
    std::cout << " " << this->name << " wins: %" << std::fixed << std::setprecision(2) << this->winRate() << '|' << std::to_string(this->wins) << " loses: %" << std::fixed << std::setprecision(2) << this->loseRate() << '|' << std::to_string(this->loses) << ";";
}
/// @brief Vitorias e derrotas
/// @return Stringy as vitórias e as derrotas do jogador e separadas por um , .
std::string gameStatus::winsAndLoses()
{
    return std::to_string(this->wins) + "," + std::to_string(this->loses);
}
/// @brief get Name
/// @return Nome do jogo.
std::string gameStatus::getName()
{
    return this->name;
}
/// @brief Adicione uma vitória para o jogador neste jogo.
void gameStatus::addWin()
{
    this->wins++;
}
/// @brief Adicione uma perda para o jogador neste jogo.
void gameStatus::addLose()
{
    this->loses++;
}
