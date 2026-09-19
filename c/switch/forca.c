#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opc, anum, num;

    printf("escolha\n");
    printf("1 - 0-10\n2 -0-50\n3 - 0 - 100\n");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        anum = rand() % 11;
        for (int i = 0; i < 10; i++)
        {
            printf("Digite seu Número: ");
            scanf("%d", &num);

            if (anum == num)
            {
                printf("isso\n");
                break;
            }
            else if (num < 0 || num > 10)
            {
                printf("valor invalido\n");
            }
            else if (anum > num)
            {
                printf("numero maior\n");
            }
            else if (anum < num)
            {
                printf("numero menor\n");
            }
        }
        break;

    case 2:
        anum = rand() % 51;
        for (int i = 0; i < 10; i++)
        {
            printf("Digite seu Número: ");
            scanf("%d", &num);

            if (anum == num)
            {
                printf("isso\n");
                break;
            }
            else if (num < 0 || num > 50)
            {
                printf("valor invalido\n");
            }
            else if (anum > num)
            {
                printf("numero maior\n");
            }
            else if (anum < num)
            {
                printf("numero menor\n");
            }
        }
        break;

    case 3:
        anum = rand() % 101;
        for (int i = 0; i < 10; i++)
        {
            printf("Digite seu Número: ");
            scanf("%d", &num);

            if (anum == num)
            {
                printf("isso\n");
                break;
            }
            else if (num < 0 || num > 100)
            {
                printf("valor invalido\n");
            }
            else if (anum > num)
            {
                printf("numero maior\n");
            }
            else if (anum < num)
            {
                printf("numero menor\n");
            }
        }
        break;

    default:
        break;
    }
    return 0;
}
