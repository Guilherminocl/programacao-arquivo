#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int a, b;
    char opc;

    printf("Escolha uma opção:\n");
    printf("a - Somar\n");
    printf("b - Subtrair\n");
    printf("c - Multiplicar\n");
    printf("d - Dividir\n");
    printf("Opção: ");
    scanf(" %c", &opc);

    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);

    switch (opc) {
        case 'a':
            printf("Soma: %d\n", a + b);
            break;
        case 'b':
            printf("Subtração: %d\n", a - b);
            break;
        case 'c':
            printf("Multiplicação: %d\n", a * b);
            break;
        case 'd':
            if (b != 0)
                printf("Divisão: %.2f\n", (float)a / b);
            else
                printf("Erro: divisão por zero!\n");
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
