#include <stdio.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

void soma(int a, int b)
{
    printf(GREEN "\n--- SOMA ---\n\n" RESET);
    printf(BLUE "%d + %d = %d\n" RESET, a, b, a + b);
}

void sub(int a, int b)
{
    printf(GREEN "\n--- SUBTRAÇÃO ---\n\n" RESET);
    printf(BLUE "%d - %d = %d\n" RESET, a, b, a - b);
}

void mul(int a, int b)
{
    printf(GREEN "\n--- MULTIPLICAÇÃO ---\n\n" RESET);
    printf(BLUE "%d * %d = %d\n" RESET, a, b, a * b);
}

void divisao(int a, int b)
{
    printf(GREEN "\n--- DIVISÃO ---\n\n" RESET);
    if (b == 0)
        printf(RED "Erro: divisão por zero!\n" RESET);
    else
        printf(BLUE "%d / %d = %d\n" RESET, a, b, a / b);
}

void resto(int a, int b)
{
    printf(GREEN "\n--- RESTO DA DIVISÃO ---\n\n" RESET);
    if (b == 0)
        printf(RED "Erro: divisão por zero!\n" RESET);
    else
        printf(BLUE "%d %% %d = %d\n" RESET, a, b, a % b);
}

int main()
{
    int opc, v1, v2;

    do
    {
        printf(BLUE "\n===========================\n" RESET);
        printf(GREEN "     CALCULADORA SIMPLES   \n" RESET);
        printf(BLUE "===========================\n\n" RESET);

        printf(YELLOW "|1 = + | 2 = - | 3 = * | 4 = / | 5 = %% | 0 = SAIR|\n\n" RESET);
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        if (opc >= 1 && opc <= 5)
        {
            printf("\nDigite o primeiro valor: ");
            scanf("%d", &v1);
            printf("Digite o segundo valor: ");
            scanf("%d", &v2);
        }

        switch (opc)
        {
        case 1:
            soma(v1, v2);
            break;
        case 2:
            sub(v1, v2);
            break;
        case 3:
            mul(v1, v2);
            break;
        case 4:
            divisao(v1, v2);
            break;
        case 5:
            resto(v1, v2);
            break;
        case 0:
            printf(RED "\nSaindo...\n" RESET);
            break;
        default:
            printf(RED "\nOpção inválida!\n" RESET);
            break;
        }

    } while (opc != 0);

    return 0;
}
