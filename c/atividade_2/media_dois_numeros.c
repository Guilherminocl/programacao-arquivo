#include <stdio.h>
#include <locale.h>

int main() {

    int n1, n2, media;

    printf("Digite o primeiro número: \n");
    scanf("%d", &n1);
    printf("Digite o segundo número: \n");
    scanf("%d", &n2);

    media = (n1 + n2) / 2;

    if (media > 10) {
        printf("Média é maior que 10\n");
    }
    else if (media < 10) {
        printf("Média é menor que 10\n");
    }
    else {
        printf("Média é igual a 10\n");
    }

    return 0;
}
