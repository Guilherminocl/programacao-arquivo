#include <stdio.h>
#include <locale.h>

int main() {

    int n;

    printf("Digite um número: \n");
    scanf("%d", &n);

    if (n > 0) {
        printf("Número positivo\n");
    }
    else if (n < 0) {
        printf("Número negativo\n");
    }
    else {
        printf("Número é zero\n");
    }

    return 0;
}
