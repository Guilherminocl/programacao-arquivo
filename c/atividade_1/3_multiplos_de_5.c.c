#include <stdio.h>
#include <locale.h>

int main() {
    printf("3. Múltiplos de 5 até 100:\n");
    for (int i = 5; i <= 100; i += 5) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
