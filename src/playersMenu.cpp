#include "playersMenu.hpp"
#include <iostream>
#include <fstream>

playersMenu::playersMenu()
{
    bool isLoop = true;
    std::cout << "------------------------------" << std::endl;
    std::cout << "-----------Menu---------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Opções" << std::endl;
    std::cout << "1. Adicionar Jogador" << std::endl;
    std::cout << "2. Remover Jogador" << std::endl;
    std::cout << "3. Ver estatísticas de jogador" << std::endl;
    std::cout << "4. Ver todas as estatísticas" << std::endl;
    std::cout << "E. Sair" << std::endl;
    while (isLoop)
    {
        char input;
        std::cin >> input;
        switch (input)
        {
        case '1':
        {
            int loop;
            std::string name, nick;
            do
            {
                std::cout << "Digite o nome do jogador:" << std::endl;
                std::cin >> name;
                std::cout << "Digite o apelido do jogador:" << std::endl;
                std::cin >> nick;
                loop = this->management.addPlayer(name, nick);
            } while (loop != 0);
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
            isLoop = false;
            break;
        default:
            std::cout << "Opção Invalida" << std::endl;
        }
    }
};

playersMenu::~playersMenu(){};
