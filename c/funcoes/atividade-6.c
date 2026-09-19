#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void soma(int a, int b)
{
    printf("A soma é: %d\n", a + b);
}

int main()
{
    int n1, n2;
    printf("Digite o primeiro número: ");
    scanf("%d", &n1);
    printf("Digite o segundo número: ");
    scanf("%d", &n2);

    soma(n1, n2);

    return 0;
}