#include <stdio.h>
#include <stdlib.h>

int blackjack(int mao){
    char resp;
    int valor;
    valor = 1 + (rand() % 13);
    mao+=valor;

    printf("SUA MAO: %d\n",mao);
    printf("Deseja mais uma carta? (S ou N)\n");
    fflush(stdin);
    scanf("%c",&resp);
    do {
        valor = 1 + (rand() % 13);
        printf("Carta recebida: %d\n",valor);
        mao+=valor;
        printf("SUA MAO: %d\n",mao);

        if (mao>21){
            printf("Voce perdeu!\n");
            resp='n';
        }
        else if(mao<21){
            printf("Deseja mais uma carta? (S ou N)\n");
            fflush(stdin);
            scanf("%c",&resp);
        }

    }while(resp=='S' || resp=='s');
    return mao;
}

int banca(int valor){
    valor=0;
    while(valor<=15){
        valor+= 1 + (rand() % 13);
    }
    printf("\nBanca: %d\n",valor);
    return valor;
}


int main() {
    int mat[4], qntd, i = 0, mao = 0, banc = 0;

    printf("------- BlackJack --------\n");
    printf("Para comecar jogar precisamos definir alguns parametros!\n");
    printf("Quantas pessoas irao jogar? (MAX 3)\n->");
    scanf("%d", &qntd);
    while (qntd > 3) {
        printf("Quantidade de jogadores nao suportada!\n");
        printf("Digite novamente quantas pessoas irao jogar? (MAX 3)\n->");
        scanf("%d", &qntd);
    }
    system("cls");
    printf("------- BlackJack --------\n");
    printf("Ok, %d irao jogar!\n", qntd);
    printf("Para comecar precione qualquer tecla!\n");
    system("pause");
    system("cls");

    while (i < qntd) {
        printf("\n-------------\nVez do jogador %d\n-------------\n", i + 1);
        mat[i] = blackjack(mao);
        i++;
    }

    mat[4] = banca(banc);

    for (i = 0; i < qntd; i++) {
        if (mat[4] > 21 && mat[i] <= 21) {
            printf("JOGADOR [%d]: O jogador ganhou!\n", i + 1);
        }
        else if(mat[i]>21){
            printf("JOGADOR [%d]: A banca ganhou!\n", i + 1);
        }
        else if (mat[4] == 21) {
            printf("JOGADOR [%d]: A banca ganhou!\n", i + 1);
        } else if (mat[4] <= 21 && mat[i] < mat[4]) {
            printf("JOGADOR [%d]: A banca ganhou!\n", i + 1);
        } else if (mat[4] == mat[i]) {
            printf("JOGADOR [%d]: A banca ganhou!\n", i + 1);
        }

    }
    return 0;
}
