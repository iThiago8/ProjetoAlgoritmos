#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void BuscaPorNome(void)
{
    char busca[100];

    printf("Digite o nome que deseja encontrar: ");
    scanf("%s", busca);
}

void BuscaPorDescricao(void)
{
    char busca[100];

    printf("Digite a descricao que deseja encontrar: ");
    scanf("%s", busca);
}


void BuscaPratos(void)
{
    printf("*************\n");
    printf("MODO DE BUSCA\n");
    printf("*************\n");
    printf("\n");

    printf("Deseja buscar por nome ou descricao?\n");
    printf("1 - Nome\n");
    printf("2 - Descricao\n");
    printf("0 - SAIR\n");

    int aux = -1;

    do {
        scanf("%d", &aux);

        switch (aux)
        {
        case 1:
            BuscaPorNome();
            aux = 0;
        break;
    
        case 2:
            BuscaPorDescricao();
            aux = 0;
        break;

        case 0: 
            aux = 0;
        break;

        default:
            printf("Opcao invalida, tente novamente.");
            aux = -1;
        break;
        }
    } while (aux == -1);
}

