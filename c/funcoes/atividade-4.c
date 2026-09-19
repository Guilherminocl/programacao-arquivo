#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dobro(int n)
{
    printf("Dobro do numero %d é %d\n", n, n * 2);
}

int main()
{

    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    dobro(numero);
    return 0;
}