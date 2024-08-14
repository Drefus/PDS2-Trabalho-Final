#include <fstream>
#include <iostream>
#include <vector>
#include <lig4.hpp>

using namespace std;

/// @brief Show the board
void lig4::mostrarTabuleiro()
{   
    for (int linha = 0; linha < this->rows; linha++)
    {
        cout << "|";
        for (int coluna = 0; coluna < this->cols; coluna++)
        {
            cout << this->tabuleiro[linha][coluna] << "|";
        }
        cout << endl;
    }
    cout << "|1|2|3|4|5|6|7|" << endl;
}

/// @brief Make a valid play in the board
/// @param posicao int
/// @return line that the player did the move as a INT
int lig4::jogada(int &posicao)
{
    int jogada = 0;
    while ((posicao < 1 && posicao > 7) || (tabuleiro[0][posicao - 1] != ' ') || (posicao%1 != 0) || isdigit(posicao) != 0)
    {   
        cout << "posição inválida, insira uma nova posição" << endl;
        cin >> jogada;
        posicao = jogada;
    }
    bool valido = false;
    int linha = this->rows - 1;
    while (valido == false)
    {
        if (this->tabuleiro[linha][posicao - 1] == ' ')
        {
            if (turno % 2 == 0)
            {
                this->tabuleiro[linha][posicao - 1] = 'V';
            }
            else
                this->tabuleiro[linha][posicao - 1] = 'A';
            valido = true;
        }
        else
            linha--;
    };
    return linha;
}

/// @brief Check if one player won the game based on the last move
/// @param linha int
/// @param coluna int
/// @param time char
/// @return Return true if that´s a win, False if the game ins´t over
bool lig4::verificarAdjacente(int linha, int coluna, char time)
{

    int sequencia = 1;
    for (int i = 1; i < 4; i++)
    {
        if (linha - i >= 0 && time == tabuleiro[linha - i][coluna])
            sequencia++;
        else break;
    }
    for (int i = 1; i < 4; i++)
    {
        if (linha + i <= 5 && time == tabuleiro[linha + i][coluna])
            sequencia++;
        else
            break;
    }
    if (sequencia >= 4)
        return true;

    sequencia = 1;
    for (int i = 1; i < 4; i++)
    {
        if (coluna - i >= 0 && time == tabuleiro[linha][coluna - i])
            sequencia++;
        else break;
    }
    for (int i = 1; i < 4; i++)
    {
        if (coluna + i <= 6 && time == tabuleiro[linha][coluna + i])
            sequencia++;
        else break;
    }
    if (sequencia >= 4)
        return true;

    sequencia = 1;
    for (int i = 1; i < 4; i++)
    {
        if (linha - i >= 0 && coluna - i >= 0 && time == tabuleiro[linha - i][coluna - i])
            sequencia++;
        else break;
    }
    for (int i = 1; i < 4; i++)
    {
        if (linha + i <= 5 && coluna + i <= 6 && time == tabuleiro[linha + i][coluna + i])
            sequencia++;
        else break;
    }
    if (sequencia >= 4)
        return true;

    sequencia = 1;
    for (int i = 1; i < 4; i++)
    {
        if (linha + i <= 5 && coluna - i >= 0 && time == tabuleiro[linha + i][coluna - i])
            sequencia++;
        else break;
    }
    for (int i = 1; i < 4; i++)
    {
        if (linha - i >= 0 && coluna + i <= 6 && time == tabuleiro[linha - i][coluna + i])
            sequencia++;
        else break;
    }
    if (sequencia >= 4)
        return true;

    return false;
}

/// @brief Constructor and match of Lig4
lig4::lig4() : game(6, 7)
{
    std::string jogador1;
    std::string jogador2;
    do
    {
        std::cout << "Digite o apelido do jogador 1:" << std::endl;

        while (std::getline(std::cin, jogador1))
            if (jogador1 != "")
            {
                break;
            }
        if (management.existPlayer(jogador1) == 1)
        {
            break;
        }
    } while (true);

    do
    {
        std::cout << "Digite o apelido do jogador 2:" << std::endl;

        while (std::getline(std::cin, jogador2))
            if (jogador2 != "")
            {
                break;
            }
        if (management.existPlayer(jogador2) == 1)
        {
            break;
        }
    } while (true);

    while (true)
    {   
        int input, line;
        bool completo = true;
        vector<int> cord;
        this->mostrarTabuleiro();
        if (turno % 2 == 0)
        {
            std::cout << "Digite a jogada do jogador 1:" << std::endl;
            std::cin >> input;
            line = jogada(input);
            if (verificarAdjacente(line, input-1, 'V'))
            {
                cout << "Jogador 1 venceu" << endl;
                winAndLose(jogador1, jogador2);
                this->mostrarTabuleiro();
                break;
            }
        }
        else
        {
            std::cout << "Digite a jogada do jogador 2:" << std::endl;
            std::cin >> input;
            line = jogada(input);
            if (verificarAdjacente(line, input-1, 'A'))
            {   
                cout << "Jogador 2 venceu" << endl;
                this->mostrarTabuleiro();
                winAndLose(jogador2, jogador1);
                break;
            }
        }
        turno++;

        for (int linha = 0; linha < this->rows; linha++) {
            for (int coluna = 0; coluna < this->cols; coluna++) {
                if (this->tabuleiro[linha][coluna] == ' ') completo = false;
            }
        }
        if (completo == true) {
            cout << "Empate" << endl;
            this->mostrarTabuleiro();
            break;
        }
    }
}
