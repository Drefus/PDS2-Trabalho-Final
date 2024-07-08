#include <iostream>
#include "jogodavelha.hpp"

using namespace std;

char tabuleiro[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char marcadorAtual;
int jogadorAtual;

void drawTabuleiro() {
    cout << " " << tabuleiro[0][0] << " | " << tabuleiro[0][1] << " | " << tabuleiro[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << tabuleiro[1][0] << " | " << tabuleiro[1][1] << " | " << tabuleiro[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << tabuleiro[2][0] << " | " << tabuleiro[2][1] << " | " << tabuleiro[2][2] << endl;
}

bool marcador(int coord){
    int fileira = (coord - 1) / 3;
    int coluna = (coord - 1) % 3;

    if (tabuleiro[fileira][coluna] != 'X' && tabuleiro[fileira][coluna] != 'O'){
        tabuleiro[fileira][coluna] = marcadorAtual;
        return true;
    }
    else 
        return false;
}

int winner(){

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == marcadorAtual && tabuleiro[i][1] == marcadorAtual && tabuleiro[i][2] == marcadorAtual)
            return jogadorAtual;
    }

    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == marcadorAtual && tabuleiro[1][j] == marcadorAtual && tabuleiro[2][j] == marcadorAtual)
            return jogadorAtual;
    }

    if (tabuleiro[0][0] == marcadorAtual && tabuleiro[1][1] == marcadorAtual && tabuleiro[2][2] == marcadorAtual)
        return jogadorAtual;
    if (tabuleiro[0][2] == marcadorAtual && tabuleiro[1][1] == marcadorAtual && tabuleiro[2][0] == marcadorAtual)
        return jogadorAtual;

    return 0;
}

void mudaJogador(){
    if (marcadorAtual == 'X')
        marcadorAtual = 'O';
    else
        marcadorAtual = 'X';

    if (jogadorAtual == 1)
        jogadorAtual = 2;
    else
        jogadorAtual = 1;
}

void game(){
    cout << "Jogador 1, escolha o marcador X ou O: ";
    char marcador1;
    cin >> marcador1;
    jogadorAtual = 1;
    marcadorAtual = marcador1;

    drawTabuleiro();

    for (int g = 0; g < 9; g++){
        cout << "Jogador " << jogadorAtual << ", faça sua jogada: ";
        int coord;
        cin >> coord;

        if (coord < 1 || coord > 9) {
            cout << "Movimento Inválido." << endl;
            g--;
            continue;
        }

        if (!marcador(coord)) {
            cout << "Espaço já ocupado." << endl;
            g--;
            continue;
        }

        drawTabuleiro();

        int vencedor = winner();
        if (vencedor == 1) {
            cout << "Jogador 1 foi o Vencedor!" << endl;
            break;
        }

        if (vencedor == 2) {
            cout << "Jogador 2 foi o Vencedor!" << endl;
            break;
        }

        if (g == 8) {
            cout << "Deu velha! Ninguém venceu." << endl;
        }

        mudaJogador();
    }
}