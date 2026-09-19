#include <stdio.h>
#include <locale.h>

int main() {

    int idade;

    printf("Digite a idade: \n");
    scanf("%d", &idade);

    if (idade <= 11) {
        printf("Criança\n");
    }
    else if (idade >= 12 && idade <= 17) {
        printf("Adolescente\n");
    }
    else if (idade >= 18 && idade <= 59) {
        printf("Adulto\n");
    }
    else {
        printf("Idoso\n");
    }

    return 0;
}
