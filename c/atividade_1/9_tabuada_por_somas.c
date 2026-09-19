#include <stdio.h>
#include <locale.h>

int main() {
    int n;

    printf("9. Tabuada por somas\nDigite um número: ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++) {
        int resultado = 0;
        for (int j = 0; j < i; j++) {
            resultado += n;
        }
        printf("%d x %d = %d\n", n, i, resultado);
    }
    return 0;
}
