#include <iostream>
#include <vector>

using namespace std;

class Tabuleiro
{
private:
    int linhas;
    int colunas;
    vector<vector<char>> tabuleiro;

public:
    Tabuleiro(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
        tabuleiro.resize(linhas, vector<char>(colunas, ' '));
     for(int i = 0; i < 2; i++){
         for(int j = 0; j < colunas; j++){
             tabuleiro[i][j] = ' ';
         }
     }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < 2; j++){
            tabuleiro[i][j] = ' ';
        }
    }
    for(int i = 11; i < 13; i++){
        for(int j = 0; j < colunas; j++){
            tabuleiro[i][j] = ' ';
        }
    }
    for(int i = 0; i < linhas; i++){
        for(int j = 11; j < 13; j++){
            tabuleiro[i][j] = ' ';
        }
    }
        tabuleiro[2][2] = ' ';
        tabuleiro[2][3] = 'A';
        tabuleiro[2][4] = 'B';
        tabuleiro[2][5] = 'C';
        tabuleiro[2][6] = 'D';
        tabuleiro[2][7] = 'E';
        tabuleiro[2][8] = 'F';
        tabuleiro[2][9] = 'G';
        tabuleiro[2][10] = 'H';
        tabuleiro[3][2] = 'A';
        tabuleiro[4][2] = 'B';
        tabuleiro[5][2] = 'C';
        tabuleiro[6][2] = 'D';
        tabuleiro[7][2] = 'E';
        tabuleiro[8][2] = 'F';
        tabuleiro[9][2] = 'G';
        tabuleiro[10][2] = 'H';
        
        for (int i = 3; i < linhas -2; i++) {
            for (int j = 3; j < colunas - 2; j++) {
                if (i < 6) {
                    if ((i + j) % 2 != 0) {
                        tabuleiro[i][j] = 'X';
                    }
                } else if (i == 6 && (i + j) % 2 != 0) {
                    tabuleiro[i][j] = '#';
                }else if(i == 7 && (i + j) % 2 != 0){
                    tabuleiro[i][j] = '#';
                }else if(i > 7){
                    if((i + j) % 2 != 0){
                        tabuleiro[i][j] = 'O';
                    }
                }
            }
        }
        



        

    }
    void comer_multiplas(int linha_final, int coluna_final)
    {    
      loop:
            if(tabuleiro[linha_final][coluna_final] == 'O'){
                if(tabuleiro[linha_final + 1][coluna_final + 1] == 'X' && tabuleiro[linha_final +2][coluna_final + 2] == '#'){
                    tabuleiro[linha_final + 1][coluna_final + 1] = '#';
                    tabuleiro[linha_final + 2][coluna_final + 2] = 'O';
                    tabuleiro[linha_final][coluna_final] = '#';
                    linha_final = linha_final + 2;
                    coluna_final = coluna_final + 2;
                    goto loop;

                }else if (tabuleiro[linha_final + 1][coluna_final -1] == 'X' && tabuleiro[linha_final + 2][coluna_final - 2] == '#'){
                    tabuleiro[linha_final + 1][coluna_final - 1] = '#';
                    tabuleiro[linha_final + 2][coluna_final - 2] = 'O';
                    tabuleiro[linha_final][coluna_final] = '#';
                    linha_final = linha_final + 2;
                    coluna_final = coluna_final - 2;
                    goto loop;

                }else if(tabuleiro[linha_final - 1][coluna_final + 1] == 'X' && tabuleiro[linha_final - 2][coluna_final + 2] == '#'){
                    tabuleiro[linha_final - 1][coluna_final + 1] = '#';
                    tabuleiro[linha_final - 2][coluna_final + 2] = 'O';
                    tabuleiro[linha_final][coluna_final] = '#';
                    linha_final = linha_final - 2;
                    coluna_final = coluna_final + 2;
                    goto loop;

                }else if(tabuleiro[linha_final -1 ][coluna_final - 1] == 'X' && tabuleiro[linha_final - 2][coluna_final - 2] == '#'){
                    tabuleiro[linha_final - 1][coluna_final - 1] = '#';
                    tabuleiro[linha_final - 2][coluna_final - 2] = 'O';
                    tabuleiro[linha_final][coluna_final] = '#';
                    linha_final = linha_final - 2;
                    coluna_final = coluna_final - 2;
                    goto loop;

                }
            }else if(tabuleiro[linha_final][coluna_final] == 'X'){
                if(tabuleiro[linha_final + 1][coluna_final + 1] == 'O' && tabuleiro[linha_final +2][coluna_final + 2] == '#'){
                    tabuleiro[linha_final + 1][coluna_final + 1] = '#';
                    tabuleiro[linha_final + 2][coluna_final + 2] = 'X';
                    tabuleiro[linha_final][coluna_final] = '#';
                    linha_final = linha_final + 2;
                    coluna_final = coluna_final + 2;
                    goto loop;


                }else if(tabuleiro[linha_final + 1][coluna_final - 1] == 'O' && tabuleiro[linha_final + 2][coluna_final - 2] == '#'){
                    tabuleiro[linha_final + 1][coluna_final - 1] = '#';
                    tabuleiro[linha_final + 2][coluna_final - 2] = 'X';
                    tabuleiro[linha_final][coluna_final] = '#';
                    linha_final = linha_final + 2;
                    coluna_final = coluna_final - 2;                                                           goto loop;


                }else if(tabuleiro[linha_final - 1][coluna_final + 1] == 'O' && tabuleiro[linha_final - 2][coluna_final + 2] == '#'){
                    tabuleiro[linha_final - 1][coluna_final + 1] = '#';
                    tabuleiro[linha_final - 2][coluna_final + 2] = 'X';
                    tabuleiro[linha_final][coluna_final] = '#';
                    linha_final = linha_final - 2;
                    coluna_final = coluna_final + 2;                                                         goto loop;


                }else if(tabuleiro[linha_final - 1][coluna_final - 1] == 'O' && tabuleiro[linha_final - 2][coluna_final - 2] == '#'){
                    tabuleiro[linha_final - 1][coluna_final - 1] = '#';
                    tabuleiro[linha_final - 2][coluna_final - 2] = 'X';
                    tabuleiro[linha_final][coluna_final] = '#';
                    linha_final = linha_final - 2;
                    coluna_final = coluna_final - 2;                    
                    goto loop;


                }
            }
            if(linha_final == 10 && tabuleiro[linha_final][coluna_final] == 'X'){
                tabuleiro[linha_final][coluna_final] = '*';
            }else if(linha_final == 3 && tabuleiro[linha_final][coluna_final] == 'O'){
                tabuleiro[linha_final][coluna_final] = '@';
            }
        }




    void imprimir_tabuleiro(){
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cout << tabuleiro[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool jogada_valida_O(char jogada1, char jogada2, char jogada3, char jogada4){
int linha_inicial =transcrever_movimento(jogada1);
    int coluna_inicial =transcrever_movimento(jogada2);
    int linha_final = transcrever_movimento(jogada3);
    int coluna_final = transcrever_movimento(jogada4);
        
    if(tabuleiro[linha_inicial][coluna_inicial] != 'O') {
        cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
        return false;            
    }else if(tabuleiro[linha_final][coluna_final] == 'X' || tabuleiro[linha_final][coluna_final] == 'O'){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;    
    }else if(coluna_inicial == coluna_final){
        cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
        return false;
    }else if((coluna_final - coluna_inicial) > 2){
        cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
        return false;
    }else if((coluna_final - coluna_inicial) < -2){
        cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
        return false;
    }else if((linha_final - linha_inicial) > 2){
        cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
        return false;
    }else if((linha_final - linha_inicial) < -2){
        cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
        return false;
    }else if((linha_final - linha_inicial) == +1 && ((coluna_final - coluna_inicial) == -1 || (coluna_final - coluna_inicial) == +1)){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;
        }
return true;
}

    bool jogada_valida_X(char jogada1, char jogada2, char jogada3, char jogada4){
        int linha_inicial =transcrever_movimento(jogada1);
        int coluna_inicial =transcrever_movimento(jogada2);
        int linha_final = transcrever_movimento(jogada3);
        int coluna_final = transcrever_movimento(jogada4);
        if(tabuleiro[linha_inicial][coluna_inicial] != 'X'){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;            
        }else if(tabuleiro[linha_final][coluna_final] == 'X' || tabuleiro[linha_final][coluna_final] == 'O'){
                cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
                return false;    
        }else if(coluna_inicial == coluna_final){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;
        }else if((coluna_final - coluna_inicial) > 2){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;
        }else if((coluna_final - coluna_inicial) < -2){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;
        }else if((linha_final - linha_inicial) > 2){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;
        }else if((linha_final - linha_inicial) < -2){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;
        }else if((linha_final - linha_inicial) == -1 && ((coluna_final - coluna_inicial) == -1 || (coluna_final - coluna_inicial) == +1)){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;
        }else if(linha_final == linha_inicial + 1 && ((coluna_final - coluna_inicial) >= 2 || (coluna_final - coluna_inicial) <= -2)){
            cout <<endl<< "Movimento invalido, tente novamente!" <<endl<<endl;
            return false;

        }
    return true;
    }

void mover_damas_X(char jogada1, char jogada2, char jogada3, char jogada4) {
    int linha_inicial = transcrever_movimento(jogada1);
    int coluna_inicial = transcrever_movimento(jogada2);
    int linha_final = transcrever_movimento(jogada3);
    int coluna_final = transcrever_movimento(jogada4);

    
    tabuleiro[linha_inicial][coluna_inicial] = '#';
    tabuleiro[linha_final][coluna_final] = '*';

    
    int diff_linha = linha_inicial - linha_final;
    int diff_coluna = coluna_inicial - coluna_final;

    if (diff_linha > 0 && diff_coluna > 0) { 
        for (int i = 1; i <= diff_linha; i++) {
            int linha_atual = linha_inicial - i;
            int coluna_atual = coluna_inicial - i;
            if (tabuleiro[linha_atual][coluna_atual] == 'O') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha > 0 && diff_coluna < 0) { 
        for (int i = 1; i <= diff_linha; i++) {
            int linha_atual = linha_inicial - i;
            int coluna_atual = coluna_inicial + i;
            if (tabuleiro[linha_atual][coluna_atual] == 'O') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha < 0 && diff_coluna < 0) { 
        for (int i = 1; i <= -diff_linha; i++) {
            int linha_atual = linha_inicial + i;
            int coluna_atual = coluna_inicial + i;
            if (tabuleiro[linha_atual][coluna_atual] == 'O') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha < 0 && diff_coluna > 0) { 
        for (int i = 1; i <= -diff_linha; i++) {
            int linha_atual = linha_inicial + i;
            int coluna_atual = coluna_inicial - i;
            if (tabuleiro[linha_atual][coluna_atual] == 'O') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    }
}

void mover_damas_XX(int jogada1, int jogada2, int jogada3, int jogada4) {
    int linha_inicial = jogada1;
    int coluna_inicial = jogada2;
    int linha_final = jogada3;
    int coluna_final = jogada4;

    tabuleiro[linha_inicial][coluna_inicial] = '#';
    tabuleiro[linha_final][coluna_final] = '*';

    int diff_linha = linha_inicial - linha_final;
    int diff_coluna = coluna_inicial - coluna_final;

    if (diff_linha > 0 && diff_coluna > 0) { 
        for (int i = 1; i <= diff_linha; i++) {
            int linha_atual = linha_inicial - i;
            int coluna_atual = coluna_inicial - i;
            if (tabuleiro[linha_atual][coluna_atual] == 'O') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha > 0 && diff_coluna < 0) { 
        for (int i = 1; i <= diff_linha; i++) {
            int linha_atual = linha_inicial - i;
            int coluna_atual = coluna_inicial + i;
            if (tabuleiro[linha_atual][coluna_atual] == 'O') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha < 0 && diff_coluna < 0) { 
        for (int i = 1; i <= -diff_linha; i++) {
            int linha_atual = linha_inicial + i;
            int coluna_atual = coluna_inicial + i;
            if (tabuleiro[linha_atual][coluna_atual] == 'O') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha < 0 && diff_coluna > 0) { 
        for (int i = 1; i <= -diff_linha; i++) {
            int linha_atual = linha_inicial + i;
            int coluna_atual = coluna_inicial - i;
            if (tabuleiro[linha_atual][coluna_atual] == 'O') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    }
}



void mover_damas_O(char jogada1, char jogada2, char jogada3, char jogada4) {
    int linha_inicial = transcrever_movimento(jogada1);
    int coluna_inicial = transcrever_movimento(jogada2);
    int linha_final = transcrever_movimento(jogada3);
    int coluna_final = transcrever_movimento(jogada4);

    tabuleiro[linha_inicial][coluna_inicial] = '#';
    tabuleiro[linha_final][coluna_final] = '@';


    int diff_linha = linha_inicial - linha_final;
    int diff_coluna = coluna_inicial - coluna_final;

    if (diff_linha > 0 && diff_coluna > 0) { 
        for (int i = 1; i <= diff_linha; i++) {
            int linha_atual = linha_inicial - i;
            int coluna_atual = coluna_inicial - i;
            if (tabuleiro[linha_atual][coluna_atual] == 'X') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha > 0 && diff_coluna < 0) { 
        for (int i = 1; i <= diff_linha; i++) {
            int linha_atual = linha_inicial - i;
            int coluna_atual = coluna_inicial + i;
            if (tabuleiro[linha_atual][coluna_atual] == 'X') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha < 0 && diff_coluna < 0) { 
        for (int i = 1; i <= -diff_linha; i++) {
            int linha_atual = linha_inicial + i;
            int coluna_atual = coluna_inicial + i;
            if (tabuleiro[linha_atual][coluna_atual] == 'X') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha < 0 && diff_coluna > 0) { 
        for (int i = 1; i <= -diff_linha; i++) {
            int linha_atual = linha_inicial + i;
            int coluna_atual = coluna_inicial - i;
            if (tabuleiro[linha_atual][coluna_atual] == 'X') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    }
}



void mover_damas_OO(int jogada1, int jogada2, int jogada3, int jogada4) {
    int linha_inicial = jogada1;
    int coluna_inicial = jogada2;
    int linha_final = jogada3;
    int coluna_final = jogada4;

    tabuleiro[linha_inicial][coluna_inicial] = '#';
    tabuleiro[linha_final][coluna_final] = '@';


    int diff_linha = linha_inicial - linha_final;
    int diff_coluna = coluna_inicial - coluna_final;

    if (diff_linha > 0 && diff_coluna > 0) { 
        for (int i = 1; i <= diff_linha; i++) {
            int linha_atual = linha_inicial - i;
            int coluna_atual = coluna_inicial - i;
            if (tabuleiro[linha_atual][coluna_atual] == 'X') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha > 0 && diff_coluna < 0) { 
        for (int i = 1; i <= diff_linha; i++) {
            int linha_atual = linha_inicial - i;
            int coluna_atual = coluna_inicial + i;
            if (tabuleiro[linha_atual][coluna_atual] == 'X') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha < 0 && diff_coluna < 0) { 
        for (int i = 1; i <= -diff_linha; i++) {
            int linha_atual = linha_inicial + i;
            int coluna_atual = coluna_inicial + i;
            if (tabuleiro[linha_atual][coluna_atual] == 'X') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    } else if (diff_linha < 0 && diff_coluna > 0) { 
        for (int i = 1; i <= -diff_linha; i++) {
            int linha_atual = linha_inicial + i;
            int coluna_atual = coluna_inicial - i;
            if (tabuleiro[linha_atual][coluna_atual] == 'X') {
                tabuleiro[linha_atual][coluna_atual] = '#';
                comer_multiplas_damas(linha_final, coluna_final);
            }
        }
    }
}

void comer_multiplas_damas(int a, int b){
    int linha_final = a;
    int coluna_final = b;
    imprimir_tabuleiro();

    loop_dama_X:
    if(tabuleiro[linha_final][coluna_final] == '*'){
        for (int i = 0; i < linha_final; i++){
            if(tabuleiro[linha_final + i][coluna_final + i] == 'O' || tabuleiro[linha_final][coluna_final] == '@'){


                if(tabuleiro[linha_final + i + 1][coluna_final + i + 1] == '#'){
                    cout << "Voce pode comer mais peças!" << endl << "Para onde quer comer" << endl;
                    char nova_linha, nova_coluna;
                    cin >> nova_linha >> nova_coluna;
                    int c =transcrever_movimento(nova_linha);
                    int d =transcrever_movimento(nova_coluna);
                    if(jogada_valida_dama_OO(a, b, c, d) == true){
                         mover_damas_OO(a, b, c, d);
                    }else{
                        cout << "Movimento invalido, tente novamente!" << endl;
                        goto loop_dama_X;
                    }
                }
            } else if(tabuleiro[linha_final + i][coluna_final - i] == 'O' || tabuleiro[linha_final][coluna_final] == '@'){
                if(tabuleiro[linha_final + i + 1][coluna_final - i - 1] == '#'){
                    cout << "Voce pode comer mais peças!" << endl << "Para onde quer comer" << endl;
                    char nova_linha, nova_coluna;
                    cin >> nova_linha >> nova_coluna;
                    int c =transcrever_movimento(nova_linha);
                    int d =transcrever_movimento(nova_coluna);
                    if(jogada_valida_dama_OO(a, b, c, d) == true){
                        mover_damas_OO(a, b, c, d); 
                    }else{
                        cout << "Movimento invalido, tente novamente!" << endl;
                        goto loop_dama_X;
                    }
                }
            } else if(tabuleiro[linha_final - i][coluna_final + i] == 'O' || tabuleiro[linha_final][coluna_final] == '@'){
                if(tabuleiro[linha_final - i - 1][coluna_final + i + 1] == '#'){
                    cout << "Voce pode comer mais peças!" << endl << "Para onde quer comer" << endl;
                    char nova_linha, nova_coluna;
                    cin >> nova_linha >> nova_coluna;
                    int c =transcrever_movimento(nova_linha);
                    int d =transcrever_movimento(nova_coluna);
                    if(jogada_valida_dama_OO(a, b, c, d) == true){
                        mover_damas_OO(a, b, c, d);
                    }else{
                        cout << "Movimento invalido, tente novamente!" << endl;
                        goto loop_dama_X;
                    }
                }
            } else if(tabuleiro[linha_final - i][coluna_final - i] == 'O' || tabuleiro[linha_final][coluna_final] == '@'){
                if(tabuleiro[linha_final - i - 1][coluna_final - i - 1] == '#'){
                    cout << "Voce pode comer mais peças!" << endl << "Para onde quer comer" << endl;
                    char nova_linha, nova_coluna;
                    cin >> nova_linha >> nova_coluna;
                    int c =transcrever_movimento(nova_linha);
                    int d =transcrever_movimento(nova_coluna);
                    if(jogada_valida_dama_OO(a, b, c, d) == true){
                        mover_damas_OO(a, b , c, d);
                    }else{
                        cout << "Movimento invalido, tente novamente!" << endl;
                        goto loop_dama_X;
                    }
                }
            }else
                if(i == linha_final -2)
                    break;
        }
    }else if(tabuleiro[linha_final][coluna_final] == '@'){
    loop_damas_O: 
        for (int i = 0; i < linha_final; i++){
            if(tabuleiro[linha_final + i][coluna_final + i] == 'X' || tabuleiro[linha_final][coluna_final] == '*'){
                if(tabuleiro[linha_final + i + 1][coluna_final + i + 1] == '#'){
                    cout << "Voce pode comer mais peças!" << endl << "Para onde quer comer" << endl;
                    char nova_linha, nova_coluna;
                    cin >> nova_linha >> nova_coluna;
                    int c =transcrever_movimento(nova_linha);
                    int d =transcrever_movimento(nova_coluna);
                    if(jogada_valida_dama_OO(a, b, c, d) == true){
                        mover_damas_OO(a, b, c, d);
                    }else{
                        cout << "Movimento invalido, tente novamente!" << endl;
                        goto loop_damas_O;
                    }
                }
            } else if(tabuleiro[linha_final + i][coluna_final - i] == 'X' || tabuleiro[linha_final][coluna_final] == '*'){
                if(tabuleiro[linha_final + i + 1][coluna_final - i - 1] == '#'){
                    cout << "Voce pode comer mais peças!" << endl << "Para onde quer comer" << endl;
                    char nova_linha, nova_coluna;
                    cin >> nova_linha >> nova_coluna;
                    int c =transcrever_movimento(nova_linha);
                    int d =transcrever_movimento(nova_coluna);
                    if(jogada_valida_dama_OO(a, b, c, d) == true){
                        mover_damas_OO(a, b, c, d);
                    }else{
                        cout << "Movimento invalido, tente novamente!" << endl;
                        goto loop_damas_O;
                    }
                }
            } else if(tabuleiro[linha_final - i][coluna_final + i] == 'X' || tabuleiro[linha_final][coluna_final] == '*'){
                if(tabuleiro[linha_final - i - 1][coluna_final + i + 1] == '#'){
                    cout << "Voce pode comer mais peças!" << endl << "Para onde quer comer" << endl;
                    char nova_linha, nova_coluna;
                    cin >> nova_linha >> nova_coluna;
                    int c =transcrever_movimento(nova_linha);
                    int d =transcrever_movimento(nova_coluna);
                    if(jogada_valida_dama_OO(a, b, c, d) == true){
                        mover_damas_OO(a, b, c, d);
                    }else{
                        cout << "Movimento invalido, tente novamente!" << endl;
                        goto loop_damas_O;
                    }
                }
            } else if(tabuleiro[linha_final - i][coluna_final - i] == 'X' || tabuleiro[linha_final][coluna_final] == '*'){
                if(tabuleiro[linha_final - i - 1][coluna_final - i - 1] == '#'){
                    cout << "Voce pode comer mais peças!" << endl << "Para onde quer comer" << endl;
                    char nova_linha, nova_coluna;
                    cin >> nova_linha >> nova_coluna;
                    int c =transcrever_movimento(nova_linha);
                    int d =transcrever_movimento(nova_coluna);
                    if(jogada_valida_dama_OO(a, b, c, d) == true){
                        mover_damas_OO(a, b, c, d);
                    }else{
                        cout << "Movimento invalido, tente novamente!" << endl;
                        goto loop_damas_O;
                    }
                }
            }else
                if(i == linha_final -2)
                    break;
        }
    }
}



                 
    

    void realizar_movimento_O(char jogada1, char jogada2, char jogada3, char jogada4){
        int linha_inicial =transcrever_movimento(jogada1);
        int coluna_inicial =transcrever_movimento(jogada2);
        int linha_final = transcrever_movimento(jogada3);
        int coluna_final = transcrever_movimento(jogada4);
            if(linha_final == (linha_inicial - 1)){
                    tabuleiro[linha_inicial][coluna_inicial] = '#';
                    tabuleiro[linha_final][coluna_final] = 'O';
                if(linha_final == 3){
                    tabuleiro[linha_final][coluna_final] = '@';
                }

            }else if(linha_final == (linha_inicial - 2 )){
                tabuleiro[linha_inicial][coluna_inicial] = '#';
                tabuleiro[linha_final][coluna_final] = 'O';
                if(coluna_final > coluna_inicial){
                    tabuleiro[linha_inicial - 1][coluna_inicial + 1] = '#';
                    comer_multiplas(linha_final, coluna_final);


                }else{
                    tabuleiro[linha_inicial - 1][coluna_inicial - 1] = '#';
                    comer_multiplas(linha_final, coluna_final);

                }
            }else if(linha_final == (linha_inicial + 2)){
                tabuleiro[linha_inicial][coluna_inicial] = '#';
                tabuleiro[linha_final][coluna_final] = 'O';
                if(coluna_final > coluna_inicial){
                    tabuleiro[linha_inicial + 1][coluna_inicial + 1] = '#';
                    comer_multiplas(linha_final, coluna_final);
                }else{
                    tabuleiro[linha_inicial + 1][coluna_inicial - 1] = '#';
                    comer_multiplas(linha_final, coluna_final);
                }

            }         
        }

    bool e_dama(char jogada1, char jogada2){
        int linha_inicial =transcrever_movimento(jogada1);
        int coluna_inicial = transcrever_movimento(jogada2);
        if(tabuleiro[linha_inicial][coluna_inicial] == '@' || tabuleiro[linha_inicial][coluna_inicial] == '*')
            return true;
        else
            return false;
    }



    void realizar_movimento_X(char jogada1, char jogada2, char jogada3, char jogada4)
    {
        int linha_inicial =transcrever_movimento(jogada1);
        int coluna_inicial = transcrever_movimento(jogada2);
        int linha_final = transcrever_movimento(jogada3);
        int coluna_final = transcrever_movimento(jogada4);
        if(linha_final == (linha_inicial + 1)){
            tabuleiro[linha_inicial][coluna_inicial] = '#';
            tabuleiro[linha_final][coluna_final] = 'X';
            if(linha_final == 10)
                tabuleiro[linha_final][coluna_final] = '*';

        }else if(linha_final == (linha_inicial + 2))
            {
            tabuleiro[linha_inicial][coluna_inicial] = '#';
            tabuleiro[linha_final][coluna_final] = 'X';
            if(coluna_final > coluna_inicial)
                {
                tabuleiro[linha_inicial + 1][coluna_inicial + 1] = '#';
                comer_multiplas(linha_final, coluna_final);

                }
            else if(coluna_final < coluna_inicial){
                tabuleiro[linha_inicial + 1][coluna_inicial - 1] = '#';
                comer_multiplas(linha_final, coluna_final);
                }             
        }else if(linha_final == (linha_inicial - 2)){
            tabuleiro[linha_inicial][coluna_inicial] = '#';
            tabuleiro[linha_final][coluna_final] = 'X';
            if(coluna_final > coluna_inicial){
                tabuleiro[linha_inicial - 1][coluna_inicial + 1] = '#';
                comer_multiplas(linha_final, coluna_final);
            }else{
                tabuleiro[linha_inicial - 1][coluna_inicial - 1] = '#';
                comer_multiplas(linha_final, coluna_final);

            }
        }        
    }

bool jogada_valida_dama_O(char jogada1, char jogada2, char jogada3, char jogada4) {
    int linha_inicial = transcrever_movimento(jogada1);
    int coluna_inicial = transcrever_movimento(jogada2);
    int linha_final = transcrever_movimento(jogada3);
    int coluna_final = transcrever_movimento(jogada4);

    if ((linha_inicial > linha_final) && (coluna_inicial > coluna_final) && ((linha_inicial - linha_final) == (coluna_inicial - coluna_final))) {
        for (int i = 1; i < (linha_inicial - linha_final); i++) {
            if (tabuleiro[linha_inicial - i][coluna_inicial - i] == 'X') {
                if (tabuleiro[linha_inicial - i - 1][coluna_inicial - i - 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial - i][coluna_inicial - i] == 'O' || tabuleiro[linha_inicial - i][coluna_inicial - i] == '@') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial > linha_final) && (coluna_inicial < coluna_final) && ((linha_inicial - linha_final) == (coluna_final - coluna_inicial))) {
        for (int i = 1; i < (linha_inicial - linha_final); i++) {
            if (tabuleiro[linha_inicial - i][coluna_inicial + i] == 'X') {
                if (tabuleiro[linha_inicial - i - 1][coluna_inicial + i + 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial - i][coluna_inicial + i] == 'O' || tabuleiro[linha_inicial - i][coluna_inicial + i] == '@') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial < linha_final) && (coluna_inicial > coluna_final) && ((linha_final - linha_inicial) == (coluna_inicial - coluna_final))) {
        for (int i = 1; i < (linha_final - linha_inicial); i++) {
            if (tabuleiro[linha_inicial + i][coluna_inicial - i] == 'X') {
                if (tabuleiro[linha_inicial + i + 1][coluna_inicial - i - 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial + i][coluna_inicial - i] == 'O' || tabuleiro[linha_inicial + i][coluna_inicial - i] == '@') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial < linha_final) && (coluna_inicial < coluna_final) && ((linha_final - linha_inicial) == (coluna_final - coluna_inicial))) {
        for (int i = 1; i < (linha_final - linha_inicial); i++) {
            if (tabuleiro[linha_inicial + i][coluna_inicial + i] == 'X') {
                if (tabuleiro[linha_inicial + i + 1][coluna_inicial + i + 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial + i][coluna_inicial + i] == 'O' || tabuleiro[linha_inicial + i][coluna_inicial + i] == '@') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else {
        cout << "jogada invalida, tente novamente" << endl;
        return false;
    }

    return true;
}

bool jogada_valida_dama_X(char jogada1, char jogada2, char jogada3, char jogada4) {
    int linha_inicial = transcrever_movimento(jogada1);
    int coluna_inicial = transcrever_movimento(jogada2);
    int linha_final = transcrever_movimento(jogada3);
    int coluna_final = transcrever_movimento(jogada4);

    if ((linha_inicial > linha_final) && (coluna_inicial > coluna_final) && ((linha_inicial - linha_final) == (coluna_inicial - coluna_final))) {
        for (int i = 1; i < (linha_inicial - linha_final); i++) {
            if (tabuleiro[linha_inicial - i][coluna_inicial - i] == 'O') {
                if (tabuleiro[linha_inicial - i - 1][coluna_inicial - i - 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial - i][coluna_inicial - i] == 'X' || tabuleiro[linha_inicial - i][coluna_inicial - i] == '*') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial > linha_final) && (coluna_inicial < coluna_final) && ((linha_inicial - linha_final) == (coluna_final - coluna_inicial))) {
        for (int i = 1; i < (linha_inicial - linha_final); i++) {
            if (tabuleiro[linha_inicial - i][coluna_inicial + i] == 'O') {
                if (tabuleiro[linha_inicial - i - 1][coluna_inicial + i + 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial - i][coluna_inicial + i] == 'X' || tabuleiro[linha_inicial - i][coluna_inicial + i] == '*') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial < linha_final) && (coluna_inicial > coluna_final) && ((linha_final - linha_inicial) == (coluna_inicial - coluna_final))) {
        for (int i = 1; i < (linha_final - linha_inicial); i++) {
            if (tabuleiro[linha_inicial + i][coluna_inicial - i] == 'O') {
                if (tabuleiro[linha_inicial + i + 1][coluna_inicial - i - 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial + i][coluna_inicial - i] == 'X' || tabuleiro[linha_inicial + i][coluna_inicial - i] == '*') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial < linha_final) && (coluna_inicial < coluna_final) && ((linha_final - linha_inicial) == (coluna_final - coluna_inicial))) {
        for (int i = 1; i < (linha_final - linha_inicial); i++) {
            if (tabuleiro[linha_inicial + i][coluna_inicial + i] == 'O') {
                if (tabuleiro[linha_inicial + i + 1][coluna_inicial + i + 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial + i][coluna_inicial + i] == 'X' || tabuleiro[linha_inicial + i][coluna_inicial + i] == '*') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else {
        cout << "jogada invalida, tente novamente" << endl;
        return false;
    }

    return true;
}

bool jogada_valida_dama_XX(int jogada1, int jogada2, int jogada3, int jogada4) {
    int linha_inicial = jogada1;
    int coluna_inicial = jogada2;
    int linha_final = jogada3;
    int coluna_final = jogada4;

    if ((linha_inicial > linha_final) && (coluna_inicial > coluna_final) && ((linha_inicial - linha_final) == (coluna_inicial - coluna_final))) {
        for (int i = 1; i < (linha_inicial - linha_final); i++) {
            if (tabuleiro[linha_inicial - i][coluna_inicial - i] == 'O') {
                if (tabuleiro[linha_inicial - i - 1][coluna_inicial - i - 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial - i][coluna_inicial - i] == 'X' || tabuleiro[linha_inicial - i][coluna_inicial - i] == '*') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial > linha_final) && (coluna_inicial < coluna_final) && ((linha_inicial - linha_final) == (coluna_final - coluna_inicial))) {
        for (int i = 1; i < (linha_inicial - linha_final); i++) {
            if (tabuleiro[linha_inicial - i][coluna_inicial + i] == 'O') {
                if (tabuleiro[linha_inicial - i - 1][coluna_inicial + i + 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial - i][coluna_inicial + i] == 'X' || tabuleiro[linha_inicial - i][coluna_inicial + i] == '*') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial < linha_final) && (coluna_inicial > coluna_final) && ((linha_final - linha_inicial) == (coluna_inicial - coluna_final))) {
        for (int i = 1; i < (linha_final - linha_inicial); i++) {
            if (tabuleiro[linha_inicial + i][coluna_inicial - i] == 'O') {
                if (tabuleiro[linha_inicial + i + 1][coluna_inicial - i - 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial + i][coluna_inicial - i] == 'X' || tabuleiro[linha_inicial + i][coluna_inicial - i] == '*') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial < linha_final) && (coluna_inicial < coluna_final) && ((linha_final - linha_inicial) == (coluna_final - coluna_inicial))) {
        for (int i = 1; i < (linha_final - linha_inicial); i++) {
            if (tabuleiro[linha_inicial + i][coluna_inicial + i] == 'O') {
                if (tabuleiro[linha_inicial + i + 1][coluna_inicial + i + 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial + i][coluna_inicial + i] == 'X' || tabuleiro[linha_inicial + i][coluna_inicial + i] == '*') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else {
        cout << "jogada invalida, tente novamente" << endl;
        return false;
    }

    return true;
}



bool jogada_valida_dama_OO(int jogada1, int jogada2, int jogada3, int jogada4) {
    int linha_inicial = jogada1;
    int coluna_inicial = jogada2;
    int linha_final = jogada3;
    int coluna_final = jogada4;

    if ((linha_inicial > linha_final) && (coluna_inicial > coluna_final) && ((linha_inicial - linha_final) == (coluna_inicial - coluna_final))) {
        for (int i = 1; i < (linha_inicial - linha_final); i++) {
            if (tabuleiro[linha_inicial - i][coluna_inicial - i] == 'X') {
                if (tabuleiro[linha_inicial - i - 1][coluna_inicial - i - 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial - i][coluna_inicial - i] == 'O' || tabuleiro[linha_inicial - i][coluna_inicial - i] == '@') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial > linha_final) && (coluna_inicial < coluna_final) && ((linha_inicial - linha_final) == (coluna_final - coluna_inicial))) {
        for (int i = 1; i < (linha_inicial - linha_final); i++) {
            if (tabuleiro[linha_inicial - i][coluna_inicial + i] == 'X') {
                if (tabuleiro[linha_inicial - i - 1][coluna_inicial + i + 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial - i][coluna_inicial + i] == 'O' || tabuleiro[linha_inicial - i][coluna_inicial + i] == '@') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial < linha_final) && (coluna_inicial > coluna_final) && ((linha_final - linha_inicial) == (coluna_inicial - coluna_final))) {
        for (int i = 1; i < (linha_final - linha_inicial); i++) {
            if (tabuleiro[linha_inicial + i][coluna_inicial - i] == 'X') {
                if (tabuleiro[linha_inicial + i + 1][coluna_inicial - i - 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial + i][coluna_inicial - i] == 'O' || tabuleiro[linha_inicial + i][coluna_inicial - i] == '@') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else if ((linha_inicial < linha_final) && (coluna_inicial < coluna_final) && ((linha_final - linha_inicial) == (coluna_final - coluna_inicial))) {
        for (int i = 1; i < (linha_final - linha_inicial); i++) {
            if (tabuleiro[linha_inicial + i][coluna_inicial + i] == 'X') {
                if (tabuleiro[linha_inicial + i + 1][coluna_inicial + i + 1] != '#') {
                    cout << "jogada invalida, tente novamente" << endl;
                    return false;
                }
            } else if (tabuleiro[linha_inicial + i][coluna_inicial + i] == 'O' || tabuleiro[linha_inicial + i][coluna_inicial + i] == '@') {
                cout << "jogada invalida, tente novamente" << endl;
                return false;
            }
        }
    } else {
        cout << "jogada invalida, tente novamente" << endl;
        return false;
    }

    return true;
}

    



    int transcrever_movimento(char jogada1){
        int linha_inicial;
        if(jogada1 == 'A')
            linha_inicial = 3;
        else if(jogada1 == 'B')
            linha_inicial = 4;
        else if(jogada1 == 'C')
            linha_inicial = 5;
        else if(jogada1 == 'D')
            linha_inicial = 6;
        else if(jogada1 == 'E')
            linha_inicial = 7;
        else if(jogada1 == 'F')
            linha_inicial = 8;
        else if(jogada1 == 'G')
            linha_inicial = 9;
        else
            linha_inicial = 10;
        return linha_inicial;

        }
    char resultado_final()
{
    int num_pecas_X = 0;
    int num_pecas_O = 0;
    char ganhador = 'E';
    for (int i = 1; i < linhas; i++){
        for (int j = 1; j < colunas; j++){
            if (tabuleiro[i][j] == 'X')
                num_pecas_X++;
            else if(tabuleiro[i][j] == 'O')
                num_pecas_O++;
        }
    }
    if(num_pecas_X == 0){
        cout<<endl<<"Vitória das 'O'!"<<endl;
        ganhador= 'O';

    }
    else if(num_pecas_O == 0){
        cout<<endl<<"Vitória das 'X'"<<endl;
        ganhador = 'X';

    }
    return ganhador;
}

};

int main() {
    Tabuleiro jogo(13, 13);
    jogo.imprimir_tabuleiro();
    cout << endl << "*************************************" << endl;
    char resultado = 'E';
    int i = 0;

    while (1) {
        resultado = jogo.resultado_final();
        if (resultado != 'E')
            break;

        i++;
        if (i % 2 != 0) {
        Tentativa_O:
            char jogada1, jogada2, jogada3, jogada4;
            cout << endl;
            cout << "Vez do jogador com peças 'O'" << endl;
            cout << endl << "Digite a posição da peça que deseja mover: " << endl;
            cin >> jogada1;
            cin >> jogada2;
            cout << endl << "Digite a posição para onde deseja mover a peça: " << endl;
            cin >> jogada3;
            cin >> jogada4;
            if (jogo.e_dama(jogada1, jogada2) == true) {
                if (jogo.jogada_valida_dama_O(jogada1, jogada2, jogada3, jogada4) == false) {
                    goto Tentativa_O;
                } else {
                    jogo.mover_damas_O(jogada1, jogada2, jogada3, jogada4);
                    cout << endl;
                    jogo.imprimir_tabuleiro();
                }
            } else {
                if (jogo.jogada_valida_O(jogada1, jogada2, jogada3, jogada4) == false) {
                    goto Tentativa_O;
                } else {
                    jogo.realizar_movimento_O(jogada1, jogada2, jogada3, jogada4);
                    cout << endl;
                    jogo.imprimir_tabuleiro();
                }
            }
        }

        if (i % 2 == 0) {
        Tentativa_X:
            char jogada1, jogada2, jogada3, jogada4;
            cout << endl;
            cout << "Vez do jogador com peças 'X'" << endl;
            cout << endl << "Digite a posição da peça que deseja mover: " << endl;
            cin >> jogada1;
            cin >> jogada2;
            cout << endl << "Digite a posição para onde deseja mover a peça: " << endl;
            cin >> jogada3;
            cin >> jogada4;
            if (jogo.e_dama(jogada1, jogada2) == true) {
                if (jogo.jogada_valida_dama_X(jogada1, jogada2, jogada3, jogada4) == false) {
                    goto Tentativa_X;
                } else {
                    jogo.mover_damas_X(jogada1, jogada2, jogada3, jogada4);
                    cout << endl;
                    jogo.imprimir_tabuleiro();
                }
            } else {
                if (jogo.jogada_valida_X(jogada1, jogada2, jogada3, jogada4) == false) {
                    goto Tentativa_X;
                } else {
                    jogo.realizar_movimento_X(jogada1, jogada2, jogada3, jogada4);
                    cout << endl;
                    jogo.imprimir_tabuleiro();
                }
            }
        }
    }

    return 0;
}
