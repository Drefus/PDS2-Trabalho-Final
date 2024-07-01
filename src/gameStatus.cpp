#include <gameStatus.hpp>

gameStatus::gameStatus(std::string _name, int _wins, int _loses): name(_name), wins(_wins), loses(_loses) 
{
}

gameStatus::~gameStatus()
{
}

double gameStatus::winRate()
{
    return this->wins / (this->wins + this->loses);
}

double gameStatus::loseRate()
{
    return this->loses / (this->wins + this->loses);
}

std::string gameStatus::gameStatics()
{
    return this->name + " wins: %" + std::to_string(this->winRate()) + '|'+std::to_string(this->wins) + " loses: %" + std::to_string(this->loseRate()) + '|'+std::to_string(this->loses);
}

std::string gameStatus::winsAndLoses()
{
    return std::to_string(this->wins) + "," + std::to_string(this->loses);
}

std::string gameStatus::getName()
{
    return this->name;
}

void gameStatus::addWin()
{
    this->wins++;
}

void gameStatus::addLose()
{
    this->loses++;
}
