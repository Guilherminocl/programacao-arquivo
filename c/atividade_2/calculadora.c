#include <stdio.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

int main()
{
    int opc, v1, v2, caso;

    printf(BLUE "===========================\n" RESET);
    printf(GREEN "     CALCULADORA SIMPLES   \n" RESET);
    printf(BLUE "===========================\n\n" RESET);

    printf(YELLOW "|1 = + | 2 = - | 3 = * | 4 = %% |\n\n" RESET);
    printf("Escolha uma opção: ");
    scanf("%d", &opc);

    if (opc == 1)
    {
        printf(GREEN "\n--- SOMA ---\n\n" RESET);
        printf("Digite o primeiro valor: ");
        scanf("%d", &v1);
        printf("Digite o segundo valor: ");
        scanf("%d", &v2);
        caso = v1 + v2;
        printf(BLUE "%d + %d = %d\n" RESET, v1, v2, caso);
    }
    else if (opc == 2)
    {
        printf(GREEN "\n--- SUBTRAÇÂO ---\n\n" RESET);
        printf("Digite o primeiro valor: ");
        scanf("%d", &v1);
        printf("Digite o segundo valor: ");
        scanf("%d", &v2);
        caso = v1 - v2;
        printf(BLUE "%d - %d = %d\n" RESET, v1, v2, caso);
    }

    else if (opc == 3)
    {
        printf(GREEN "\n--- MULTIPLICAÇÃO ---\n\n" RESET);
        printf("Digite o primeiro valor: ");
        scanf("%d", &v1);
        printf("Digite o segundo valor: ");
        scanf("%d", &v2);
        caso = v1 * v2;
        printf(BLUE "%d * %d = %d\n" RESET, v1, v2, caso);
    }
    else if (opc == 4)
    {
        printf(GREEN "\n--- DIVISÂO ---\n\n" RESET);
        printf("Digite o primeiro valor: ");
        scanf("%d", &v1);
        printf("Digite o segundo valor: ");
        scanf("%d", &v2);
        caso = v1 / v2;
        printf(BLUE "%d / %d = %d\n" RESET, v1, v2, caso);
    }
    else
    {
        printf(RED "Opção invalida" RESET);
    }

    return 0;
}
