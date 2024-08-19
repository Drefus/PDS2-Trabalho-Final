# Trabalho Final da Disciplina de PDS2

## Instruções de Execução

Para executar o código em um ambiente Linux, siga os passos abaixo:

1. Navegue até o diretório do projeto.
2. Use o comando `make all` para gerar o arquivo compilado.
3. Após a compilação, execute o arquivo `bin/tp.out`.

## Instruções para Jogar

Escolha uma das opções do menu. O que cada uma delas faz está descrito abaixo. Para sair do menu, digite `E`.

### Gerenciamento de Jogadores

Para acessar o gerenciamento de jogadores, escolha a opção 1 do menu.

#### Adição de Jogador

Escolha a opção 1 do menu de gerenciamento de jogadores e forneça um nome e um apelido únicos para o jogador. O jogador será criado.

#### Remoção de Jogador

Escolha a opção 2 do menu de gerenciamento de jogadores e forneça um nome ou apelido válido. O jogador será removido.

#### Listar Estatísticas de Jogador

Escolha a opção 3 do menu de gerenciamento de jogadores e forneça um nome ou apelido válido. As estatísticas do jogador serão exibidas. **Observação:** Só aparecerão estatísticas de jogos que o jogador já tenha participado; se o usuário não tiver jogado nenhum jogo, apenas o apelido será exibido.

#### Listar Estatísticas de Todos os Jogadores

Escolha a opção 4 do menu de gerenciamento de jogadores. Todas as estatísticas de todos os jogadores serão exibidas. **Observação:** Só aparecerão estatísticas de jogos que os jogadores já tenham participado; se algum jogador não tiver jogado nenhum jogo, apenas o apelido será exibido.

#### Sair

Para sair do menu, digite `E`.

## Instruções para os Jogos

### Lig4

#### Começando o Jogo

Insira o apelido do 1º jogador e, em seguida, do 2º jogador.

#### Como Jogar

O objetivo dos jogadores é unir 4 peças da sua cor, seja na vertical, horizontal ou diagonal.

Para uma jogada ser válida, ela deve ser um número inteiro de 1 a 7 e a coluna correspondente não pode estar totalmente preenchida. Quando o jogador escolher uma coluna, sua peça será colocada na primeira linha disponível (de cima para baixo) dessa coluna.

A primeira jogada é do jogador 1 (time vermelho: V), e, a partir daí, os jogadores vermelho e azul irão revezar as jogadas. O vencedor será o jogador que unir 4 peças primeiro. Cada jogador receberá uma vitória ou derrota. Se o tabuleiro estiver totalmente completo e nenhum jogador vencer, o jogo será declarado empate.

### Damas

#### Regras

O jogo de damas é praticado entre dois parceiros, com 12 pedras 'O' de um lado e 12 pedras 'X' do outro. O lance inicial cabe sempre ao jogador com as peças 'O'.

A pedra move-se apenas para frente, uma casa de cada vez. Quando a pedra atinge a oitava linha do tabuleiro, ela é promovida à dama. Para identificá-la, usa-se '@' para as peças 'O' e '*' para as peças 'X'.

A dama tem movimentos mais amplos, podendo se mover para frente e para trás, quantas casas desejar. A dama não pode saltar uma peça da mesma cor. A captura é obrigatória. Não há "sopro". Duas ou mais peças juntas na mesma diagonal não podem ser capturadas.

A pedra captura a dama e a dama captura a pedra. Ambas podem capturar peças tanto para frente quanto para trás, uma ou mais peças. Se houver mais de uma opção de captura no mesmo lance, é obrigatório capturar o maior número de peças (Lei da Maioria).

Se a pedra, durante a captura de várias peças, passar por uma casa de coroação sem parar, não será promovida à dama. Na execução da captura, é permitido passar mais de uma vez pela mesma casa vazia; não é permitido capturar a mesma peça mais de uma vez.

#### Como Realizar as Jogadas

Primeiro, selecione a peça que deve executar a ação, indicando sua posição no tabuleiro, especificando a Linha e a Coluna. As informações sobre as posições das peças devem ser passadas em letras maiúsculas e na ordem LinhaColuna.

Depois, indique para qual casa a peça deve se mover. Se a jogada for capturar uma peça, basta informar a casa final da peça movimentada. Se for capturar múltiplas peças, e a peça inicial for uma pedra comum, a captura será feita automaticamente. Se a peça for uma dama, após a primeira captura, você deve indicar a posição para onde sua dama deve se mover, priorizando sempre capturar outra peça.

#### Como Ganhar

A única condição de vitória é capturar todas as peças do adversário.

### Reversi

#### Começando o Jogo

Insira o apelido do 1º jogador e, em seguida, do 2º jogador.

#### Como Jogar

Dois jogadores competem usando 64 peças idênticas, claras de um lado e escuras do outro. Cada jogador escolhe uma cor para usar durante o jogo.

Os jogadores se revezam colocando um disco em um quadrado vazio, com a cor escolhida voltada para cima. Depois de uma jogada, quaisquer discos da cor do oponente que estejam em linha reta delimitada pelo disco recém-colocado e outro disco da cor do jogador atual serão virados.

Quando todos os quadrados vazios jogáveis estiverem preenchidos, o jogador com mais discos na sua cor vencerá o jogo.

### Jogo da Velha

#### Como Jogar

Dois jogadores, usando os marcadores 'X' e 'O', disputam em um tabuleiro 3x3. Os jogadores se alternam escolhendo uma posição para fazer uma nova marcação.

Vence o jogador que conseguir alinhar 3 de seus marcadores em sequência, seja na horizontal, vertical ou diagonal. Se o tabuleiro estiver completamente preenchido e nenhum jogador vencer, o jogo será declarado empate.

## Documentação

A documentação foi feita utilizando o Doxygen. Para acessá-la, abra o arquivo `docs/html/index.html` em seu navegador de preferência ou [clique aqui](https://drefus.github.io/PDS2-Trabalho-Final/html/index.html). Se preferir a documentação em formato de arquivo, acesse `docs/rtf/refman.rtf`.
