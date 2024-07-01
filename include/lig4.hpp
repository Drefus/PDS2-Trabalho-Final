#ifndef Lig4_H
#define Lig4_H

#include <fstream>
#include <iostream>
#include <vector>
#include <game.hpp>

using namespace std;

class Lig4 : public game
{
    char tabuleiro[6][7];
    int turno;

    void InicializarTabuleiro() {}

    void MostrarTabuleiro() {}

    void Jogada(int posicao) {}

    bool VerificarAdjacente(int linha, int coluna, char time) {}
};

#endif