#include <stdio.h>
#include <locale.h>

int main() {

    int n1,n2;

    printf("Digite um número: \n");
    scanf("%d", &n1);
    printf("Digite um segundo número: \n");
    scanf("%d", &n2);

    if (n1 > n2){
        printf("%d é maior que %d\n", n1, n2);
    }
    else if (n2 > n1){
        printf("%d é maior que %d\n", n2, n1);
    }
    else{
        printf("Os números são iguais\n");
    }
    return 0;
}
