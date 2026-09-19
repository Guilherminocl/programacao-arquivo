#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maior(int a, int b)
{
    if (a > b)
    {
        printf("%d é maior que %d", a, b);
    }
    else if (b > a)
    {
        printf("%d é maior que %d", b, a);
    }
    else
    {
        printf("Valor inválido");
    }
}

int main()
{
    int n1, n2;
    printf("Digite o primeiro número: ");
    scanf("%d", &n1);
    printf("Digite o segundo número: ");
    scanf("%d", &n2);
    maior(n1, n2);
    return 0;
}