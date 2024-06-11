#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void RegistraPedido(void) {

    //Utilizado o extern para acessar as variáveis globais criadas
    extern char pratos[10][50];
    extern float preco[10];
    int c;

    printf("\n");
    printf("*******************\n");
    printf("REGISTRO DE PEDIDOS\n");
    printf("*******************\n");
    printf("\n");

    printf("Aperte enter para listar os pratos cadastrados\n"); 
    while ((c = getchar()) != '\n' && c != EOF) { }  //Apagar o caractere de nova linha (\n) para que não interfira no getchar
    getchar();

    ListaPratos(); //Chama a função de listagem já criada em outro arquivo

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

        limpaBufferDeEntrada(); //Chama a função para limpar o caractere de nova linha

        printf("Quantos desse prato serao pedidos? (Digite apenas o numero): ");
        scanf("%d", &quantidade);
        limpaBufferDeEntrada();

        /*Quando o usuário digitar o número do prato, a posição do array escolhida vai ser copiada para o novo array de pedidos(quantidadeTotaldePratos),
        fazendo assim uma nova lista de pratos, mas apenas com o que o usuário escolheu e a quantidade de cada */
        strcpy(pratosPedidos[quantidadeTotalDePratos], pratos[pratoEscolhido]); 
        quantidadesEscolhidas[quantidadeTotalDePratos] = quantidade;
        quantidadeTotalDePratos++;

        precoTotalPedido += preco[pratoEscolhido] * quantidade; //Faz o cálculo dos preços de cada prato e quantidade

        int decisao = 0;
        printf("Deseja adicionar mais um prato?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        scanf("%d", &decisao);
        limpaBufferDeEntrada();

        if (decisao == 2) 
            loop = false;

    } while (loop);

    //A partir desta linha é mostrado o resultado de todas as funções e códigos acima (Nome dos pratos escolhidos, quantidade e preços totais)
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
