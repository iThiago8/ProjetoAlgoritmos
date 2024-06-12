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


//Bloco de código referente à busca da palavra digitada nos pratos
void BuscaPorNome(void)
{
    //Utilizado o extern para acessar as variáveis globais criadas
    extern char pratos[10][50];
    extern char descricao[10][300]; 
    extern float preco[10];

    char busca[100];

    printf("Digite o prato que deseja encontrar: ");
    scanf("%s", busca);

    int tamanhoArray = (sizeof(pratos) / sizeof(pratos[0])); //Faz com que o tamanho da array seja variável, dependendo de quantos pratos existe
    bool pratoEncontrado = false;

    for (int i = 0; i < tamanhoArray; i++)
    {
        char pratosMinusculo[100];
        char buscaMinuscula[100];

        Str_minuscula(pratosMinusculo, pratos[i]); //Transforma todas as letras em minúsculo dos pratos
        Str_minuscula(buscaMinuscula, busca); //Transforma todas as letras em minúsculo da palavra pesquisada

        if (strstr(pratosMinusculo, buscaMinuscula) != NULL) //Verifica se Há alguma palavra pesquisada presente nos nossos pratos
        {
            printf("Pratos encontrados:\n");
            printf("Nome: %s\n", pratos[i]);
            printf("Descricao: %s\n", descricao[i]);
            printf("Preco: %.2f\n", preco[i]);
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

        // Chama a função de Busca caso o usuário digite 1, para o programa caso 2 ou opção inválida caso outro número
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


//Bloco de código referente à busca da palavra digitada nos pratos
void BuscaPorDescricao(void)
{
    extern char pratos[10][50];
    extern char descricao[10][300];
    extern float preco[10];

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
            printf("Preco: %.2f\n", preco[i]);
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

//Interface da busca por pratos e utilização das funções criadas acima
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
        printf("Deseja buscar por pratos ou descricao?\n");
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
