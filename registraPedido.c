#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void limpaBufferDeEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void RegistraPedido(void) {
    printf("\n");
    printf("*******************\n");
    printf("REGISTRO DE PEDIDOS\n");
    printf("*******************\n");
    printf("\n");

    printf("Aperte enter para listar os pratos cadastrados\n");
    limpaBufferDeEntrada();  
    getchar();

    ListaPratos();

    bool loop = true;
    int quantidadeTotalDePratos = 0;
    char pratosPedidos[10][50];  
    int quantidadesEscolhidas[10] = {0};  

    float precoTotalPedido = 0;
    do {
        int pratoEscolhido = 0;
        int quantidade = 0;

        printf("Digite o numero do prato escolhido: ");
        scanf("%d", &pratoEscolhido);

        limpaBufferDeEntrada();

        printf("Quantos desse prato serao pedidos? (Digite apenas o numero): ");
        scanf("%d", &quantidade);
        limpaBufferDeEntrada();

        strcpy(pratosPedidos[quantidadeTotalDePratos], nome[pratoEscolhido]);
        quantidadesEscolhidas[quantidadeTotalDePratos] = quantidade;
        quantidadeTotalDePratos++;

        precoTotalPedido += preco[pratoEscolhido] * quantidade;

        int decisao = 0;
        printf("Deseja adicionar mais um prato?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        scanf("%d", &decisao);
        limpaBufferDeEntrada();

        if (decisao == 2) 
            loop = false;

    } while (loop);

    if (quantidadeTotalDePratos == 1)
        printf("Foi escolhido %d prato, sendo seu nome e quantidade: \n", quantidadeTotalDePratos);
    else
        printf("Foram escolhidos %d pratos, sendo seus nomes e quantidades: \n", quantidadeTotalDePratos);

    for (int i = 0; i < quantidadeTotalDePratos; i++) {
        printf("Nome do prato: %s\n", pratosPedidos[i]);
        printf("Quantidade do prato: %d\n", quantidadesEscolhidas[i]);
        printf("-------------------------------\n");
    }

    printf("Preco total do pedido: R$%.2f\n", precoTotalPedido);
    printf("Pressione enter para voltar ao menu inicial\n");
    getchar();
}