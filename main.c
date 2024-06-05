#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "BuscaPratos.c"
#include "ListaPratos.c"
#include "cadastroPratos.c"
#include "removerPratos.c"

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
        printf("Seja bem vindo ao nosso sistema! O que deseja fazer?\n");
        printf("1 - Cadastro de Pratos\n");
        printf("2 - Remocao de Pratos\n");
        printf("3 - Busca de Pratos\n");
        printf("4 - Listagem de Pratos\n");
        printf("5 - Registrar um pedido\n");
        printf("0 - SAIR\n");

        scanf ("%d", &decisao);

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
                printf("Opção escolhida inválida! Por favor tente novamente");
                loop = true;
            break;
        }
    } while (loop);

    return 0;
}
