#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include <string>

/// @brief game status classe
class gameStatus
{
private:
    std::string name;
    int wins;
    int loses;

public:
    /// @brief game status construtor
    /// @param _name
    /// @param _wins
    /// @param _loses
    gameStatus(std::string _name, int _wins, int _loses);
    /// @brief game status destructor
    ~gameStatus();
    /// @brief Calcula a taxa de vitoria
    /// @return A taxa de vitoria
    double winRate();
    /// @brief Calcula a taxa de derrota
    /// @return A taxa de derrota
    double loseRate();
    /// @brief Printa as estatísticas do jogo
    void gameStatics();
    /// @brief Cria uma string de vitorias e derrotas
    /// @return Retorna uma string de vitorias e derrotas
    std::string winsAndLoses();
    /// @brief Pega o nome de jogo
    /// @return Retorna o nome do jogo
    std::string getName();
    /// @brief Adiciona uma vitoria
    void addWin();
    /// @brief Adiciona uma derrota
    void addLose();
};

#endif