#ifndef REVERSI_H
#define REVERSI_H

#include <iostream>
#include <vector>
#include <game.hpp>

using namespace std;

/// @brief Classe do jogo reverse
class reversi : public game
{
private:
    int turno;

public:
    reversi();

    void mostrarTabuleiro();

    bool jogada(int x, int y, char player);

    bool verificarAdjacente(int x, int y, char player);

    bool movimentoValido(int x, int y, char player);

    bool temMovimentosValidos(char player);

    int contarPecas(char player);
};

#endif
