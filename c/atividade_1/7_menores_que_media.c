#include <stdio.h>
#include <locale.h>

int main() {
    int n, soma = 0;
    float media;

    printf("Digite 5 números:\n");

    for (int i = 1; i <= 5; i++) {
        printf("Número %d: ", i);
        scanf("%d", &n);
        soma += n;
    }

    media = soma / 5.0;
    printf("Média = %.2f\nNúmeros menores que a média:\n", media);

    for (int i = 1; i <= 5; i++) {
        printf("Número %d: ", i);
        scanf("%d", &n);
        if (n < media) {
            printf("%d ", n);
        }
    }
    printf("\n");

    return 0;
}
