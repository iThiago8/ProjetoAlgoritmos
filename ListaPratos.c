#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void ListaPratos(void)
{
    //Utilizado o extern para acessar as variáveis globais criadas
    extern char pratos[10][50];
    extern char descricao[10][300];
    extern float preco[10];

    int tamanhoArrayNome = sizeof(pratos) / sizeof(pratos[0]); //Faz com que o tamanho da array seja variável, dependendo de quantos pratos existe

    printf("\n");
    printf("*************\n");
    printf("LISTAR PRATOS\n");
    printf("*************\n");
    printf("\n");

    //Loop de repetição para apresentar cada caracatere de cada linha e cada coluna dos nossos vetores
    for (int i = 1; i < tamanhoArrayNome; i++)
    {
        if (strlen(pratos[i]) != 0){ //Verificação se existe algo naquela posição, caso verdadeiro é mostrado o conteúdo
        printf("PRATO NUMERO %d\n", (i));
        printf("Nome do prato %d: %s\n", (i), pratos[i]);
        printf("Descricao do prato %d: %s\n", (i), descricao[i]);
        printf("Preco do prato %d: %.2f\n", (i), preco[i]);
        printf("--------------------------------------\n");
        }
    }

    limpaBufferDeEntrada(); //Chama a função para limpar o caractere de nova linha
    printf("Pressione enter para voltar ao menu inicial\n");
    getchar();
}
