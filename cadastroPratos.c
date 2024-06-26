#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Cria a função para limpar o caractere de nova linha para que não interfira nos getchar, fgets e nas outras leituras de entrada utilizadas
void limpaBufferDeEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

char pratos[10][50] = {"Ajuste", "Sorvete", 0, 0, 0, 0, 0, 0, 0, 0};          // Inicializo o vetor com valores prédefinidos
char descricao[10][300] = {"Ajuste", "Bem gelado", "", "", "", "", "", "", "", ""}; // Ajuste é para começar a mostrar os pratos na posição 1
float preco[10] = {1, 19.90, 0, 0, 0, 0, 0, 0, 0, 0};

void CadastroPratos(void)
{

    
    bool repeat = true;
    int i, resp;

    while (repeat == true) // Para repetir ou voltar o menu, escolhendo no final do código
    {
        
        for (i = 1; i < 10; i++)
        { // Laço de repetição para adicionar um prato na lista
            if (strlen(pratos[i]) == 0) // Verifica se o índice está vazio para ser preenchido, evitando sobrescrever algum prato
            { 
                printf("Adicione o nome do prato: ");
                limpaBufferDeEntrada();
                fgets(pratos[i], 50, stdin); // Lê uma linha inteira da entrada, incluindo o caractere de nova linha, permitindo escrever mais de uma palavra

                size_t len = strlen(pratos[i]); // Armazena o tamanho da string

                if (len > 0 && pratos[i][len - 1] == '\n') // Remove o caractere de nova linha do final da string, se presente
                {
                    pratos[i][len - 1] = '\0';
                }

                break; // Comando utilizado para adicionar apenas um prato por vez
            }
        }

        for (i = 1; i < 10; i++)
        { // Laço de repetição para incluir a descrição do prato

            if (strlen(descricao[i]) == 0)
            {

                printf("Adicione a descricao do prato: ");
                fgets(descricao[i], 50, stdin);

                size_t len = strlen(descricao[i]); // Grava o comprimento da string

                if (len > 0 && descricao[i][len - 1] == '\n')
                {
                    descricao[i][len - 1] = '\0'; // len - 1 é utilizado pois o strlen conta a partir do um e os vetores em c são iniciados em zero, logo diminuindo um, ele faz a referência correta do último caractere
                }
                break;
            }
        }

        for (i = 1; i < 10; i++)
        { // Laço de repetição para incluir o preço do prato

            if (preco[i] == 0)
            {
                printf("Adicione o preco do prato: ");
                scanf("%f", &preco[i]);

                break;
            }
        }

        do
        {
            printf("\n O que deseja fazer agora?\n 1 - Cadastrar outro prato \n 2 - Voltar ao menu \n");
            scanf("%d", &resp);

            if (resp == 1)
            {
                repeat = true;
                    ; // Consome o caractere de nova linha para não influenciar no próximo fgets
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
    // printf("%zu\n", strlen(pratos[i])); // É utilizado para contar quantos caracteres tem naquela posição da array
}
