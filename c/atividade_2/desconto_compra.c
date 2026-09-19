#include <stdio.h>
#include <locale.h>

int main() {

    float valor;

    printf("Digite o valor da compra: \n");
    scanf("%f", &valor);

    if (valor >= 100) {
        printf("Valor final com desconto: R$%.2f\n", valor * 0.9);
    }
    else {
        printf("Valor final: R$%.2f\n", valor);
    }

    return 0;
}
