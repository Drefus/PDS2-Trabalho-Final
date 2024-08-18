# Trabalho Final da disciplina de PDS2
## Instuções de execução:
Para executar o codigo, em uma ambiente linux dentro do diretorio do projeto. Use o comando **make all** para gerar o arquivo compilado. Após a execução execute o arquivo bin/tp.out.

## Instruções para jogar:
Escolha uma das opções do menu,o que cada uma delas faz está citado abaixo. Caso deseje sair do menu digite **E** .
### Gerenciamento de jogadores:
>Para isso escolha a opção 1 do menu
> #### Adição de jogador:
> Escolha a opção 1 do menu de gerencia de jogadores ao passar um nome e um apelido unico para o jogador o jogador sera criado.
>#### Remoção de jogador:
>  Escolha a opção 2 do menu de gerencia de jogadores ao passar um nome ou um apelido valido o jogador será removido.
>#### Listar estatisticas de jogador:
>  Escolha a opção 3 do menu de gerencia de jogadores ao passar um nome ou um apelido valido. Assim aparecerá na tela as estatisticas do jogador. Observação: so aparecerá estatisticas de jogos que ele ja jogou então   se o usurio não tiver jogado nenhum jogo so aparecera o nick dele.
>#### Listar estatisticas de todos jogadores:
>  Escolha a opção 4 do menu de gerencia de jogadores. Assim aparecerá na tela todas as estatisticas de todos jogadores. Observação: so aparecerá estatisticas de jogos que ele ja jogou então se o usurio não tiver jogado nenhum jogo so aparecera o nick dele.
>#### Sair:
> Caso deseje sair do menu digite **E** .
 
## Documentação:
A documentação foi feita utilizando o doxygen. Para acessar ela abra o arquivo docs/index/index.html em seu navegador de preferencia ou [Clique  aqui](https://drefus.github.io/PDS2-Trabalho-Final/index/index.html). Se preferir a documentação em formatato de arquivo, acesse o arquivo docs\rtf\refman.rtf.

## Instruções para o LIG4:

### Começando o jogo:
>Insira o apelido do 1º e em seguida do 2º jogador

### Como jogar: 
>O objetivo dos jogadores é de unir 4 peças da sua cor, seja na vertial, horizontal ou diagonal.
>Para uma jogada ser válida ela deve ser um dos números inteiros de 1 a 7 e a respectiva coluna não pode estar totalmente preenchida ainda.
>Quando o jogador escolher uma coluna sua peça ira para primeira linha (de cima para baixo) que esteja vazia.
>A primeira jogada é do jogador 1 (time vermelho: V) e em diante os jogadores vermelho e azul irão revezar as jogadas.
>O vencedor será aquele que unir as 4 peças primeiro e cada jogador recebe uma vitória ou derrota
>Caso o tabuleiro esteja totalmente completo e nenhum dos jogadores tenham vencido ocorre um empate.

