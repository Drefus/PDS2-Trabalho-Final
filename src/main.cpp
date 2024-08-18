#include <iostream>
#include <stdlib.h>
#include <string>
#include "playersManagement.hpp"
#include <playersMenu.hpp>
#include <lig4.hpp>
#include <reversi.hpp>
#include "damas.hpp"
#include <jogodavelha.hpp>
int main()
{
    bool isLoop = true;

    while (isLoop)
    {
        std::cout << "╔═══════════════════════════════╗" << std::endl;
        std::cout << "║             Menu              ║" << std::endl;
        std::cout << "╠═══════════════════════════════╣" << std::endl;
        std::cout << "║ 1. Gerenciamento de jogadores ║" << std::endl;
        std::cout << "║ 2. Ligue 4                    ║" << std::endl;
        std::cout << "║ 3. Reversi                    ║" << std::endl;
        std::cout << "║ 4. Damas                      ║" << std::endl;
        std::cout << "║ 5. Jogo da velha              ║" << std::endl;
        std::cout << "║ E. Sair                       ║" << std::endl;
        std::cout << "╚═══════════════════════════════╝" << std::endl;
        char input;
        std::cin >> input;
        switch (input)
        {
        case '1':
        {
            playersMenu();
            break;
        }
        case '2':
        {
            lig4();
            break;
        }
        case '3':
        {
            reversi();
            break;
        }
        case '4':
        {
            damas jogo;
            jogo.jogar();
            break;
        }
        case '5':
        {
            jogodavelha();
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