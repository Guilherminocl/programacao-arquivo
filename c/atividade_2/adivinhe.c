#include <stdio.h>
#include <stdlib.h>  // Para rand() e srand()
#include <time.h>    // Para time()

int main() {
    int i, valor, num;

    srand(time(NULL));     // Inicializa o gerador de números aleatórios
    num = rand() % 100 + 1; // Número aleatório entre 1 e 100

    for (i = 0; i < 5; i++) {
        printf("Digite um valor: \n");
        scanf("%d", &valor);

        if (valor == num) {
            printf("Acertou! O número é: %d\n", num);
            break; // Sai do loop ao acertar
        } 
        else if (valor > num) {
            printf("Número maior\n");
        } 
        else {
            printf("Número menor\n");
        }
    }

    return 0;
}
