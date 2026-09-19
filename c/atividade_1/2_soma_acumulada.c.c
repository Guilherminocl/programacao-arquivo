#include <stdio.h>
#include <locale.h>

int main() {
    int n, soma = 0;
    printf("2. Soma acumulada até N\nDigite N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        soma += i;
    }

    printf("Soma de 1 até %d: %d\n", n, soma);
    return 0;
}