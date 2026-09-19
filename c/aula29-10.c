#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opc, n1, n2, res;

    printf("Escolha a opção:\n");
    printf("1 - +\n2 - -\n3 - *\n4 - /\n");
    scanf("%d", &opc);

    printf("Digite o primeiro número: ");
    scanf("%d", &n1);
    printf("Digite o segundo número: ");
    scanf("%d", &n2);

    switch (opc)
    {
        case 1:
            res = n1 + n2;
            printf("Resultado: %d\n", res);
            break;
        case 2:
            res = n1 - n2;
            printf("Resultado: %d\n", res);
            break;
        case 3:
            res = n1 * n2;
            printf("Resultado: %d\n", res);
            break;
        case 4:
            if (n2 != 0)
                printf("Resultado: %d\n", n1 / n2);
            else
                printf("Erro: divisão por zero!\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
