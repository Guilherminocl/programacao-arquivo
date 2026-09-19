#include <stdio.h>

int quadrado(int n) {
	return n * n;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		printf("O quadrado de %d é %d\n", i, quadrado(i));
	}
	return 0;
}
