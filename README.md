# Trabalho Final da disciplina de PDS2
## Instruções de execução:
Para executar o código, em uma ambiente Linux dentro do diretório do projeto. Use o comando **make all** para gerar o arquivo compilado. Após a execução execute o arquivo bin/tp.out.

## Instruções para jogar:
Escolha uma das opções do menu,o que cada uma delas faz está citado abaixo. Caso deseje sair do menu digite **E** .
### Gerenciamento de jogadores:
>Para isso escolha a opção 1 do menu
> #### Adição de jogador:
> Escolha a opção 1 do menu de gerencia de jogadores ao passar um nome e um apelido único para o jogador o jogador sera criado.
>#### Remoção de jogador:
>  Escolha a opção 2 do menu de gerencia de jogadores ao passar um nome ou um apelido valido o jogador será removido.
>#### Listar estatísticas de jogador:
>  Escolha a opção 3 do menu de gerencia de jogadores ao passar um nome ou um apelido valido. Assim aparecerá na tela as estatísticas do jogador. Observação: so aparecerá estatísticas de jogos que ele ja jogou então   se o usuário não tiver jogado nenhum jogo so aparecera o nick dele.
>#### Listar estatísticas de todos jogadores:
>  Escolha a opção 4 do menu de gerencia de jogadores. Assim aparecerá na tela todas as estatísticas de todos jogadores. Observação: so aparecerá estatísticas de jogos que ele ja jogou então se o usuário não tiver jogado nenhum jogo so aparecera o nick dele.
>#### Sair:
> Caso deseje sair do menu digite **E** .
 
## Documentação:
A documentação foi feita utilizando o doxygen. Para acessar ela abra o arquivo docs/index/index.html em seu navegador de preferencia ou [Clique  aqui](https://drefus.github.io/PDS2-Trabalho-Final/index/index.html). Se preferir a documentação em formatato de arquivo, acesse o arquivo docs\rtf\refman.rtf.

## Instruções para os jogos:

### Lig4

#### Começando o jogo:
>Insira o apelido do 1º e em seguida do 2º jogador

#### Como jogar: 
>O objetivo dos jogadores é de unir 4 peças da sua cor, seja na vertical, horizontal ou diagonal.

>Para uma jogada ser válida ela deve ser um dos números inteiros de 1 a 7 e a respectiva coluna não pode estar totalmente preenchida ainda.

>Quando o jogador escolher uma coluna sua peça ira para primeira linha (de cima para baixo) que esteja vazia.

>A primeira jogada é do jogador 1 (time vermelho: V) e em diante os jogadores vermelho e azul irão revezar as jogadas.

>O vencedor será aquele que unir as 4 peças primeiro e cada jogador recebe uma vitória ou derrota

>Caso o tabuleiro esteja totalmente completo e nenhum dos jogadores tenham vencido ocorre um empate.

### Damas

#### Como jogar :
>O jogo de damas é praticado entre dois parceiros, com 12 pedras 'O' de um lado e com 12 pedras 'X' de outro lado. O lance inicial cabe sempre a quem estiver com as peças 'O'.

>A pedra anda só para frente, uma casa de cada vez. Quando a pedra atinge a oitava linha do tabuleiro ela é promovida à dama. Para identificá-la coloca-se '@' para as peças 'O' e '*' para as peças 'X'.

>A dama é uma peça de movimentos mais amplos. Ela anda para frente e para trás, quantas casas quiser. A dama não pode saltar uma peça da mesma cor.

>A captura é obrigatória. Não existe sopro. Duas ou mais peças juntas, na mesma diagonal, não podem ser capturadas.

>A pedra captura a dama e a dama captura a pedra. A pedra e a dama podem capturar tanto para frente como para trás, uma ou mais peças

>Se no mesmo lance se apresentar mais de um modo de capturar, é obrigatório executar o lance que capture o maior número de peças (Lei da Maioria).

>A pedra que durante o lance de captura de várias peças, apenas passe por qualquer casa de coroação, sem aí parar, não será promovida à dama.

>Na execução do lance de captura, é permitido passar mais de uma vez pela mesma casa vazia, não é permitido capturar duas vezes a mesma peça.

#### Como realizar as jogadas:
>Primeiro você deve selecionar a peça que deve executar a ação, para tal deve indicar qual a sua posição no tabuleiro.

>Deve-se indicar respectivamente em qual Linha e em qual Coluna a peça está.

>É de suma importância que as informações referentes às posições das peças sejam passadas em letra maiúscula e na ordem LinhaColuna.

>Posteriormente, para finalizar o seu turno, deve indicar para qual casa a peça deve se mover.

>Se a sua jogada for comer apenas uma peça, basta apenas colocar a casa final da peça movimentada.

>Em caso de comer múltiplas peças, se a peça inicial for uma pedra comum, ela irá comer as múltiplas peças automaticamente, mas em caso de dama, após a primeira peça, todas as outras você deve indicar para qual posição sua dama deve ir, priorizando sempre que coma alguma peça.

#### Como ganhar:
>A única condição de vitória do jogo é que algum jogador coma todas as peças inimigas.

### Reversi

#### Começando o jogo:
>Insira o apelido do 1º e em seguida do 2º jogador

#### Como jogar:
>Dois jogadores competem, usando 64 peças idênticas que são claras de um lado e escuras do outro. Cada jogador escolhe uma cor para usar durante o jogo. 

>Os jogadores se revezam colocando um disco em um quadrado vazio, com a cor atribuída voltada para cima. 

>Depois que uma jogada é feita, quaisquer discos da cor do oponente que estejam em linha reta delimitada por aquele que acabou de ser jogado e outro da cor do jogador atual são virados. 

>Quando todos os quadrados vazios jogáveis ​​forem preenchidos, o jogador com mais discos exibidos em sua própria cor ganha o jogo.

### Jogo Da Velha

#### Como jogar:
>Dois jogadores com os marcadores 'X' e 'O' disputam num tabuleiro 3x3.

>Os jogadores se alternam escolhendo a posição para fazer uma nova marcação.

>Vence quem conseguir deixar 3 dos seus marcadores em sequência, podendo ser na horizontal, vertical ou diagonal.

>Caso nenhum dos dois jogadores consiga vencer e o tabuleiro estiver todo marcado, então terá sido um empate.

