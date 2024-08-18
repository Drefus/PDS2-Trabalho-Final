#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP
#include <game.hpp>

class jogoDaVelha : public game
{
private:
    char marcadorAtual;
    int jogadorAtual;

public:
    jogoDaVelha();
    void drawTabuleiro();
    bool marcador(int coord);
    int winner();
    void mudaJogador();
    void escolherMarcador();
};

#endif
