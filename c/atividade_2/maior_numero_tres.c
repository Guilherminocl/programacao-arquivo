#include <stdio.h>
#include <locale.h>

int main() {

    int n1, n2, n3;

    printf("Digite o primeiro número: \n");
    scanf("%d", &n1);
    printf("Digite o segundo número: \n");
    scanf("%d", &n2);
    printf("Digite o terceiro número: \n");
    scanf("%d", &n3);

    if ((n1 > n2) && (n2 > n3)) {
        printf("%d é maior que %d\n e %d é maior que %d\n", n1, n2, n2, n3);
    }
    else if ((n1 > n3) && (n3 > n2)) {
        printf("%d é maior que %d\n e %d é maior que %d\n", n1, n3, n3, n2);
    }
    else if ((n2 > n1) && (n1 > n3)) {
        printf("%d é maior que %d\n e %d é maior que %d\n", n2, n1, n1, n3);
    }
    else if ((n2 > n3) && (n3 > n1)) {
        printf("%d é maior que %d\n e %d é maior que %d\n", n2, n3, n3, n1);
    }
    else if ((n3 > n1) && (n1 > n2)) {
        printf("%d é maior que %d\n e %d é maior que %d\n", n3, n1, n1, n2);
    }
    else if ((n3 > n2) && (n2 > n1)) {
        printf("%d é maior que %d\n e %d é maior que %d\n", n3, n2, n2, n1);
    }
    else {
        printf("Alguns números são iguais\n");
    }

    return 0;
}
