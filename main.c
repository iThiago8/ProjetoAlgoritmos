#include <stdio.h> //Biblioteca de entrada e saída simples
#include <stdlib.h> //Biblioteca de funções padrões da linguagem C (strlen, strstr, strcopy e etc...)
#include <stdbool.h> //Biblioteca que permite utilizar o tipo booleano das variáveis
//Todos os "#include" abaixo com os arquivos .c permitem nós fazermos a utilização da função de cada arquivo 
#include "BuscaPratos.c"
#include "ListaPratos.c"
#include "cadastroPratos.c" 
#include "removerPratos.c"
#include "registraPedido.c"

int main ()
{
    setlocale(LC_ALL, "Portuguese");

    void CadastroPratos(void);
    void RemoverPratos(void);
    void BuscaPratos(void);
    void ListaPratos(void);
    void RegistraPedido(void);


    bool loop = true;
    do {
        int decisao = 0;
        //Interface inicial do programa
        printf("=================================================================");
        printf("\n=============== Gabriel e Thiago - Restaurante ==================");
        printf("\n=================================================================");
        printf("\nSeja bem vindo ao nosso sistema! O que deseja fazer?");
        printf("\n=================================================================\n");
        printf("1 - Cadastro de Pratos\n");
        printf("2 - Remocao de Pratos\n");
        printf("3 - Busca de Pratos\n");
        printf("4 - Listagem de Pratos\n");
        printf("5 - Registrar um pedido\n");
        printf("0 - SAIR\n");

        scanf ("%d", &decisao);
        


        //É feito um switch case para chamar a função de cada arquivo de acordo com o número digitado pelo usuário anteriormente
        switch (decisao)
        {
            case 1:
                CadastroPratos();
            break;
        
            case 2:
                RemoverPratos();
            break;

            case 3:
                BuscaPratos();
            break;

            case 4:
                ListaPratos();
            break;

            case 5:
                RegistraPedido();
            break;

            case 0:
                loop = false;
            break;
        
            
            default:
                printf("Opcao escolhida invalida! Por favor tente novamente\n");
                loop = true;
            break;
        }
    } while (loop);

    return 0;
}
