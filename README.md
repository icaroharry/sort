sort
====

Repository of sorting algorithms in C and CUDA.


## Compiling

``` bash
gcc -c jogador.c -o jogador.o

gcc -c pong.c

gcc pong.o -o pong $(pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_primitives-5.0) jogador.p

./pong
```




## Instructions
> Our program generates and fills arrays in four different ways: 
  > 1. arrays with totally random elements
  2. arrays already ordered 
  3.arrays ordered in descending order 
  4. arrays 90%   ordered.
	
  > **Comandos**
  - Controle com as setas para cima e para baixo (UP and DOWN);
  - Para sacar, pressione espaço.
  
  
  
## Módulo ["jogador.h"](https://github.com/icaroharry/pong/blob/master/jogador.c)
> Struct que define um jogador.
currentScore e currentDefenses são variáveis auxiliares para armazenar a pontuação do jogador durante o jogo.


``` c
typedef struct Player {
	char login[8];
    char password[8];
    char name[100];
    int age;
    int bestScore;
    int wins;
    int currentScore;
    int currentDefenses;
} Player;
```

> Função que criptografa a senha, alterando os caracteres pelo seu código ascii.

``` c
char* encrypt(char* password);
```

> Função que descriptografa a senha, alterando os caracteres pelo seu código ascii original.

``` c
char* decrypt(char* password);
```

> Função que pede o login ou realiza cadastro, de acordo com a opção do usuário.
Retorna o Player logado.

``` c
Player requireLogin();
```

> Função que procura o jogador na base de dados pelo seu login.
Retorna o Player se econtrou, ou um Player vazio se não encontrou.

``` c
char* getPlayer(char* login);
```

> Função que percorre a base de dados conferindo se existe o player que está logando. Se existir verifica se a senha está correta. Retorna 1 se estiver ou -1 se o usuário não for encontrado ou a senha estiver incorreta.

``` c
int logIn(char* login, char* password);
```

> Função que verifica se existe algum usuário com o login inserido;
Retorna 1 se existir ou -1 se não existir.

``` c
char* existsPlayer(char* login);
```
  
> Função que salva um Player na base de dados.

``` c
void savePlayerToDatabase(Player player);
```










