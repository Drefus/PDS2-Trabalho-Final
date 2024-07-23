#include <reversi.hpp>

reversi::reversi() : game(8, 8), turno(0)
{
    for (int i = 0; i < rows; ++i)
    {
        vector<char> linha(cols, ' ');
        tabuleiro.push_back(linha);
    }

    tabuleiro[3][3] = 'B';
    tabuleiro[4][4] = 'B';
    tabuleiro[3][4] = 'P';
    tabuleiro[4][3] = 'P';

    string jogador1, jogador2;
    do
    {
        cout << "Digite o apelido do jogador 1:" << endl;

        while (getline(cin, jogador1))
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
        cout << "Digite o apelido do jogador 2:" << endl;

        while (getline(cin, jogador2))
            if (jogador2 != "")
            {
                break;
            }
        if (management.existPlayer(jogador2) == 1)
        {
            break;
        }
    } while (true);

    bool jogoFinalizado = false;

    while (!jogoFinalizado)
    {
        mostrarTabuleiro();
        char currentPlayer = (turno % 2 == 0) ? 'P' : 'B';
        if (!temMovimentosValidos(currentPlayer))
        {
            cout << "Jogador " << ((turno % 2 == 0) ? "1" : "2") << " (" << currentPlayer << "), não tem movimentos válidos. Deseja passar a vez? (s/n): ";
            char escolha;
            cin >> escolha;
            cin.ignore();
            if (escolha == 's' || escolha == 'S')
            {
                turno++;
                continue;
            }
        }
        else
        {
            int x, y;
            cout << "Jogador " << ((turno % 2 == 0) ? "1" : "2") << " (" << currentPlayer << "), digite a jogada (linha coluna): ";
            cin >> x >> y;
            cin.ignore();
            if (jogada(x - 1, y - 1, currentPlayer))
            {
                turno++;
            }
            else
            {
                cout << "Movimento inválido, tente novamente." << endl;
                continue;
            }
        }

        int pontuacaoP = contarPecas('P');
        int pontuacaoB = contarPecas('B');

        if (pontuacaoP == 0)
        {
            cout << endl << "Jogador 2 (B) venceu!" << endl;
            winAndLose(jogador2, jogador1);
            jogoFinalizado = true;
        }
        else if (pontuacaoB == 0)
        {
            cout << endl << "Jogador 1 (P) venceu!" << endl;
            winAndLose(jogador1, jogador2);
            jogoFinalizado = true;
        }

        bool semMovimentosP = !temMovimentosValidos('P');
        bool semMovimentosB = !temMovimentosValidos('B');

        if (!jogoFinalizado && semMovimentosP && semMovimentosB)
        {
            if (pontuacaoP > pontuacaoB)
            {
                cout << endl << "Jogador 1 (P) venceu!" << endl;
                winAndLose(jogador1, jogador2);

            }
            else if (pontuacaoB > pontuacaoP)
            {
                cout << endl << "Jogador 2 (B) venceu!" << endl;
                winAndLose(jogador2, jogador1);
            }
            else
            {
                cout << endl << "Empate!" << endl;
            }
            jogoFinalizado = true;
        }
    }

    mostrarTabuleiro();
}

void reversi::mostrarTabuleiro()
{
    cout << "  ";
    for (int col = 0; col < cols; col++)
    {
        cout << col + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < rows; ++i)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < cols; ++j)
        {
            char displayChar = tabuleiro[i][j];
            if (displayChar == ' ')
            {
                char currentPlayer = (turno % 2 == 0) ? 'P' : 'B';
                if (movimentoValido(i, j, currentPlayer))
                {
                    displayChar = 'O';
                }
            }
            cout << displayChar << " ";
        }
        cout << endl;
    }

    int pontuacaoP = contarPecas('P');
    int pontuacaoB = contarPecas('B');
    cout << "Pontuação - P: " << pontuacaoP << " B: " << pontuacaoB << endl;
}

bool reversi::movimentoValido(int x, int y, char player)
{
    if (tabuleiro[x][y] != ' ')
        return false;

    return verificarAdjacente(x, y, player);
}

bool reversi::jogada(int x, int y, char player)
{
    if (!movimentoValido(x, y, player))
    {
        return false;
    }

    tabuleiro[x][y] = player;
    char oponente = (player == 'P') ? 'B' : 'P';

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx != 0 || dy != 0)
            {
                int nx = x + dx, ny = y + dy;
                bool encontrouOponente = false;
                while (nx >= 0 && nx < rows && ny >= 0 && ny < cols && tabuleiro[nx][ny] == oponente)
                {
                    encontrouOponente = true;
                    nx += dx;
                    ny += dy;
                }
                if (encontrouOponente && nx >= 0 && nx < rows && ny >= 0 && ny < cols && tabuleiro[nx][ny] == player)
                {
                    int cx = x + dx, cy = y + dy;
                    while (cx != nx || cy != ny)
                    {
                        tabuleiro[cx][cy] = player;
                        cx += dx;
                        cy += dy;
                    }
                }
            }
        }
    }
    return true;
}

bool reversi::verificarAdjacente(int x, int y, char player)
{
    char oponente = (player == 'P') ? 'B' : 'P';
    bool valido = false;

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx != 0 || dy != 0)
            {
                int nx = x + dx, ny = y + dy;
                bool encontrouOponente = false;
                while (nx >= 0 && nx < rows && ny >= 0 && ny < cols && tabuleiro[nx][ny] == oponente)
                {
                    encontrouOponente = true;
                    nx += dx;
                    ny += dy;
                }
                if (encontrouOponente && nx >= 0 && nx < rows && ny >= 0 && ny < cols && tabuleiro[nx][ny] == player)
                {
                    valido = true;
                    break;
                }
            }
        }
    }
    return valido;
}

bool reversi::temMovimentosValidos(char player)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (movimentoValido(i, j, player))
            {
                return true;
            }
        }
    }
    return false;
}

int reversi::contarPecas(char player)
{
    int count = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (tabuleiro[i][j] == player)
            {
                count++;
            }
        }
    }
    return count;
}
