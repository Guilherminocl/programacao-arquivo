    #include <stdio.h>

int main() {
    int n, fatorial = 1;

    printf("10. Fatorial sem multiplicação direta\nDigite N: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        int temp = 0;
        for (int j = 0; j < fatorial; j++) {
            temp += i;
        }
        fatorial = temp;
    }

    printf("Fatorial de %d = %d\n", n, fatorial);
    return 0;
}
