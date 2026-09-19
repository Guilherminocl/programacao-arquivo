#include <stdio.h>
#include <locale.h>

int main() {
    int n, soma = 0;
    printf("5. Somatório de pares até N\nDigite N: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i += 2) {
        soma += i;
    }

    printf("Soma dos pares de 1 até %d: %d\n", n, soma);
    return 0;
}
