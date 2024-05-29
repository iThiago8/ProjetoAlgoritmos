#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void main (void)
{
    setlocale(LC_ALL, "Portuguese");



    bool loop = true;
    do {
        int decisao = 0;
        printf("Seja bem vindo ao nosso sistema! O que deseja fazer?\n");
        printf("1 - Cadastro de Pratos\n");
        printf("2 - Remoção de Pratos\n");
        printf("3 - Busca de Pratos\n");
        printf("4 - Listagem de Pratos\n");
        printf("5 - Registrar um pedido\n");
        printf("0 - SAIR\n");

        scanf ("%d", &decisao);

        switch (decisao)
        {
            case 1:
                
            break;
        
            case 2:
                /* code */
            break;

            case 3:
                /* code */
            break;

            case 4:
                /* code */
            break;

            case 5:
                /* code */
            break;

            case 0:
                loop = false;
            break;
        
            
            default:
                printf("Opção escolhida inválida! Por favor tente novamente");
                loop = true;
            break;
        }
    } while (loop);
}