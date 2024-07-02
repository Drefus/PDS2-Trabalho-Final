#include <fstream>
#include <iostream>
#include <vector>
#include <lig4.hpp>

using namespace std;

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
}

void lig4::jogada(int posicao)
{
    bool valido = false;
    int linha = this->rows - 1;
    while (valido == false)
    {
        if (this->tabuleiro[linha][posicao] == ' ')
        {
            if (turno % 2 == 0)
            {
                this->tabuleiro[linha][posicao] = 'V';
            }
            else
                this->tabuleiro[linha][posicao] = 'A';
            valido = true;
        }
        else
            linha--;
    };
}

bool lig4::verificarAdjacente(int linha, int coluna, char time)
{

    int sequencia = 1;
    for (int i = 1; i < 4; i++)
    {
        if (linha - i < 0 || time != tabuleiro[linha - i][coluna])
            break;
        else
            sequencia++;
    }
    for (int i = 1; i < 4; i++)
    {
        if (linha + i > 5 || time != tabuleiro[linha + i][coluna])
            break;
        else
            sequencia++;
    }
    if (sequencia >= 4)
        return true;

    sequencia = 1;
    for (int i = 1; i < 4; i++)
    {
        if (coluna - i < 0 || time != tabuleiro[linha][coluna - i])
            break;
        else
            sequencia++;
    }
    for (int i = 1; i < 4; i++)
    {
        if (coluna + i > 6 || time != tabuleiro[linha][coluna + i])
            break;
        else
            sequencia++;
    }
    if (sequencia >= 4)
        return true;

    sequencia = 1;
    for (int i = 1; i < 4; i++)
    {
        if (linha - i < 0 || coluna - i < 0 || time != tabuleiro[linha - i][coluna - i])
            break;
        else
            sequencia++;
    }
    for (int i = 1; i < 4; i++)
    {
        if (linha + i > 5 || coluna + i > 6 || time != tabuleiro[linha + i][coluna + i])
            break;
        else
            sequencia++;
    }
    if (sequencia >= 4)
        return true;

    sequencia = 1;
    for (int i = 1; i < 4; i++)
    {
        if (linha + i > 5 || coluna - i < 0 || time != tabuleiro[linha + i][coluna - i])
            break;
        else
            sequencia++;
    }
    for (int i = 1; i < 4; i++)
    {
        if (linha - i < 0 || coluna + i > 6 || time != tabuleiro[linha - i][coluna + i])
            break;
        else
            sequencia++;
    }
    if (sequencia >= 4)
        return true;
    return false;
}

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
        int input;
        this->mostrarTabuleiro();
        if (turno % 2 == 0)
        {
            std::cout << "Digite a jogada do jogador 1:" << std::endl;
            std::cin >> input;
            jogada(input);
            if (verificarAdjacente(rows, cols, 'V'))
            {
                winAndLose(jogador1, jogador2);
            }
        }
        else
        {
            std::cout << "Digite a jogada do jogador 2:" << std::endl;
            std::cin >> input;
            jogada(input);
            if (verificarAdjacente(rows, cols, 'A'))
            {
                winAndLose(jogador2, jogador1);
            }
        }
        turno++;
    }
}
