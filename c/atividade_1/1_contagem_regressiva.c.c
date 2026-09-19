#include <stdio.h>
#include <locale.h>

int main() {
    int n;
    printf("1. Contagem regressiva\nDigite um número: ");
    scanf("%d", &n);

    if (n >= 0) {
        printf("Contagem regressiva:\n");
        while (n >= 0) {
            printf("%d\n", n);
            n--;
        }
    } else {
        printf("Número inválido!\n");
    }

    return 0;
}
