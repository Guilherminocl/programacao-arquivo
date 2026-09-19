#include <stdio.h>

float media(float n1, float n2, float n3) {
	return (n1 + n2 + n3) / 3.0;
}

int main() {
	float nota1, nota2, nota3;
	printf("Digite a primeira nota: ");
	scanf("%f", &nota1);
	printf("Digite a segunda nota: ");
	scanf("%f", &nota2);
	printf("Digite a terceira nota: ");
	scanf("%f", &nota3);

	float m = media(nota1, nota2, nota3);
	printf("Média: %.2f\n", m);
	if (m >= 6.0) {
		printf("Aluno aprovado!\n");
	} else {
		printf("Aluno reprovado.\n");
	}
	return 0;
}
