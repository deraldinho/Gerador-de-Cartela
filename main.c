/*
                printf("********************************\n");
                printf("* Nome: Deraldo Palomino Filho *\n");
                printf("* Matricula: 21111385-5        *\n");
                printf("* Curso: BACHARELADO EM        *\n");
                printf("* ENGENHARIA DE SOFTWARE       *\n");
                printf("********************************\n");
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct cartela{
    int casa[10];
}Cartela;


Cartela criar_Cartela();

int main() {
    srand((unsigned)time(NULL));
    setlocale(LC_ALL, "Portuguese");
    printf("Bem vindo ao Cartela Plus!\n");
    printf("Este programa tem como finalidade gerar \nnumeros de cartela para bingo.\n");
    int menu = -1;
    int quantidade;

    while(menu != 0){
        printf("\n----> Menu <-----\n");
        printf("Digite o numero inteiro que representa as opções do menu\n");
        printf("1 - Gerar 1 Cartela de Exemplo\n");
        printf("2 - Gerar uma quantidade finitas de Cartela\n");
        printf("3 - Sortear 1 Numero\n");
        printf("4 - Informações sobre o Desenvolvedor\n");
        printf("0 - Sair do Programa\n");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                Cartela cart = criar_Cartela();
                printf("-----> Cartela de Exemplo <-----\n");
                printf("|------------------------|");
                printf("\n|Casa 1 | Casa 2 | Casa 3|\n");
                printf("|  %d   |  %d    |  %d   |\n",cart.casa[0], cart.casa[1], cart.casa[2]);
                printf("|Casa 4 | Casa 5 | Casa 6|\n");
                printf("|  %d   |  %d    |  %d   |\n",cart.casa[3], cart.casa[4], cart.casa[5]);
                printf("|Casa 7 | Casa 8 | Casa 9|\n");
                printf("|  %d   |  %d    |  %d   |\n",cart.casa[6], cart.casa[7], cart.casa[8]);
                printf("|------------------------|");
                break;
            case 2:
                printf("Por favor informe uma quantidade de cartela para serem geradas: ");
                scanf("%d", &quantidade);
                Cartela * cart1;
                cart1 = malloc(quantidade * sizeof(Cartela));
                for (int i = 0; i < quantidade; ++i) {
                    cart1[i] = criar_Cartela();

                }
                for (int i = 0; i < quantidade; ++i) {
                    printf("\n-----> Cartela de %d <-----\n", i);
                    printf("|------------------------|");
                    printf("\n|Casa 1 | Casa 2 | Casa 3|\n");
                    printf("|  %d   |  %d    |  %d   |\n",cart1[i].casa[0], cart1[i].casa[1], cart1[i].casa[2]);
                    printf("|Casa 1 | Casa 2 | Casa 3|\n");
                    printf("|  %d   |  %d    |  %d   |\n",cart1[i].casa[3], cart1[i].casa[4], cart1[i].casa[5]);
                    printf("|Casa 1 | Casa 2 | Casa 3|\n");
                    printf("|  %d   |  %d    |  %d   |\n",cart1[i].casa[6], cart1[i].casa[7], cart1[i].casa[8]);
                    printf("|------------------------|");
                }
                break;
            case 4:
                printf("********************************\n");
                printf("* Nome: Deraldo Palomino Filho *\n");
                printf("* Matricula: 21111385-5        *\n");
                printf("* Curso: BACHARELADO EM        *\n");
                printf("* ENGENHARIA DE SOFTWARE       *\n");
                printf("********************************\n");
                break;
            case 3:
                int n = rand() % 99;
                printf("%d \n", n);
                break;
            case 0:
                int sair;
                printf("Foi muito bom te ter por aqui ");
                printf("Tchau Amiguinhos rererererere ");

                break;
            default:
                printf("Opção invalida por favor digite somente numeros inteiro que corresponde ao menu\n\n");
                break;
        }
    }
    return 0;
}

Cartela criar_Cartela(){
    Cartela cart;
    int aleatorio;

    for (int i = 0; i < 10; ++i) {
        aleatorio = rand() % 99;
        for (int j = 0; j < 10; ++j) {
            if (cart.casa[j] == aleatorio){
                aleatorio = rand() % 99;
            }
        }
        cart.casa[i] = aleatorio;
    }
    int key, aux;

    for (int i = 1; i < 10; ++i) {
        key = cart.casa[i];
        aux = i - 1;
        while (aux >= 0 && cart.casa[aux] > key){
            cart.casa[aux + 1] = cart.casa[aux];
            aux = aux - 1;
        }
        cart.casa[aux + 1] = key;
    }

    return cart;
}
