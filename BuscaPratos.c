#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Função para converter uma string para minúsculas
void Str_minuscula(char *strMinuscula, const char *strOriginal)
{
    while (*strOriginal)
    {
        *strMinuscula = tolower((unsigned char)*strOriginal);
        strMinuscula++;
        strOriginal++;
    }
    *strMinuscula = '\0'; // Finaliza a string com o caractere nulo
}

void BuscaPorNome(void)
{
    char pratos[50][100] = {"Macarrao", "Sopa", "Arroz e feijao", "Arroz seco"};
    char descricao[50][100] = {"gelado", "quente", "cru", "quentinho"};
    char precos[50][100] = {"14,25", "13,00", "12,34", "69,23"};

    char busca[100];

    printf("Digite o nome que deseja encontrar: ");
    scanf("%s", busca);

    int tamanhoArray = (sizeof(pratos) / sizeof(pratos[0]));
    bool pratoEncontrado = false;

    for (int i = 0; i < tamanhoArray; i++)
    {
        char pratosMinusculo[100];
        char buscaMinuscula[100];

        Str_minuscula(pratosMinusculo, pratos[i]);
        Str_minuscula(buscaMinuscula, busca);

        if (strstr(pratosMinusculo, buscaMinuscula) != NULL)
        {
            printf("Pratos encontrados:\n");
            printf("Nome: %s\n", pratos[i]);
            printf("Descricao: %s\n", descricao[i]);
            printf("Preco: %s\n", precos[i]);
            printf("----------------------------\n");
            pratoEncontrado = true;
        }
    }

    if (pratoEncontrado == false)
        printf("Prato nao encontrado!\n");

    bool loop = true;
    do
    {
        printf("O que deseja fazer?\n");
        printf("1 - Pesquisar outro prato\n");
        printf("2 - Sair\n");

        int decisao;
        scanf("%d", &decisao);
        switch (decisao)
        {
        case 1:
            BuscaPorNome();

            loop = false;
            break;

        case 2:
            printf("Voce escolheu sair.\n");
            printf("\n");

            loop = false;
            break;

        default:
            printf("Opcao invalida, tente novamente.\n");
            printf("\n");

            loop = true;
            break;
        }
    } while (loop);
}

void BuscaPorDescricao(void)
{
    char pratos[50][100] = {"Macarrao", "Sopa", "Arroz e feijao", "Arroz seco"};
    char descricao[50][100] = {"gelado", "quente", "cru", "quentinho"};
    char precos[50][100] = {"14,25", "13,00", "12,34", "69,23"};

    char busca[100];

    printf("Digite a descricao que deseja encontrar: ");
    scanf("%s", busca);

    int tamanhoArray = (sizeof(descricao) / sizeof(descricao[0]));
    bool pratoEncontrado = false;

    for (int i = 0; i < tamanhoArray; i++)
    {
        char descricaoMinuscula[100];
        char buscaMinuscula[100];

        Str_minuscula(descricaoMinuscula, descricao[i]);
        Str_minuscula(buscaMinuscula, busca);

        if (strstr(descricaoMinuscula, buscaMinuscula) != NULL)
        {
            printf("Pratos encontrados:\n");
            printf("Nome: %s\n", pratos[i]);
            printf("Descricao: %s\n", descricao[i]);
            printf("Preco: %s\n", precos[i]);
            printf("----------------------------\n");
            pratoEncontrado = true;
        }
    }
    if (pratoEncontrado == false)
        printf("Prato nao encontrado!\n");

    bool loop = true;
    do
    {
        printf("O que deseja fazer?\n");
        printf("1 - Pesquisar outro prato\n");
        printf("2 - Sair\n");

        int decisao;
        scanf("%d", &decisao);

        switch (decisao)
        {
        case 1:
            BuscaPorDescricao();

            loop = false;
            break;

        case 2:
            printf("Voce escolheu sair.\n");
            printf("\n");

            loop = false;
            break;

        default:
            printf("Opcao invalida, tente novamente.\n");
            printf("\n");

            loop = true;
            break;
        }
    } while (loop);
}

void BuscaPratos(void)
{
    printf("\n");
    printf("*************\n");
    printf("MODO DE BUSCA\n");
    printf("*************\n");
    printf("\n");

    int aux = -1;

    do
    {
        printf("Deseja buscar por nome ou descricao?\n");
        printf("1 - Nome\n");
        printf("2 - Descricao\n");
        printf("0 - SAIR\n");

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
            printf("Opcao invalida, tente novamente.\n");
            aux = -1;
            break;
        }
    } while (aux == -1);
}
