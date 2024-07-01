#include <iostream>
#include <stdlib.h>
#include <string>
#include "playersManagement.hpp"
#include <playersMenu.hpp>

int main(){
    bool isLoop = true;
        std::cout << "------------------------------" << std::endl;
        std::cout << "-----------Menu---------------" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "Opções" << std::endl;
        std::cout << "1. Cadastrar Usuário" << std::endl;
        std::cout << "E. Sair" << std::endl;
    while (isLoop)
    {
        char input;
        std::cin >> input;
        switch (input)
        {
        case '1':{
            playersMenu();
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