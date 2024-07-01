#include <gameStatus.hpp>
#include <iostream>
#include <iomanip>

gameStatus::gameStatus(std::string _name, int _wins, int _loses) : name(_name), wins(_wins), loses(_loses)
{
}

gameStatus::~gameStatus()
{
}

double gameStatus::winRate()
{
    double media = static_cast<double>(this->wins) / (this->wins + this->loses);
    return media * 100;
}

double gameStatus::loseRate()
{
    double media = static_cast<double>(this->loses) / (this->wins + this->loses);
    return media * 100;
}

void gameStatus::gameStatics()
{
    std::cout << this->name << " wins: %" << std::fixed << std::setprecision(2) << this->winRate() << '|' << std::to_string(this->wins) << " loses: %" << std::fixed << std::setprecision(2) << this->loseRate() << '|' << std::to_string(this->loses) << std::endl;
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
