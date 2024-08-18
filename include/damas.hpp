#ifndef DAMA_HPP
#define DAMA_HPP
#include <string>
#include <vector>
#include <game.hpp>
using namespace std;
class damas : public game
{
public:
    damas();

    void comer_multiplas(int linha_final, int coluna_final);

    void imprimir_tabuleiro();

    bool jogada_valida_O(char jogada1, char jogada2, char jogada3, char jogada4);

    bool jogada_valida_X(char jogada1, char jogada2, char jogada3, char jogada4);

    void mover_damas_X(char jogada1, char jogada2, char jogada3, char jogada4);

    void mover_damas_XX(int jogada1, int jogada2, int jogada3, int jogada4);

    void mover_damas_O(char jogada1, char jogada2, char jogada3, char jogada4);

    void mover_damas_OO(int jogada1, int jogada2, int jogada3, int jogada4);

    void comer_multiplas_damas(int a, int b);

    void realizar_movimento_O(char jogada1, char jogada2, char jogada3, char jogada4);

    bool e_dama(char jogada1, char jogada2);

    void realizar_movimento_X(char jogada1, char jogada2, char jogada3, char jogada4);

    bool jogada_valida_dama_O(char jogada1, char jogada2, char jogada3, char jogada4);

    bool jogada_valida_dama_X(char jogada1, char jogada2, char jogada3, char jogada4);

    bool jogada_valida_dama_XX(int jogada1, int jogada2, int jogada3, int jogada4);

    bool jogada_valida_dama_OO(int jogada1, int jogada2, int jogada3, int jogada4);

    int transcrever_movimento(char jogada1);

    char resultado_final();

    int jogar();
};
#endif