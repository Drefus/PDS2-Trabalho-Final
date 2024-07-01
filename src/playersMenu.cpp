#include "playersMenu.hpp"
#include <iostream>
#include <fstream>

playersMenu::playersMenu()
{
    bool isLoop = true;

    while (isLoop)
    {
        std::cout << "╔════════════════════════════════╗" << std::endl;
        std::cout << "║       Menu de Jogadores        ║" << std::endl;
        std::cout << "╠════════════════════════════════╣" << std::endl;
        std::cout << "║ 1. Adicionar Jogador           ║" << std::endl;
        std::cout << "║ 2. Remover Jogador             ║" << std::endl;
        std::cout << "║ 3. Ver estatísticas de jogador ║" << std::endl;
        std::cout << "║ 4. Ver todas as estatísticas   ║" << std::endl;
        std::cout << "║ E. Sair                        ║" << std::endl;
        std::cout << "╚════════════════════════════════╝" << std::endl;
        char input;
        std::cin >> input;
        switch (input)
        {
        case '1':
        {
            std::string name, nick;
            std::cout << "Digite o nome do jogador:" << std::endl;
            std::cin >> name;
            std::cout << "Digite o apelido do jogador:" << std::endl;
            std::cin >> nick;
            this->management.addPlayer(name, nick);
            std::cout << "Jogador adicionado com sucesso" << std::endl;
            break;
        }
        case '2':
        {
            std::string name;
            std::cout << "Digite o nome ou apelido do jogador:" << std::endl;
            std::cin >> name;
            this->management.removePlayer(name);
            break;
        }
        case '3':
        {
            std::string name;
            std::cout << "Digite o nome ou apelido do jogador:" << std::endl;
            std::cin >> name;
            this->management.listPlayers(name);
            break;
        }
        case '4':
        {
            this->management.listPlayers();
            break;
        }
        case 'E':
        {
            isLoop = false;
            break;
        }
        default:
            std::cout << "Opção Invalida" << std::endl;
        }
    }
};

playersMenu::~playersMenu(){};
