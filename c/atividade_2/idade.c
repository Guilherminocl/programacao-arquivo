#include <stdio.h>
#include <locale.h>

int main() {

    int N;

    printf("Digite a sua idade: \n");
    scanf("%d", &N);

    if(N >= 18){
        printf("Maior de idade!");
    }
    else if(N < 18){
        printf("Menor de idade!");
    }
    else
        printf("Valor invalalido");


    return 0;

}