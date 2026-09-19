#include <stdio.h>
#include <locale.h>

int main() {
    
    int senha;

    printf("Digite a senha: \n");
    scanf("%d", &senha);

    if (senha == 1234) {
        printf("Senha correta\n");
    }
    else {
        printf("Senha incorreta\n");
    }

    return 0;
}
