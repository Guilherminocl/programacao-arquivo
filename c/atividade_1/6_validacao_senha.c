#include <stdio.h>
#include <locale.h>

int main() {
    int senhaCorreta = 1234, tentativa;

    printf("6. Validação de senha\n");

    do {
        printf("Digite a senha: ");
        scanf("%d", &tentativa);
        if (tentativa != senhaCorreta) {
            printf("Senha incorreta! Tente novamente.\n");
        }
    } while (tentativa != senhaCorreta);

    printf("Senha correta!\n");
    return 0;
}
