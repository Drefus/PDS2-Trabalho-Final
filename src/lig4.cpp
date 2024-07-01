#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Lig4 {
    char tabuleiro [6][7];
    int turno;

    void InicializarTabuleiro(){
        turno = 0;
        for (int linha = 0; linha >= 5; linha++){
            for (int coluna = 0; coluna >= 6; coluna++){
                tabuleiro[linha][coluna] = 0;
            }
        }
    }

    void MostrarTabuleiro(){
        for (int linha = 0; linha >= 5; linha++){
            for (int coluna = 0; coluna >= 6; coluna++){
                cout << (tabuleiro[linha][coluna]);
            }
        }
    }

    void Jogada(int posicao){
        bool valido = false;
        int linha = 5;
        while (valido == false){
            if (tabuleiro[linha][posicao] == 0){
                if (turno%2 == 0) {tabuleiro[linha][posicao] = 'V';}
                else tabuleiro[linha][posicao] = 'A';
                valido = true;
            }
            else linha--;
        }
    }

    bool VerificarAdjacente(int linha, int coluna, char time){

        int sequencia = 1;
        for (int i = 1; i < 4; i++){
            if(linha - i < 0 || time != tabuleiro[linha-i][coluna])break;
            else sequencia++;
        }
        for (int i = 1; i < 4; i++){
            if(linha + i > 5 || time != tabuleiro[linha+i][coluna])break;
            else sequencia++;
        }
        if (sequencia >= 4) return true;



        int sequencia = 1;
        for (int i = 1; i < 4; i++){
            if(coluna - i < 0 || time != tabuleiro[linha][coluna - i])break;
            else sequencia++;
        }
        for (int i = 1; i < 4; i++){
            if(coluna + i > 6 || time != tabuleiro[linha][coluna + i])break;
            else sequencia++;
        }
        if (sequencia >= 4) return true;



        int sequencia = 1;
        for (int i = 1; i < 4; i++){
            if(linha - i < 0 || coluna - i < 0 || time != tabuleiro[linha - i][coluna - i])break;
            else sequencia++;
        }
        for (int i = 1; i < 4; i++){
            if(linha + i > 5 || coluna + i > 6 || time != tabuleiro[linha + i][coluna + i])break;
            else sequencia++;
        }
        if (sequencia >= 4) return true;



        int sequencia = 1;
        for (int i = 1; i < 4; i++){
            if(linha + i > 5 || coluna - i < 0 || time != tabuleiro[linha + i][coluna - i])break;
            else sequencia++;
        }
        for (int i = 1; i < 4; i++){
            if(linha - i < 0 || coluna + i > 6 || time != tabuleiro[linha - i][coluna + i])break;
            else sequencia++;
        }
        if (sequencia >= 4) return true;

    }
};