#include <iostream>
#include <jogoDaVelha.hpp>
using namespace std;

/// @brief Construtor do tabuleiro
void jogoDaVelha::drawTabuleiro()
{
    cout << " " << tabuleiro[0][0] << " | " << tabuleiro[0][1] << " | " << tabuleiro[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << tabuleiro[1][0] << " | " << tabuleiro[1][1] << " | " << tabuleiro[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << tabuleiro[2][0] << " | " << tabuleiro[2][1] << " | " << tabuleiro[2][2] << endl;
}

/// @brief Marca o tabuleiro
/// @param coord int
/// @return true se a jogada for possível e false se não for
bool jogoDaVelha::marcador(int coord)
{
    int fileira = (coord - 1) / 3;
    int coluna = (coord - 1) % 3;

    if (tabuleiro[fileira][coluna] != 'X' && tabuleiro[fileira][coluna] != 'O')
    {
        tabuleiro[fileira][coluna] = marcadorAtual;
        return true;
    }
    else
        return false;
}

/// @brief Verifica se houve um vencedor
/// @return 1 ou 2 se houver vencedor e 0 se não houver
int jogoDaVelha::winner()
{

    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == marcadorAtual && tabuleiro[i][1] == marcadorAtual && tabuleiro[i][2] == marcadorAtual)
            return jogadorAtual;
    }

    for (int j = 0; j < 3; j++)
    {
        if (tabuleiro[0][j] == marcadorAtual && tabuleiro[1][j] == marcadorAtual && tabuleiro[2][j] == marcadorAtual)
            return jogadorAtual;
    }

    if (tabuleiro[0][0] == marcadorAtual && tabuleiro[1][1] == marcadorAtual && tabuleiro[2][2] == marcadorAtual)
        return jogadorAtual;
    if (tabuleiro[0][2] == marcadorAtual && tabuleiro[1][1] == marcadorAtual && tabuleiro[2][0] == marcadorAtual)
        return jogadorAtual;

    return 0;
}

/// @brief Alterna o jogador após a jogada
void jogoDaVelha::mudaJogador()
{
    if (marcadorAtual == 'X')
        marcadorAtual = 'O';
    else
        marcadorAtual = 'X';

    if (jogadorAtual == 1)
        jogadorAtual = 2;
    else
        jogadorAtual = 1;
}

/// @brief Função para garantir que o jogador 1 escolha entre X ou O
void jogoDaVelha::escolherMarcador()
{
    while (true)
    {
        cout << "Jogador 1, escolha o marcador (X ou O): ";
        char marcador1;
        cin >> marcador1;
        marcador1 = toupper(marcador1);

        if (marcador1 == 'X' || marcador1 == 'O')
        {
            marcadorAtual = marcador1;
            jogadorAtual = 1;
            break;
        }
        else
        {
            cout << "Escolha inválida. Escolha X ou O." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

/// @brief Utiliza as funções para rodar o jogo e faz checagem para jogadas válidas
jogoDaVelha::jogoDaVelha() : game(3, 3, "jogodavelha")
{
    this->tabuleiro = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    this->loadPlayers();
    escolherMarcador();
    drawTabuleiro();

    for (int g = 0; g < 9; g++)
    {
        int coord;
        while (true)
        {
            cout << "Jogador " << jogadorAtual << ", faça sua jogada: ";
            cin >> coord;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Movimento inválido. Por favor, insira um número entre 1 e 9." << endl;
            }
            else
            {
                break;
            }
        }

        if (coord < 1 || coord > 9)
        {
            cout << "Movimento Inválido." << endl;
            g--;
            continue;
        }

        if (!marcador(coord))
        {
            cout << "Espaço já ocupado." << endl;
            g--;
            continue;
        }

        drawTabuleiro();

        int vencedor = winner();
        if (vencedor == 1)
        {
            cout << "Jogador 1 foi o Vencedor!" << endl;
            this->winAndLose(jogador1, jogador2);
            break;
        }

        if (vencedor == 2)
        {
            cout << "Jogador 2 foi o Vencedor!" << endl;
            this->winAndLose(jogador2, jogador1);
            break;
        }

        if (g == 8)
        {
            cout << "Deu velha! Ninguém venceu." << endl;
        }

        mudaJogador();
    }
}
