#ifndef PLAYER_MANAGEMENT_H
#define PLAYER_MANAGEMENT_H
#include <vector>
#include "player.hpp"
/// @brief Gerenciamento de Jogadores
class playersManagement
{
private:
    std::vector<player> players;

public:
    playersManagement();
    ~playersManagement();
    /// @brief Carregar dados
    void loadData();
    /// @brief Salvar dados
    void saveData();
    /// @brief Adicionar jogador
    /// @param name
    /// @param nickname
    /// @return Retorne 0 se for bem-sucedido e -1 se falhar.
    int addPlayer(std::string name, std::string nickname);
    /// @brief Remover jogador
    /// @param name
    /// @return Retorne 0 se for bem-sucedido e -1 se falhar.
    int removePlayer(std::string name);
    /// @brief Listar todos os jogadores
    void listPlayers();
    /// @brief Listar jogador a partir do nome
    /// @param name
    void listPlayers(std::string name);
    /// @brief Adicionar derrota a um jogador
    /// @param game
    /// @param nickname
    /// @return Se o jogo já existir retorne 0, se não crie e retorne 1.
    int addLose(std::string game, std::string nickname);
    /// @brief Adiciona vitoria a um jogador
    /// @param game
    /// @param nickname
    /// @return Se o jogo já existir retorne 0, se não crie e retorne 1.
    int addWin(std::string game, std::string nickname);
    /// @brief Verifica se um jogador existe a partir
    /// @param nick
    /// @return Se existir, retorne 1, se não, retorne -1
    int existPlayer(std::string nick);
};

#endif