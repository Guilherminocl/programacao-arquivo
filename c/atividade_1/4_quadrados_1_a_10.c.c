#include <stdio.h>
#include <locale.h>


int main() {
    printf("4. Quadrado de números de 1 a 10:\n");

    for (int i = 1; i <= 10; i++) {
        printf("%d → %d\n", i, i * i);
    }

    return 0;
}
