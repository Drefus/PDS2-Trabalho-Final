#ifndef Lig4_H
#define Lig4_H

#include <fstream>
#include <iostream>
#include <vector>
#include <game.hpp>

using namespace std;

class lig4 : public game
{
private:
    int turno;

public:
    lig4();

    void mostrarTabuleiro();

    void jogada(int posicao);

    bool verificarAdjacente(int linha, int coluna, char time);
};

#endif