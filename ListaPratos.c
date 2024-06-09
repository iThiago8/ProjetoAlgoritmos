#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void ListaPratos(void)
{
    extern char nome[10][50];
    extern char descricao[10][300];
    extern float preco[10];

    int tamanhoArrayNome = sizeof(nome) / sizeof(nome[0]);

    printf("\n");
    printf("*************\n");
    printf("LISTAR PRATOS\n");
    printf("*************\n");
    printf("\n");

    for (int i = 1; i < tamanhoArrayNome; i++)
    {
        printf("PRATO NUMERO %d\n", (i));
        printf("Nome do prato %d: %s\n", (i), nome[i]);
        printf("Descricao do prato %d: %s\n", (i), descricao[i]);
        printf("Preco do prato %d: %.2f\n", (i), preco[i]);
        printf("--------------------------------------\n");

    }
}