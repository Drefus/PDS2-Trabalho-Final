#include <reversi.hpp>

/**
 * @brief Construtor da classe reversi, inicializa o tabuleiro e define as peças iniciais.
 */
reversi::reversi() : game(8, 8, "reversi"), turno(0)
{
    // Inicializa o tabuleiro com espaços em branco
    for (int i = 0; i < rows; ++i)
    {
        vector<char> linha(cols, ' ');
        tabuleiro.push_back(linha);
    }

    // Define as peças iniciais no tabuleiro
    tabuleiro[3][3] = 'B';
    tabuleiro[4][4] = 'B';
    tabuleiro[3][4] = 'P';
    tabuleiro[4][3] = 'P';

    this->loadPlayers();

    bool jogoFinalizado = false;

    while (!jogoFinalizado)
    {
        mostrarTabuleiro();
        char currentPlayer = (turno % 2 == 0) ? 'P' : 'B';

        // Verifica se o jogador atual tem movimentos válidos
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

        // Verifica a pontuação dos jogadores
        int pontuacaoP = contarPecas('P');
        int pontuacaoB = contarPecas('B');

        // Verifica se algum jogador venceu
        if (pontuacaoP == 0)
        {
            cout << endl
                 << "Jogador 2 (B) venceu!" << endl;
            winAndLose(jogador2, jogador1);
            jogoFinalizado = true;
        }
        else if (pontuacaoB == 0)
        {
            cout << endl
                 << "Jogador 1 (P) venceu!" << endl;
            winAndLose(jogador1, jogador2);
            jogoFinalizado = true;
        }

        bool semMovimentosP = !temMovimentosValidos('P');
        bool semMovimentosB = !temMovimentosValidos('B');

        // Verifica se o jogo acabou
        if (!jogoFinalizado && semMovimentosP && semMovimentosB)
        {
            if (pontuacaoP > pontuacaoB)
            {
                cout << endl
                     << "Jogador 1 (P) venceu!" << endl;
                winAndLose(jogador1, jogador2);
            }
            else if (pontuacaoB > pontuacaoP)
            {
                cout << endl
                     << "Jogador 2 (B) venceu!" << endl;
                winAndLose(jogador2, jogador1);
            }
            else
            {
                cout << endl
                     << "Empate!" << endl;
            }
            jogoFinalizado = true;
        }
    }

    mostrarTabuleiro();
}

/**
 * @brief Exibe o tabuleiro do jogo.
 */
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

/**
 * @brief Verifica se um movimento é válido para o jogador atual.
 * @param x Coordenada x (linha) do movimento.
 * @param y Coordenada y (coluna) do movimento.
 * @param player Jogador atual ('P' ou 'B').
 * @return true se o movimento for válido, false caso contrário.
 */
bool reversi::movimentoValido(int x, int y, char player)
{
    if (tabuleiro[x][y] != ' ')
        return false;

    return verificarAdjacente(x, y, player);
}

/**
 * @brief Executa um movimento no tabuleiro.
 * @param x Coordenada x (linha) do movimento.
 * @param y Coordenada y (coluna) do movimento.
 * @param player Jogador atual ('P' ou 'B').
 * @return true se o movimento foi realizado, false caso contrário.
 */
bool reversi::jogada(int x, int y, char player)
{
    if (!movimentoValido(x, y, player))
    {
        return false;
    }

    tabuleiro[x][y] = player;
    char oponente = (player == 'P') ? 'B' : 'P';

    // Verifica e converte as peças do oponente
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

/**
 * @brief Verifica se há peças adjacentes que podem ser capturadas.
 * @param x Coordenada x (linha) da peça atual.
 * @param y Coordenada y (coluna) da peça atual.
 * @param player Jogador atual ('P' ou 'B').
 * @return true se houver peças adjacentes a serem capturadas, false caso contrário.
 */
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

/**
 * @brief Verifica se o jogador atual tem movimentos válidos disponíveis.
 * @param player Jogador atual ('P' ou 'B').
 * @return true se o jogador tiver movimentos válidos, false caso contrário.
 */
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

/**
 * @brief Conta o número de peças de um jogador no tabuleiro.
 * @param player Jogador ('P' ou 'B').
 * @return Número de peças do jogador
 * @return Número de peças do jogador no tabuleiro.
 */
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
