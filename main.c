#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"
int main()
{
    //declarando variáveis
    char jogo[6][7];
    int i;
    int j;
    int count=0;
    int info=3;
    int pontuacao1=100;
    int pontuacao2=100;
    int count1=1;
    int count2=1;
    int ganhou=0;
    char player1[100];
    char player2[100];
    char jogada='y';

            //"MENU"
            while((0>=info)|| (3<=info))
            {
                system("cls");
                printf("Aperte 1 para aprender a jogar e 2 para comecar a jogar: ");
                scanf("%d",&info);

                //INFORMAÇÃO DO JOGO
                if (info==1)
                {
                    information();
                    info=3;
                }
                //COMEÇAR O JOGO
                else if(info==2)
                {
                    while(jogada=='y')
                    //>> ESTRUTURA DE REPETIÇÃO JOGAR NOVAMENTE <<
                    {
                    count++;
                        //INICIALIZANDO O JOGO = ZERANDO COLUNAS E LINHAS
                        for (i=0;i<6;i++)
                        {
                            for (j=0;j<7;j++)
                            {
                                jogo[i][j]=' ';
                            }
                        }
                        //LENDO NOME DOS JOGADORES
                        system("cls");
                    	printf("Digite o nome do player 1: ");
                        fflush(stdin);
                        gets(player1);
                        printf("Digite o nome do player 2: ");
                        fflush(stdin);
                        gets(player2);

                        //MOSTRAR JOGO
                        system("cls");
                        printf("\n\n    | 1 | 2 | 3 | 4 | 5 | 6 | 7");
                        printf("\n    -----------------------------");
                        for(i=5;i>=0;i--)
                        {

                            printf("\n%d ->",i+1);
                            for (j=0;j<7;j++)
                            {
                                printf("| %c ",jogo[i][j]);
                            }
                            printf("\n    -----------------------------");
                        }
                        //ESTRUTURA DE REPETIÇÃO (ENQUANTO NÃO GANHOU)
                        while(ganhou==0)
                        {
                            //IDENTIFICANDO JOGADA (PLAYER 1)
                            if (count%2==1)
                            {
                            count++;
                            info=3;

                            //RECEBENDO JOGADA
                            while(info==3)
                            {
                                j=9;
                                while((j>=8) || (j<=0))
                                {
                                printf("\n\nJogada de %s! Escolha a coluna: ",player1);
                                scanf("%d",&j);
                            }
                            j--;
                            for (i=0;i<6;i++)
                            {
                                //IDENTIFICANDO JOGADA VALIDA
                                if((jogo[i][j]==' ') || (i>6))
                                {
                                    jogo[i][j]='x';
                                    if(jogo[i][j]=='x')
            					   {
            					       i=7;
            					       info=2;
            					   }
                                }
                            }
                        }
                        //MOSTRANDO JOGO
                        system("cls");
                        printf("\n\n    | 1 | 2 | 3 | 4 | 5 | 6 | 7");
                        printf("\n    -----------------------------");
                        for(i=5;i>=0;i--)
                        {

                            printf("\n%d ->",i+1);
                            for (j=0;j<7;j++)
                            {
                                printf("| %c ",jogo[i][j]);
                            }
                            printf("\n    -----------------------------");
                        }
                        //IDENTIFICANDO SE GANHOU
                        //ganhou(&jogo);
                        for (i=0;i<6;i++)
                        {
                            for (j=0;j<7;j++)
                            {
                                if(ganhou==0)
                                {
                                    if(jogo[i][j]=='x')
                                    {
                                        if(jogo[i+1][j]=='x')
                                        {
                                            if(jogo[i+2][j]=='x')
                                            {
                                                if(jogo[i+3][j]=='x')
                                                {
                                                    ganhou=1;
                                                }
                                            }
                                        }
                                        else if(jogo[i+1][j+1]=='x')
                                        {
                                            if(jogo[i+2][j+2]=='x')
                                            {
                                                if(jogo[i+3][j+3]=='x')
                                                {
                                                    ganhou=1;
                                                }
                                            }
                                        }
                                        else if(jogo[i][j+1]=='x')
                                        {
                                            if(jogo[i][j+2]=='x')
                                            {
                                                if(jogo[i][j+3]=='x')
                                                {
                                                    ganhou=1;
                                                }
                                            }
                                        }
                                        else if(jogo[i+1][j-1]=='x')
                                        {
                                            if(jogo[i+2][j-2]=='x')
                                            {
                                                if(jogo[i+3][j-3]=='x')
                                                {
                                                    ganhou=1;
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    i=7;
                                }
                            }
                        }
                        //MOSTRANDO PONTUAÇÃO
                        if(ganhou==1)
                        {
                            pontuacao1=100;
                            pontuacao1=(pontuacao1+(100*count1)+(42000/count1));
                            printf("\n\n\nParabens %s, voce ganhou! Sua pontuacao foi: %d",player1, pontuacao1);
                            pontuacao2=100;
                            pontuacao2=(pontuacao2+(100*count2));
                            printf("\n\n%s perdeu! Teve pontuacao: %d",player2, pontuacao2);

                            FILE *PontArquivo;
                            PontArquivo = fopen("rec.txt", "wt");
                            fwrite(1, player1, pontuacao1,1);
                            fclose(PontArquivo);

                            FILE *PontArquivo;
                            PontArquivo = fopen("rec.txt", "wt");
                            fprintf(pos,player1[a], pontuacao1[a]);
                            fclose(PontArquivo);

                        }
                        else
                        {
                            pontuacao1=100;
                            pontuacao1=(pontuacao1+(100*count1)+(42000/count1));
                            printf("\n\n\nQue pena, se tivesse ganhado sua pontuacao seria: %d",pontuacao1);
                            pontuacao1=100;
                            pontuacao1=(pontuacao1+(100*count1));
                            printf("\n\nComo nao ganhou, sua pontuacao atual e: %d\n\n",pontuacao1);
                            count1++;
                        }
                    }
                    //IDENTIFICANDO VEZ DE JOGAR (PLAYER 2)
                    else if((ganhou==0) || (count%2==0))
                    {
                        count++;
                        info=3;

                        //IDENTIFICANDO JOGADA VÁLIDA
                        while(info==3)
                        {
                            j=9;
                            while((j>=8) || (j<=0))
                            {
                                printf("\n\nJogada de %s! Escolha a coluna: ",player2);
                                scanf("%d",&j);
                            }
                            j--;
                            for (i=0;i<6;i++)
                            {
                                if((jogo[i][j]==' ') || (i>6))
                                {
                                    jogo[i][j]='o';
                                    if(jogo[i][j]=='o')
            					       {
            					           i=7;
            					           info=2;
            					       }
                                }
                            }
                        }
                        //MOSTRANDO JOGO
                        system("cls");
                        printf("\n\n    | 1 | 2 | 3 | 4 | 5 | 6 | 7");
                        printf("\n    -----------------------------");
                        for(i=5;i>=0;i--)
                        {

                            printf("\n%d ->",i+1);
                            for (j=0;j<7;j++)
                            {
                                printf("| %c ",jogo[i][j]);
                            }
                            printf("\n    -----------------------------");
                        }
                        //IDENTIFICANDO SE GANHOU
                        for (i=0;i<6;i++)
                        {
                            for (j=0;j<7;j++)
                            {
            					if(ganhou==0)
            					{
            						if(jogo[i][j]=='o')
            						{
            							if(jogo[i+1][j]=='o')
            							{
            								if(jogo[i+2][j]=='o')
            								{
            									if(jogo[i+3][j]=='o')
            									{
            										ganhou=2;
            									}
            								}
            							}
            							else if(jogo[i+1][j+1]=='o')
            							{
            								if(jogo[i+2][j+2]=='o')
            								{
            									if(jogo[i+3][j+3]=='o')
            									{
            										ganhou=2;
            									}
            								}
            							}
            							else if(jogo[i][j+1]=='o')
            							{
            								if(jogo[i][j+2]=='o')
            								{
            									if(jogo[i][j+3]=='o')
            									{
            										ganhou=2;
            									}
            								}
            							}
            							else if(jogo[i+1][j-1]=='o')
            							{
            								if(jogo[i+2][j-2]=='o')
            								{
            									if(jogo[i+3][j-3]=='o')
            									{
            										ganhou=2;
            									}
            								}
            							}
            						}
            					}
            					else
            					{
            						i=7;
            					}
                            }
            			}
                        //MOSTRANDO PONTUAÇÃO
                        if(ganhou==2)
                        {
                            pontuacao2=100;
                            pontuacao2=(pontuacao2+(100*count2)+(42000/count2));
                            printf("\n\n\nParabens %s, voce ganhou! Sua pontuacao foi: %d",player2, pontuacao2);
                            pontuacao1=100;
                            pontuacao1=(pontuacao1+(100*count1));
                            printf("\n\n%s perdeu! Teve pontuacao: %d",player1, pontuacao1);
                        }
                        else
                        {
                            pontuacao2=100;
                            pontuacao2=(pontuacao2+(100*count2)+(42000/count2));
                            printf("\n\n\nQue pena, se tivesse ganhado sua pontuacao seria: %d",pontuacao2);
                            pontuacao2=100;
                            pontuacao2=(pontuacao2+(100*count2));
                            printf("\n\nComo nao ganhou, sua pontuacao atual e: %d\n\n",pontuacao2);
                            count2++;
                        }
                    }
            	}
                //>> ESTRUTURA DE REPETIÇÃO JOGAR NOVAMENTE <<
                jogada='z';
                while((jogada!='y') && (jogada!='n'))
                {
                    printf("\n\n\nSe quiser jogar novamente digite a tecla [y], se nao, digite a tecla[n]: ");
                    setbuf(stdin,NULL);
                    scanf("%c",&jogada);
                }
                if(jogada=='y')
                {
                    ganhou=0;
                }
            }
        }
    }
 return 0;
}

