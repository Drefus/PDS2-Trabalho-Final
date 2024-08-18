#include "playersManagement.hpp"
#include <string>
#include <fstream>
#include <iostream>
/// @brief Construtor e dados de carregamento
playersManagement::playersManagement()
{
    this->loadData();
}
/// @brief Destructor
playersManagement::~playersManagement()
{
}
/// @brief Carregue os dados do jogador de playersStatics.txt
void playersManagement::loadData()
{
    try
    {
        this->players.clear();
        std::ifstream in("./data/playersStatics.txt", std::fstream::in);
        std::string playerLine;
        while (std::getline(in, playerLine))
        {
            this->players.push_back(player(playerLine));
        }
        in.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "ERRO: Arquivo corrompido" << '\n';
    }
}
/// @brief Salve os dados dos jogadores em playersStatics.txt
void playersManagement::saveData()
{
    std::ofstream out("./data/playersStatics.txt", std::fstream::out);
    for (auto it : this->players)
    {
        out << it.playerToString() << std::endl;
    }
    out.close();
}
/// @brief Adicione um jogador pelo nome ou apelido.
/// @param name
/// @param nickname
/// @return Retorne 0 se for bem-sucedido e -1 se falhar.
int playersManagement::addPlayer(std::string name, std::string nickname)
{
    for (auto it : this->players)
    {
        if (it.getName() == name)
        {
            std::cout << "ERRO : nome de jogador ja esta em uso." << std::endl;
            return -1;
        }
        if (it.getNick() == nickname)
        {
            std::cout << "ERRO : nickname de jogador ja esta em uso." << std::endl;
            return -2;
        }
    }
    this->players.push_back(player(name, nickname));
    this->saveData();
    return 0;
}
/// @brief Remova um jogador pelo nome ou apelido.
/// @param name
/// @return Retorne 0 se for bem-sucedido e -1 se falhar.
int playersManagement::removePlayer(std::string name)
{
    int index = 0;
    for (auto &it : this->players)
    {
        if (name == it.getName() || name == it.getNick())
        {
            this->players.erase(this->players.begin() + index);
            std::cout << "Jogador removido com sucesso." << std::endl;
            this->saveData();
            return 0;
        }
        index++;
    }
    std::cout << "ERRO: Não foi encontrado nenhum jogador com esse nome ou nickname." << std::endl;
    return -1;
}
/// @brief Liste todos os jogadores e suas estatísticas
void playersManagement::listPlayers()
{
    for (auto it : this->players)
    {
        std::cout << it.getNick() << ":";
        for (auto game : it.getGameStatics())
        {
            game.gameStatics();
        }
        std::cout << std::endl;
    }
}
/// @brief Liste o jogador pelo nome ou apelido e suas estatísticas.
/// @param name
void playersManagement::listPlayers(std::string name)
{
    for (auto it : this->players)
    {
        if (name == it.getName() || name == it.getNick())
        {
            std::cout << it.getNick() << ":" << std::endl;
            for (auto game : it.getGameStatics())
            {
                game.gameStatics();
            }
        }
    }
}
/// @brief Adicione uma perda no jogo para o jogador que o nick passou
/// @param game
/// @param nickname
/// @return Se o jogo já existir retorne 0, se não crie e retorne 1.
int playersManagement::addLose(std::string game, std::string nickname)
{
    for (auto &it : this->players)
    {
        if (it.getNick() == nickname)
        {
            std::vector<gameStatus> temp = it.getGameStatics();
            for (auto &gameStatus : temp)
            {
                if (gameStatus.getName() == game)
                {
                    gameStatus.addLose();
                    it.setGameStatics(temp);
                    this->saveData();
                    return 0;
                }
            }
            temp.push_back(gameStatus(game, 0, 1));
            it.setGameStatics(temp);
            this->saveData();
            return 1;
        }
    }
    std::cout << "ERRO: Não foi encontrado nenhum jogador com esse nickname." << std::endl;
    return -1;
}
/// @brief Adicione uma vitória no jogo para o jogador que o nick passou
/// @param game
/// @param nickname
/// @return Se o jogo já existir retorne 0, se não crie e retorne 1.
int playersManagement::addWin(std::string game, std::string nickname)
{
    for (auto &it : this->players)
    {
        if (it.getNick() == nickname)
        {
            std::vector<gameStatus> temp = it.getGameStatics();
            for (auto &gameStatus : temp)
            {
                if (gameStatus.getName() == game)
                {
                    gameStatus.addWin();
                    it.setGameStatics(temp);
                    this->saveData();
                    return 0;
                }
            }
            temp.push_back(gameStatus(game, 1, 0));
            it.setGameStatics(temp);
            this->saveData();
            return 1;
        }
    }
    std::cout << "ERRO: Não foi encontrado nenhum jogador com esse nickname." << std::endl;
    return -1;
}

/// @brief Verifique se o nick do jogador existe nos jogadores
/// @param nick
/// @return se existir, retorne 1, se não, retorne -1
int playersManagement::existPlayer(std::string nick)
{
    for (auto it : this->players)
    {
        if (it.getNick() == nick)
        {
            return 1;
        }
    }
    std::cout << "ERRO: Não foi encontrado nenhum jogador com esse nickname." << std::endl;
    std::cout << "Deseja criar um jogador novo(y/n):" << std::endl;
    std::string entrada, nome, nickname;
    do
    {
        std::cin >> entrada;
        if (entrada == "y")
        {
            do
            {
                std::cout << "Digite o nome do jogador:" << std::endl;
                std::cin >> nome;
                std::cout << "Digite o nome do nick:" << std::endl;
                std::cin >> nickname;
                if (this->addPlayer(nome, nickname) == 0)
                {
                    break;
                }
            } while (true);
            return 2;
        }
        else if (entrada == "n")
        {
            return -1;
        }
    } while (true);
}
