#include <stdio.h>

void soma() {
    int v1, v2, result;

    printf("Digite o primeiro numero: ");
    scanf("%d", &v1);

    printf("Digite o segundo numero: ");
    scanf("%d", &v2);

    result = v1 + v2;

    printf("Resultado: %d\n", result);
}

int main() {
    int opcao;

    printf("1 - Soma\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            soma();
            break;
        default:
            printf("Opcao invalida\n");
    }

    return 0;
}
