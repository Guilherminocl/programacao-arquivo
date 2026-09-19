#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirNumero(int n)
{
    printf("O número informado foi: %d\n", n);
}

int main()
{
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero );
    imprimirNumero(numero);
    return 0;
}