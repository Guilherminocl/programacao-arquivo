#include <stdio.h>
#include <locale.h>

int main() {

    float media;

    printf("Digite a média final do aluno: \n");
    scanf("%f", &media);

    if (media >= 6) {
        printf("Aprovado\n");
    }
    else if (media >= 4 && media < 6) {
        printf("Recuperação\n");
    }
    else {
        printf("Reprovado\n");
    }

    return 0;
}
