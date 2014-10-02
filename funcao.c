#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"

//INFORMAÇÃO DO JOGO
void information (){
        system("cls");
        printf("INFORMACAO\n");
        printf("O jogo eh bem simples!\nVoce deve escolher uma coluna (de 1 a 7) para jogar o ""elemento.""\n");
        printf("A sua jogada tera como lugar a ultima posicao da coluna.\n");
        printf("O player 1 tera como elemento (x) e o player 2 como elemento (o).\n");
        printf("Quem conseguir realizar primeiro uma sequencia de 4 ""elementos:\n" "na diagonal, na vertical, ou na horizontal vence o jogo.\n");
        printf("Todos começam com um total de 100 pontos.\n");
        printf("Cada jogada soma-se mais 100 pontos.\n");
        printf("O ganhador tera 42000, que serao dividos pela quantidade de vezes que jogou.\n");
        printf("Ou seja, quantos menos jogadas mais pontos!\n");
        printf("Agora vamos jogar?\n");
        system("pause");
}