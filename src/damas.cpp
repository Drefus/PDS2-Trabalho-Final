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
        tabuleiro[1][0] = 'A';
        tabuleiro[2][0] = 'B';
        tabuleiro[3][0] = 'C';
        tabuleiro[4][0] = 'D';
        tabuleiro[5][0] = 'E';
        tabuleiro[6][0] = 'F';
        tabuleiro[7][0] = 'G';
        tabuleiro[8][0] = 'H';
        tabuleiro[0][1] = 'A';
        tabuleiro[0][2] = 'B';
        tabuleiro[0][3] = 'C';
        tabuleiro[0][4] = 'D';
        tabuleiro[0][5] = 'E';
        tabuleiro[0][6] = 'F';
        tabuleiro[0][7] = 'G';
        tabuleiro[0][8] = 'H';
        for (int i = 1; i < linhas; i++) {
            for (int j = 1; j < colunas; j++) {
                if (i < 4) {
                    if ((i + j) % 2 != 0) {
                        tabuleiro[i][j] = 'X';
                    }
                } else if (i == 4 && (i + j) % 2 != 0) {
                    tabuleiro[i][j] = '#';
                }else if(i == 5 && (i + j) % 2 != 0){
                    tabuleiro[i][j] = '#';
                }else if(i > 5){
                    if((i + j) % 2 != 0){
                        tabuleiro[i][j] = 'O';
                    }
                }
            }
        }
    }

    void imprimir_tabuleiro() {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cout << tabuleiro[i][j] << " ";
            }
            cout << endl;
        }
    }
    void realizar_movimento_O(char jogada1, char jogada2, char jogada3, char jogada4){
        int linha_inicial =transcrever_movimento(jogada1);
        int coluna_inicial =transcrever_movimento(jogada2);
        if(tabuleiro[linha_inicial][coluna_inicial] != 'O'){
            cout << "Movimento invalido" <<endl<<endl;
        }else if(tabuleiro[linha_inicial][coluna_inicial] == 'O'){
            int linha_final = transcrever_movimento(jogada3);
            int coluna_final = transcrever_movimento(jogada4);
            if(tabuleiro[linha_final][coluna_final] == 'X' || tabuleiro[linha_final][coluna_final] == 'O'){
                cout << "Movimento invalido" << endl<<endl;
            }else{
                if(linha_final == (linha_inicial - 1)){
                    tabuleiro[linha_inicial][coluna_inicial] = '#';
                    tabuleiro[linha_final][coluna_final] = 'O';
                   
                }else if(linha_final == linha_inicial - 2){
                    tabuleiro[linha_inicial][coluna_inicial] = '#';
                    tabuleiro[linha_final][coluna_final] = 'O';
                    if(coluna_final > coluna_inicial)
                        tabuleiro[linha_inicial - 1][coluna_inicial + 1] = '#';
                    else
                        tabuleiro[linha_inicial - 1][coluna_inicial - 1] = '#';
                   

                }        
            }
        }
        
    }
    void realizar_movimento_X(char jogada1, char jogada2, char jogada3, char jogada4){
        int linha_inicial =transcrever_movimento(jogada1);
        int coluna_inicial = transcrever_movimento(jogada2);
        if(tabuleiro[linha_inicial][coluna_inicial] != 'X'){
            cout << "Movimento invalido" << endl;
        }else if(tabuleiro[linha_inicial][coluna_inicial] == 'X'){
            int linha_final = transcrever_movimento(jogada3);
            int coluna_final = transcrever_movimento(jogada4);
            if(tabuleiro[linha_final][coluna_final] == 'X' || tabuleiro[linha_final][coluna_final] == 'O'){
                cout << "Movimento invalido" << endl<<endl;
            }else if(tabuleiro[linha_final][coluna_final] == '#'){
                if(linha_final == linha_inicial + 1){
                    tabuleiro[linha_inicial][coluna_inicial] = '#';
                    tabuleiro[linha_final][coluna_final] = 'X';
                    
                }else if(linha_final == linha_inicial +2){
                    tabuleiro[linha_inicial][coluna_inicial] = '#';
                    tabuleiro[linha_final][coluna_final] = 'X';
                    if(coluna_final > coluna_inicial)
                        tabuleiro[linha_inicial + 1][coluna_inicial + 1] = '#';
                    else
                        tabuleiro[linha_inicial + 1][coluna_inicial - 1] = '#';
                   

                }        
            }
        }

    }
    int transcrever_movimento(char jogada1){
        int linha_inicial;
        if(jogada1 == 'A')
            linha_inicial = 1;
        else if(jogada1 == 'B')
            linha_inicial = 2;
        else if(jogada1 == 'C')
            linha_inicial = 3;
        else if(jogada1 == 'D')
            linha_inicial = 4;
        else if(jogada1 == 'E')
            linha_inicial = 5;
        else if(jogada1 == 'F')
            linha_inicial = 6;
        else if(jogada1 == 'G')
            linha_inicial = 7;
        else
            linha_inicial = 8;
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
        cout<<"Vitória das 'O'"<<endl;
        ganhador= 'O';
    }
    else if(num_pecas_O == 0){
        cout<<"Vitória das 'X'"<<endl;
        ganhador = 'X';
    }
    return ganhador;
}
     
};

int main() {
    Tabuleiro jogo(9, 9);
    jogo.imprimir_tabuleiro();
    cout<<endl<<"******************************************"<<endl;
    char resultado = 'E';
    int i = 0;

    while(resultado == 'E')
    {
        resultado = jogo.resultado_final();
        i++;
        if(i % 2 != 0)
        {
            char jogada1, jogada2, jogada3, jogada4;
            cout<<"Vez do jogador com peças 'O'"<<endl;
            cout<<endl<<"Digite a posição da peça que deseja mover: "<<endl;
            cin>>jogada1;
            cin>>jogada2;
            cout<<endl<<"digite a posição para onde deseja mover a peça: "<<endl;
            cin>>jogada3;
            cin>>jogada4;
            jogo.realizar_movimento_O(jogada1, jogada2, jogada3, jogada4);
            jogo.imprimir_tabuleiro();
            
        }
        if(i % 2 == 0)
        {
            char jogada1, jogada2, jogada3, jogada4;
            cout<<"Vez do jogador com peças 'X'"<<endl;
            cout<<endl<<"Digite a posição da peça que deseja mover: "<<endl;
            cin>>jogada1;
            cin>>jogada2;
            cout<<endl<<"digite a posição para onde deseja mover a peça: "<<endl;
            cin>>jogada3;
            cin>>jogada4;
            jogo.realizar_movimento_X(jogada1, jogada2, jogada3, jogada4);
            jogo.imprimir_tabuleiro();

            
        }
        
    }

    return 0;
}
