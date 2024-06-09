#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void RemoverPratos(void)
{

    extern char pratos[10][50];
    extern char descricao[10][300];
    extern float preco[10];

    bool repeat = true; 
    int i, j, excluir, resp;

    while (repeat == true) // Para repetir ou voltar o menu, escolhendo no final do código
    {

        for (i = 1; i < 10; i++) // Mostra todos os pratos disponíveis
        {
            if (strlen(pratos[i]) != 0) // Verifica se naquela posição possui caracter, se possuir mostra o conteúdo, evitando mostrar campos vazios
            {
                printf("\nPrato numero %d: %s\n", i, pratos[i]);
            }
        }

        printf("Qual numero do prato deseja excluir?"); 
        scanf("%d", &excluir);

        for (i = 1; i < 10; i++)
        {
            if (excluir == i) // Faz a ligação entre a opção digitada e o posição no vetor
            {
                for (j = 0; j < 300; j++) // Laço para percorrer todas as colunas da string
                {
                    pratos[i][j] = '\0'; // Este símbolo é utilizado para zerar caracteres (Caracatere nulo)
                    descricao[i][j] = '\0'; 
                    preco[i] = '0.0';  // Aqui é utilizado o 0.0 para zerar valores numéricos
                    
                    break;
                }
            }
        }

        for (i = 1; i < 10; i++) // Mostra todos os pratos disponíveis
        {
            if (strlen(pratos[i]) != 0) // Verifica se naquela posição possui caracter, se possuir mostra o conteúdo, evitando mostrar campos vazios
            {
                printf("\nPrato numero %d: %s\n", i, pratos[i]);
            }
        }

        do // Laço de repetição para que o usuário apenas posso digitar duas opção (1 ou 2)
        {
            printf("\n O que deseja fazer agora?\n 1 - Remover outro prato \n 2 - Voltar ao menu \n");
            scanf("%d", &resp);

            if (resp == 1)
            {
                repeat = true;
            }
            else if (resp == 2)
            {
                repeat = false;
            }
            else
            {
                printf("Digite uma opcao valida!");
            }
        } while (resp != 1 && resp != 2);
    }
}
