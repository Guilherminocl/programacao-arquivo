#include <stdio.h>
#include <locale.h>

int main() {
    int n, maior, menor;

    printf("Digite 6 números:\n");

    printf("Número 1: ");
    scanf("%d", &n);
    maior = menor = n;

    for (int i = 2; i <= 6; i++) {
        printf("Número %d: ", i);
        scanf("%d", &n);
        if (n > maior) maior = n;
        if (n < menor) menor = n;
    }

    printf("Maior = %d\nMenor = %d\n", maior, menor);

    return 0;
}
