#include <gameStatus.hpp>
#include <iostream>
#include <iomanip>
/// @brief Start the class with the name, wins and loses.
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
/// @brief Win Rate at this game
/// @return Calc the win rate of the player in this game.
double gameStatus::winRate()
{
    double media = static_cast<double>(this->wins) / (this->wins + this->loses);
    return media * 100;
}
/// @brief Lose Rate at this game
/// @return Calc the lose rate of the player in this game.
double gameStatus::loseRate()
{
    double media = static_cast<double>(this->loses) / (this->wins + this->loses);
    return media * 100;
}
/// @brief Show in the console the statics of the player in this game.
void gameStatus::gameStatics()
{
    std::cout << " " << this->name << " wins: %" << std::fixed << std::setprecision(2) << this->winRate() << '|' << std::to_string(this->wins) << " loses: %" << std::fixed << std::setprecision(2) << this->loseRate() << '|' << std::to_string(this->loses) << ";";
}
/// @brief Wins and Loses
/// @return Stringy the wins and the loses of the player and separe by a , .
std::string gameStatus::winsAndLoses()
{
    return std::to_string(this->wins) + "," + std::to_string(this->loses);
}
/// @brief get Name
/// @return name of the game.
std::string gameStatus::getName()
{
    return this->name;
}
/// @brief Add a win for the player in this game.
void gameStatus::addWin()
{
    this->wins++;
}
/// @brief Add a lose for the player in this game.
void gameStatus::addLose()
{
    this->loses++;
}
