#include <stdio.h>

int fatorial(int n) {
	int fat = 1;
	for (int i = 2; i <= n; i++) {
		fat *= i;
	}
	return fat;
}

int main() {
	int num = 5;
	printf("Fatorial de %d = %d\n", num, fatorial(num));
	return 0;
}
a