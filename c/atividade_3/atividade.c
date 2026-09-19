#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define MAGENTA "\033[1;35m"

//  FUNÇÕES DO EXERCÍCIO 1
void soma(int a, int b)
{
    printf(GREEN "\n--- SOMA ---\n\n" RESET);
    printf(BLUE "%d + %d = %d\n" RESET, a, b, a + b);
}

void sub(int a, int b)
{
    printf(GREEN "\n--- SUBTRAÇÃO ---\n\n" RESET);
    printf(BLUE "%d - %d = %d\n" RESET, a, b, a - b);
}

void mul(int a, int b)
{
    printf(GREEN "\n--- MULTIPLICAÇÃO ---\n\n" RESET);
    printf(BLUE "%d * %d = %d\n" RESET, a, b, a * b);
}

void divisao(int a, int b)
{
    printf(GREEN "\n--- DIVISÃO ---\n\n" RESET);
    if (b == 0)
        printf(RED "Erro: divisão por zero!\n" RESET);
    else
        printf(BLUE "%d / %d = %d\n" RESET, a, b, a / b);
}

void resto_div(int a, int b)
{
    printf(GREEN "\n--- RESTO DA DIVISÃO ---\n\n" RESET);
    if (b == 0)
        printf(RED "Erro: divisão por zero!\n" RESET);
    else
        printf(BLUE "%d %% %d = %d\n" RESET, a, b, a % b);
}

void exercicio1()
{
    int opc, v1, v2;

    printf(BLUE "\n=== EXERCÍCIO 1 - CALCULADORA MODULAR ===\n" RESET);

    do
    {
        printf(BLUE "\n=======\n" RESET);
        printf(GREEN "     CALCULADORA SIMPLES   \n" RESET);
        printf(BLUE "=======\n\n" RESET);

        printf(YELLOW "|1 = + | 2 = - | 3 = * | 4 = / | 5 = %% | 0 = SAIR|\n\n" RESET);
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        if (opc >= 1 && opc <= 5)
        {
            printf("\nDigite o primeiro valor: ");
            scanf("%d", &v1);
            printf("Digite o segundo valor: ");
            scanf("%d", &v2);
        }

        switch (opc)
        {
        case 1:
            soma(v1, v2);
            break;
        case 2:
            sub(v1, v2);
            break;
        case 3:
            mul(v1, v2);
            break;
        case 4:
            divisao(v1, v2);
            break;
        case 5:
            resto_div(v1, v2);
            break;
        case 0:
            printf(RED "\nSaindo da calculadora...\n" RESET);
            break;
        default:
            printf(RED "\nOpção inválida!\n" RESET);
            break;
        }
    } while (opc != 0);
}

//  FUNÇÕES DO EXERCÍCIO 2
void exercicio2()
{
    int num, tipo;

    printf(BLUE "\n=== EXERCÍCIO 2 - CLASSIFICADOR DE NÚMEROS ===\n" RESET);
    printf(BLUE "=======\n" RESET);
    printf(GREEN "   IDENTIFICADOR DE NÚMEROS\n" RESET);
    printf(BLUE "=======\n\n" RESET);

    printf(YELLOW "Digite um número inteiro: " RESET);
    scanf("%d", &num);

    if (num == 0)
        tipo = 0;
    else if (num > 0)
        tipo = (num % 2 == 0) ? 1 : 2;
    else
        tipo = (num % 2 == 0) ? 3 : 4;

    printf("\n");
    switch (tipo)
    {
    case 0:
        printf(CYAN "O número é zero.\n" RESET);
        break;
    case 1:
        printf(GREEN "O número é par positivo.\n" RESET);
        break;
    case 2:
        printf(YELLOW "O número é ímpar positivo.\n" RESET);
        break;
    case 3:
        printf(BLUE "O número é par negativo.\n" RESET);
        break;
    case 4:
        printf(RED "O número é ímpar negativo.\n" RESET);
        break;
    }
    printf("\n" BLUE "=======\n" RESET);
}

//  FUNÇÕES DO EXERCÍCIO 3
void exercicio3()
{
    float v[5];
    int i, opc;
    float resultado;

    printf(BLUE "\n=== EXERCÍCIO 3 - TABELA DE OPERAÇÕES COM VETOR ===\n" RESET);
    printf(BLUE "=======\n" RESET);
    printf(GREEN "     OPERANDO COM VETOR    \n" RESET);
    printf(BLUE "=======\n\n" RESET);

    printf(YELLOW "Digite 5 números:\n" RESET);
    for (i = 0; i < 5; i++)
    {
        printf("v[%d]: ", i);
        scanf("%f", &v[i]);
    }

    printf("\n");
    printf(GREEN "1-Somar todos\n" RESET);
    printf(GREEN "2-Subtrair todos\n" RESET);
    printf(GREEN "3-Multiplicar todos\n" RESET);
    printf(GREEN "4-Dividir o primeiro pelo último\n" RESET);
    printf(YELLOW "\nEscolha uma opção: " RESET);
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        resultado = 0;
        for (i = 0; i < 5; i++)
            resultado += v[i];
        printf(BLUE "\nA soma de todos é: %.2f\n" RESET, resultado);
        break;
    case 2:
        resultado = v[0];
        for (i = 1; i < 5; i++)
            resultado -= v[i];
        printf(BLUE "\nA subtração de todos é: %.2f\n" RESET, resultado);
        break;
    case 3:
        resultado = 1;
        for (i = 0; i < 5; i++)
            resultado *= v[i];
        printf(BLUE "\nA multiplicação de todos é: %.2f\n" RESET, resultado);
        break;
    case 4:
        if (v[4] == 0)
            printf(RED "\nErro: divisão por zero!\n" RESET);
        else
        {
            resultado = v[0] / v[4];
            printf(BLUE "\n%.2f / %.2f = %.2f\n" RESET, v[0], v[4], resultado);
        }
        break;
    default:
        printf(RED "\nOpção inválida!\n" RESET);
        break;
    }
    printf("\n" BLUE "=======\n" RESET);
}

//  FUNÇÕES DO EXERCÍCIO 4
float calcular_media(float vetor[], int tamanho)
{
    float soma = 0;
    for (int i = 0; i < tamanho; i++)
        soma += vetor[i];
    return soma / tamanho;
}

float encontrar_maior(float vetor[], int tamanho)
{
    float maior = vetor[0];
    for (int i = 1; i < tamanho; i++)
        if (vetor[i] > maior)
            maior = vetor[i];
    return maior;
}

float encontrar_menor(float vetor[], int tamanho)
{
    float menor = vetor[0];
    for (int i = 1; i < tamanho; i++)
        if (vetor[i] < menor)
            menor = vetor[i];
    return menor;
}

int contar_div5(float vetor[], int tamanho)
{
    int count = 0;
    for (int i = 0; i < tamanho; i++)
        if ((int)vetor[i] % 5 == 0)
            count++;
    return count;
}

void exercicio4()
{
    float numeros[10];
    int opc, i;

    printf(BLUE "\n=== EXERCÍCIO 4 - ESTATÍSTICAS DE VETOR ===\n" RESET);

    printf(YELLOW "Digite 10 números:\n" RESET);
    for (i = 0; i < 10; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%f", &numeros[i]);
    }

    do
    {
        printf(CYAN "\n=== MENU ESTATÍSTICAS ===\n" RESET);
        printf("1 - Calcular média\n");
        printf("2 - Maior número\n");
        printf("3 - Menor número\n");
        printf("4 - Quantos são divisíveis por 5\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf(GREEN "\nMédia: %.2f\n" RESET, calcular_media(numeros, 10));
            break;
        case 2:
            printf(GREEN "\nMaior número: %.2f\n" RESET, encontrar_maior(numeros, 10));
            break;
        case 3:
            printf(GREEN "\nMenor número: %.2f\n" RESET, encontrar_menor(numeros, 10));
            break;
        case 4:
            printf(GREEN "\nDivisíveis por 5: %d\n" RESET, contar_div5(numeros, 10));
            break;
        case 0:
            break;
        default:
            printf(RED "\nOpção inválida!\n" RESET);
        }
    } while (opc != 0);
}

//  FUNÇÕES DO EXERCÍCIO 5
float metros_para_cm(float metros) { return metros * 100; }
float cm_para_metros(float cm) { return cm / 100; }
float celsius_para_fahrenheit(float celsius) { return (celsius * 9 / 5) + 32; }
float fahrenheit_para_celsius(float fahrenheit) { return (fahrenheit - 32) * 5 / 9; }
float reais_para_dolares(float reais, float cotacao) { return reais / cotacao; }
float dolares_para_reais(float dolares, float cotacao) { return dolares * cotacao; }
float kmh_para_ms(float kmh) { return kmh / 3.6; }
float ms_para_kmh(float ms) { return ms * 3.6; }

void exercicio5()
{
    int opc, sub_opc;
    float valor, resultado, cotacao;

    printf(BLUE "\n=== EXERCÍCIO 5 - CONVERSOR MATEMÁTICO ===\n" RESET);

    do
    {
        printf(CYAN "\n=== CONVERSOR ===\n" RESET);
        printf("1 - Metros  Centímetros\n");
        printf("2 - Celsius  Fahrenheit\n");
        printf("3 - Reais  Dólares\n");
        printf("4 - Km/h  m/s\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        if (opc >= 1 && opc <= 4)
        {
            printf("Digite o valor a converter: ");
            scanf("%f", &valor);
        }

        switch (opc)
        {
        case 1:
            printf("1 - Metros para CM\n2 - CM para Metros\nEscolha: ");
            scanf("%d", &sub_opc);
            if (sub_opc == 1)
            {
                resultado = metros_para_cm(valor);
                printf(GREEN "%.2f metros = %.2f cm\n" RESET, valor, resultado);
            }
            else
            {
                resultado = cm_para_metros(valor);
                printf(GREEN "%.2f cm = %.2f metros\n" RESET, valor, resultado);
            }
            break;

        case 2:
            printf("1 - Celsius para Fahrenheit\n2 - Fahrenheit para Celsius\nEscolha: ");
            scanf("%d", &sub_opc);
            if (sub_opc == 1)
            {
                resultado = celsius_para_fahrenheit(valor);
                printf(GREEN "%.2f°C = %.2f°F\n" RESET, valor, resultado);
            }
            else
            {
                resultado = fahrenheit_para_celsius(valor);
                printf(GREEN "%.2f°F = %.2f°C\n" RESET, valor, resultado);
            }
            break;

        case 3:
            printf("Digite a cotação do dólar: ");
            scanf("%f", &cotacao);
            printf("1 - Reais para Dólares\n2 - Dólares para Reais\nEscolha: ");
            scanf("%d", &sub_opc);
            if (sub_opc == 1)
            {
                resultado = reais_para_dolares(valor, cotacao);
                printf(GREEN "R$ %.2f = US$ %.2f\n" RESET, valor, resultado);
            }
            else
            {
                resultado = dolares_para_reais(valor, cotacao);
                printf(GREEN "US$ %.2f = R$ %.2f\n" RESET, valor, resultado);
            }
            break;

        case 4:
            printf("1 - Km/h para m/s\n2 - m/s para Km/h\nEscolha: ");
            scanf("%d", &sub_opc);
            if (sub_opc == 1)
            {
                resultado = kmh_para_ms(valor);
                printf(GREEN "%.2f km/h = %.2f m/s\n" RESET, valor, resultado);
            }
            else
            {
                resultado = ms_para_kmh(valor);
                printf(GREEN "%.2f m/s = %.2f km/h\n" RESET, valor, resultado);
            }
            break;

        case 0:
            break;
        default:
            printf(RED "Opção inválida!\n" RESET);
        }
    } while (opc != 0);
}

//  FUNÇÕES DO EXERCÍCIO 6
void bubble_sort(int vetor[], int tamanho)
{
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void exercicio6()
{
    int numeros[10], pares[10], impares[10];
    int i, count_pares = 0, count_impares = 0;

    printf(BLUE "\n=== EXERCÍCIO 6 - VETOR DE PARES E ÍMPARES SEPARADOS ===\n" RESET);

    printf(YELLOW "Digite 10 números inteiros:\n" RESET);
    for (i = 0; i < 10; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);

        if (numeros[i] % 2 == 0)
        {
            pares[count_pares] = numeros[i];
            count_pares++;
        }
        else
        {
            impares[count_impares] = numeros[i];
            count_impares++;
        }
    }

    if (count_pares > 0)
    {
        bubble_sort(pares, count_pares);
        printf(GREEN "\nNúmeros pares (ordenados): " RESET);
        for (i = 0; i < count_pares; i++)
            printf("%d ", pares[i]);
        printf("\n");
    }
    else
    {
        printf(YELLOW "\nNenhum número par encontrado.\n" RESET);
    }

    if (count_impares > 0)
    {
        bubble_sort(impares, count_impares);
        printf(GREEN "Números ímpares (ordenados): " RESET);
        for (i = 0; i < count_impares; i++)
            printf("%d ", impares[i]);
        printf("\n");
    }
    else
    {
        printf(YELLOW "Nenhum número ímpar encontrado.\n" RESET);
    }
}

//  FUNÇÕES DO EXERCÍCIO 7
void exercicio7()
{
    int saque, opc, notas100, notas50, notas20, notas10, resto;

    printf(BLUE "\n=== EXERCÍCIO 7 - SIMULADOR DE CAIXA ELETRÔNICO ===\n" RESET);

    printf("Digite o valor do saque: ");
    scanf("%d", &saque);

    printf(CYAN "\nEscolha o tipo de cédula inicial:\n" RESET);
    printf("1 - Notas de R$ 100\n");
    printf("2 - Notas de R$ 50\n");
    printf("3 - Notas de R$ 20\n");
    printf("4 - Notas de R$ 10\n");
    printf("Escolha: ");
    scanf("%d", &opc);

    notas100 = notas50 = notas20 = notas10 = 0;
    resto = saque;

    switch (opc)
    {
    case 1:
        notas100 = resto / 100;
        resto %= 100;
        notas50 = resto / 50;
        resto %= 50;
        notas20 = resto / 20;
        resto %= 20;
        notas10 = resto / 10;
        break;
    case 2:
        notas50 = resto / 50;
        resto %= 50;
        notas20 = resto / 20;
        resto %= 20;
        notas10 = resto / 10;
        resto %= 10;
        notas100 = resto / 100;
        break;
    case 3:
        notas20 = resto / 20;
        resto %= 20;
        notas10 = resto / 10;
        resto %= 10;
        notas50 = resto / 50;
        resto %= 50;
        notas100 = resto / 100;
        break;
    case 4:
        notas10 = resto / 10;
        resto %= 10;
        notas20 = resto / 20;
        resto %= 20;
        notas50 = resto / 50;
        resto %= 50;
        notas100 = resto / 100;
        break;
    default:
        printf(RED "Opção inválida!\n" RESET);
        return;
    }

    printf(GREEN "\nNotas necessárias para R$ %d:\n" RESET, saque);
    if (notas100 > 0)
        printf("R$ 100: %d notas\n", notas100);
    if (notas50 > 0)
        printf("R$ 50: %d notas\n", notas50);
    if (notas20 > 0)
        printf("R$ 20: %d notas\n", notas20);
    if (notas10 > 0)
        printf("R$ 10: %d notas\n", notas10);
}

//  FUNÇÕES DO EXERCÍCIO 8
void mostrar_pares(int vetor[], int tamanho)
{
    printf(GREEN "Números pares: " RESET);
    for (int i = 0; i < tamanho; i++)
        if (vetor[i] % 2 == 0)
            printf("%d ", vetor[i]);
    printf("\n");
}

void mostrar_impares(int vetor[], int tamanho)
{
    printf(GREEN "Números ímpares: " RESET);
    for (int i = 0; i < tamanho; i++)
        if (vetor[i] % 2 != 0)
            printf("%d ", vetor[i]);
    printf("\n");
}

void mostrar_soma_media(int vetor[], int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
        soma += vetor[i];
    printf(GREEN "Soma: %d\n" RESET, soma);
    printf(GREEN "Média: %.2f\n" RESET, (float)soma / tamanho);
}

void mostrar_acima_media(int vetor[], int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
        soma += vetor[i];
    float media = (float)soma / tamanho;

    printf(GREEN "Valores acima da média (%.2f): " RESET, media);
    for (int i = 0; i < tamanho; i++)
        if (vetor[i] > media)
            printf("%d ", vetor[i]);
    printf("\n");
}

void exercicio8()
{
    int numeros[8], opc, i;

    printf(BLUE "\n=== EXERCÍCIO 8 - MENU DE ANÁLISE DE NÚMEROS ===\n" RESET);

    printf(YELLOW "Digite 8 números inteiros:\n" RESET);
    for (i = 0; i < 8; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    do
    {
        printf(CYAN "\n=== MENU ANÁLISE ===\n" RESET);
        printf("1 - Mostrar números pares\n");
        printf("2 - Mostrar números ímpares\n");
        printf("3 - Exibir soma e média\n");
        printf("4 - Exibir valores acima da média\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            mostrar_pares(numeros, 8);
            break;
        case 2:
            mostrar_impares(numeros, 8);
            break;
        case 3:
            mostrar_soma_media(numeros, 8);
            break;
        case 4:
            mostrar_acima_media(numeros, 8);
            break;
        case 0:
            break;
        default:
            printf(RED "Opção inválida!\n" RESET);
        }
    } while (opc != 0);
}

//  FUNÇÕES DO EXERCÍCIO 9
long long fatorial(int n)
{
    if (n <= 1)
        return 1;
    long long resultado = 1;
    for (int i = 2; i <= n; i++)
        resultado *= i;
    return resultado;
}

void exercicio9()
{
    int numeros[6];
    long long fatoriais[6];
    int i;

    printf(BLUE "\n=== EXERCÍCIO 9 - VETOR DE FATORIAL ===\n" RESET);

    printf(YELLOW "Digite 6 números inteiros (recomendado 0-20):\n" RESET);
    for (i = 0; i < 6; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        fatoriais[i] = fatorial(numeros[i]);
    }

    printf(GREEN "\nVetor original: " RESET);
    for (i = 0; i < 6; i++)
        printf("%d ", numeros[i]);

    printf(GREEN "\nVetor fatorial: " RESET);
    for (i = 0; i < 6; i++)
        printf("%lld ", fatoriais[i]);
    printf("\n");
}

//  FUNÇÕES DO EXERCÍCIO 10
void exercicio10()
{
    int matriculas[10], i;
    int count_pares = 0, count_termina5 = 0, count_div3e5 = 0;

    printf(BLUE "\n=== EXERCÍCIO 10 - ANALISADOR DE MATRÍCULAS ===\n" RESET);

    printf(YELLOW "Digite 10 números de matrícula:\n" RESET);
    for (i = 0; i < 10; i++)
    {
        printf("Matrícula %d: ", i + 1);
        scanf("%d", &matriculas[i]);

        if (matriculas[i] % 2 == 0)
            count_pares++;
        if (matriculas[i] % 10 == 5)
            count_termina5++;
        if (matriculas[i] % 3 == 0 && matriculas[i] % 5 == 0)
            count_div3e5++;
    }

    printf(GREEN "\n=== RESULTADOS ===\n" RESET);
    printf("Matrículas pares: %d\n", count_pares);
    printf("Matrículas que terminam em 5: %d\n", count_termina5);
    printf("Matrículas divisíveis por 3 e 5: %d\n", count_div3e5);
}

//  FUNÇÕES DO EXERCÍCIO 11
void exercicio11()
{
    float temperaturas[7], maior, menor, media;
    int i, opc, dias_acima = 0;
    float soma = 0;

    printf(BLUE "\n=== EXERCÍCIO 11 - CONTROLE DE TEMPERATURAS ===\n" RESET);

    printf(YELLOW "Digite 7 temperaturas (uma por dia):\n" RESET);
    for (i = 0; i < 7; i++)
    {
        printf("Dia %d: ", i + 1);
        scanf("%f", &temperaturas[i]);
        soma += temperaturas[i];

        if (i == 0)
        {
            maior = temperaturas[i];
            menor = temperaturas[i];
        }
        else
        {
            if (temperaturas[i] > maior)
                maior = temperaturas[i];
            if (temperaturas[i] < menor)
                menor = temperaturas[i];
        }
    }

    media = soma / 7;
    for (i = 0; i < 7; i++)
        if (temperaturas[i] > media)
            dias_acima++;

    do
    {
        printf(CYAN "\n=== MENU TEMPERATURAS ===\n" RESET);
        printf("1 - Maior e menor temperatura\n");
        printf("2 - Média das temperaturas\n");
        printf("3 - Dias acima da média\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf(GREEN "Maior temperatura: %.2f\n" RESET, maior);
            printf(GREEN "Menor temperatura: %.2f\n" RESET, menor);
            break;
        case 2:
            printf(GREEN "Média das temperaturas: %.2f\n" RESET, media);
            break;
        case 3:
            printf(GREEN "Dias acima da média: %d\n" RESET, dias_acima);
            break;
        case 0:
            break;
        default:
            printf(RED "Opção inválida!\n" RESET);
        }
    } while (opc != 0);
}

//  FUNÇÕES DO EXERCÍCIO 12
void exercicio12()
{
    float notas[6], media, menor_nota;
    int i, opc;
    float soma = 0;

    printf(BLUE "\n=== EXERCÍCIO 12 - SISTEMA DE NOTAS ===\n" RESET);

    printf(YELLOW "Digite 6 notas:\n" RESET);
    for (i = 0; i < 6; i++)
    {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];

        if (i == 0)
            menor_nota = notas[i];
        else if (notas[i] < menor_nota)
            menor_nota = notas[i];
    }

    media = soma / 6;

    do
    {
        printf(CYAN "\n=== SISTEMA DE NOTAS ===\n" RESET);
        printf("1 - Mostrar notas\n");
        printf("2 - Calcular média\n");
        printf("3 - Mostrar notas acima da média\n");
        printf("4 - Mostrar menor nota\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf(GREEN "Notas: " RESET);
            for (i = 0; i < 6; i++)
                printf("%.1f ", notas[i]);
            printf("\n");
            break;
        case 2:
            printf(GREEN "Média: %.2f\n" RESET, media);
            break;
        case 3:
            printf(GREEN "Notas acima da média (%.2f): " RESET, media);
            for (i = 0; i < 6; i++)
                if (notas[i] > media)
                    printf("%.1f ", notas[i]);
            printf("\n");
            break;
        case 4:
            printf(GREEN "Menor nota: %.1f\n" RESET, menor_nota);
            break;
        case 0:
            break;
        default:
            printf(RED "Opção inválida!\n" RESET);
        }
    } while (opc != 0);
}

//  FUNÇÕES DO EXERCÍCIO 13
void exercicio13()
{
    int numeros[10], i, opc, soma_total = 0, soma_pares = 0, soma_impares = 0, produto = 1;

    printf(BLUE "\n=== EXERCÍCIO 13 - VETOR COM OPERAÇÕES MISTAS ===\n" RESET);

    printf(YELLOW "Digite 10 números inteiros:\n" RESET);
    for (i = 0; i < 10; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    do
    {
        printf(CYAN "\n=== OPERAÇÕES ===\n" RESET);
        printf("1 - Somar todos\n");
        printf("2 - Somar apenas pares\n");
        printf("3 - Somar apenas ímpares\n");
        printf("4 - Multiplicar todos\n");
        printf("5 - Resto da soma dividido por 7\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        soma_total = soma_pares = soma_impares = 0;
        produto = 1;

        for (i = 0; i < 10; i++)
        {
            soma_total += numeros[i];
            produto *= numeros[i];
            if (numeros[i] % 2 == 0)
                soma_pares += numeros[i];
            else
                soma_impares += numeros[i];
        }

        switch (opc)
        {
        case 1:
            printf(GREEN "Soma total: %d\n" RESET, soma_total);
            break;
        case 2:
            printf(GREEN "Soma dos pares: %d\n" RESET, soma_pares);
            break;
        case 3:
            printf(GREEN "Soma dos ímpares: %d\n" RESET, soma_impares);
            break;
        case 4:
            printf(GREEN "Produto de todos: %d\n" RESET, produto);
            break;
        case 5:
            printf(GREEN "Resto da soma por 7: %d\n" RESET, soma_total % 7);
            break;
        case 0:
            break;
        default:
            printf(RED "Opção inválida!\n" RESET);
        }
    } while (opc != 0);
}

//  FUNÇÕES DO EXERCÍCIO 14
void exercicio14()
{
    int votos[20], i, opc;
    int candidato1 = 0, candidato2 = 0, candidato3 = 0;

    printf(BLUE "\n=== EXERCÍCIO 14 - SISTEMA DE VOTAÇÃO ===\n" RESET);

    printf(YELLOW "Digite 20 votos (1, 2 ou 3):\n" RESET);
    for (i = 0; i < 20; i++)
    {
        printf("Voto %d: ", i + 1);
        scanf("%d", &votos[i]);

        switch (votos[i])
        {
        case 1:
            candidato1++;
            break;
        case 2:
            candidato2++;
            break;
        case 3:
            candidato3++;
            break;
        default:
            printf(RED "Voto inválido! (use 1, 2 ou 3)\n" RESET);
            i--;
            break;
        }
    }

    printf(GREEN "\n=== RESULTADO DA ELEIÇÃO ===\n" RESET);
    printf("Candidato 1: %d votos\n", candidato1);
    printf("Candidato 2: %d votos\n", candidato2);
    printf("Candidato 3: %d votos\n", candidato3);
    printf("Total de votos: %d\n", candidato1 + candidato2 + candidato3);

    if (candidato1 > candidato2 && candidato1 > candidato3)
        printf(MAGENTA "Vencedor: Candidato 1\n" RESET);
    else if (candidato2 > candidato1 && candidato2 > candidato3)
        printf(MAGENTA "Vencedor: Candidato 2\n" RESET);
    else if (candidato3 > candidato1 && candidato3 > candidato2)
        printf(MAGENTA "Vencedor: Candidato 3\n" RESET);
    else
        printf(YELLOW "Empate!\n" RESET);
}

//  FUNÇÕES DO EXERCÍCIO 15
void exercicio15()
{
    int placas[10], i, ultimo_digito;

    printf(BLUE "\n=== EXERCÍCIO 15 - ANALISADOR DE PLACAS ===\n" RESET);

    printf(YELLOW "Digite os 10 finais de placa (0-9):\n" RESET);
    for (i = 0; i < 10; i++)
    {
        printf("Final %d: ", i + 1);
        scanf("%d", &placas[i]);
    }

    printf(GREEN "\n=== DIAS DE RODÍZIO ===\n" RESET);
    for (i = 0; i < 10; i++)
    {
        ultimo_digito = placas[i] % 10;
        printf("Placa final %d: ", ultimo_digito);

        switch (ultimo_digito)
        {
        case 1:
        case 2:
            printf("Segunda-feira\n");
            break;
        case 3:
        case 4:
            printf("Terça-feira\n");
            break;
        case 5:
        case 6:
            printf("Quarta-feira\n");
            break;
        case 7:
        case 8:
            printf("Quinta-feira\n");
            break;
        case 9:
        case 0:
            printf("Sexta-feira\n");
            break;
        default:
            printf("Inválido\n");
            break;
        }
    }
}

//  FUNÇÕES DO EXERCÍCIO 16
void mostrar_inverso(int vetor[], int tamanho)
{
    printf(GREEN "Vetor invertido: " RESET);
    for (int i = tamanho - 1; i >= 0; i--)
        printf("%d ", vetor[i]);
    printf("\n");
}

int contar_multiplos2(int vetor[], int tamanho)
{
    int count = 0;
    for (int i = 0; i < tamanho; i++)
        if (vetor[i] % 2 == 0)
            count++;
    return count;
}

int soma_posicoes_pares(int vetor[], int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i += 2)
        soma += vetor[i];
    return soma;
}

void exercicio16()
{
    int numeros[10], i, opc;

    printf(BLUE "\n=== EXERCÍCIO 16 - VETOR DINÂMICO DE ESTATÍSTICAS ===\n" RESET);

    printf(YELLOW "Digite 10 números inteiros:\n" RESET);
    for (i = 0; i < 10; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    do
    {
        printf(CYAN "\n=== ESTATÍSTICAS ===\n" RESET);
        printf("1 - Mostrar em ordem inversa\n");
        printf("2 - Contar múltiplos de 2\n");
        printf("3 - Soma das posições pares\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            mostrar_inverso(numeros, 10);
            break;
        case 2:
            printf(GREEN "Múltiplos de 2: %d\n" RESET, contar_multiplos2(numeros, 10));
            break;
        case 3:
            printf(GREEN "Soma das posições pares: %d\n" RESET, soma_posicoes_pares(numeros, 10));
            break;
        case 0:
            break;
        default:
            printf(RED "Opção inválida!\n" RESET);
        }
    } while (opc != 0);
}

//  FUNÇÕES DO EXERCÍCIO 17
void exercicio17()
{
    int vetor[6], i, opc, produto = 1, soma_pares = 0;

    printf(BLUE "\n=== EXERCÍCIO 17 - MENU DE OPERAÇÕES EM VETOR ===\n" RESET);

    printf(YELLOW "Digite 6 valores inteiros:\n" RESET);
    for (i = 0; i < 6; i++)
    {
        printf("v[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    do
    {
        printf(CYAN "\n=== OPERAÇÕES ===\n" RESET);
        printf("1 - Dobrar cada elemento\n");
        printf("2 - Somar elementos das posições pares\n");
        printf("3 - Mostrar vetor invertido\n");
        printf("4 - Calcular produto dos elementos\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf(GREEN "Vetor dobrado: " RESET);
            for (i = 0; i < 6; i++)
            {
                vetor[i] *= 2;
                printf("%d ", vetor[i]);
            }
            printf("\n");
            break;
        case 2:
            soma_pares = 0;
            for (i = 0; i < 6; i += 2)
                soma_pares += vetor[i];
            printf(GREEN "Soma das posições pares: %d\n" RESET, soma_pares);
            break;
        case 3:
            printf(GREEN "Vetor invertido: " RESET);
            for (i = 5; i >= 0; i--)
                printf("%d ", vetor[i]);
            printf("\n");
            break;
        case 4:
            produto = 1;
            for (i = 0; i < 6; i++)
                produto *= vetor[i];
            printf(GREEN "Produto dos elementos: %d\n" RESET, produto);
            break;
        case 0:
            break;
        default:
            printf(RED "Opção inválida!\n" RESET);
        }
    } while (opc != 0);
}

//  FUNÇÕES DO EXERCÍCIO 18
void exercicio18()
{
    float valor, valor_final;
    int opc;

    printf(BLUE "\n=== EXERCÍCIO 18 - SISTEMA DE PAGAMENTO COM DESCONTO ===\n" RESET);

    printf("Digite o valor da compra: R$ ");
    scanf("%f", &valor);

    printf(CYAN "\n=== FORMAS DE PAGAMENTO ===\n" RESET);
    printf("1 - À vista (10%% de desconto)\n");
    printf("2 - Cartão (5%% de desconto)\n");
    printf("3 - 2x sem juros\n");
    printf("4 - 3x com 5%% de juros\n");
    printf("Escolha: ");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        valor_final = valor * 0.9;
        printf(GREEN "Valor final à vista: R$ %.2f\n" RESET, valor_final);
        printf(GREEN "Desconto: R$ %.2f\n" RESET, valor - valor_final);
        break;
    case 2:
        valor_final = valor * 0.95;
        printf(GREEN "Valor final no cartão: R$ %.2f\n" RESET, valor_final);
        printf(GREEN "Desconto: R$ %.2f\n" RESET, valor - valor_final);
        break;
    case 3:
        valor_final = valor;
        printf(GREEN "Valor total: R$ %.2f\n" RESET, valor_final);
        printf(GREEN "2 parcelas de: R$ %.2f\n" RESET, valor / 2);
        break;
    case 4:
        valor_final = valor * 1.05;
        printf(GREEN "Valor total com juros: R$ %.2f\n" RESET, valor_final);
        printf(GREEN "3 parcelas de: R$ %.2f\n" RESET, valor_final / 3);
        break;
    default:
        printf(RED "Opção inválida!\n" RESET);
        break;
    }
}

//  MENU PRINCIPAL
void mostrar_menu()
{
    printf(BLUE "\n╔═════════════════════════════════════════════════════════════════════╗\n" RESET);
    printf(BLUE "║" MAGENTA "                      MENU PRINCIPAL -EXERCÍCIOS                     " BLUE "║\n" RESET);
    printf(BLUE "╠═════════════════════════════════════════════════════════════════════╣\n" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN " 1. Calculadora Modular           " RESET);
    printf(BLUE "║" RESET);
    printf(CYAN " 2. Classificador de Números      " BLUE "║\n" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN " 3. Tabela de Operações com Vetor " RESET);
    printf(BLUE "║" RESET);
    printf(CYAN " 4. Estatísticas de Vetor         " BLUE "║\n" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN " 5. Conversor Matemático          " RESET);
    printf(BLUE "║" RESET);
    printf(CYAN " 6. Pares e Ímpares Separados     " BLUE "║\n" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN " 7. Simulador de Caixa Eletrônico " RESET);
    printf(BLUE "║" RESET);
    printf(CYAN " 8. Análise de Números com Vetor  " BLUE "║\n" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN " 9. Vetor de Fatorial             " RESET);
    printf(BLUE "║" RESET);
    printf(CYAN "10. Analisador de Matrículas      " BLUE "║\n" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN "11. Controle de Temperaturas      " RESET);
    printf(BLUE "║" RESET);
    printf(CYAN "12. Sistema de Notas              " BLUE "║\n" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN "13. Operações Mistas em Vetor     " RESET);
    printf(BLUE "║" RESET);
    printf(CYAN "14. Sistema de Votação            " BLUE "║\n" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN "15. Analisador de Placas          " RESET);
    printf(BLUE "║" RESET);
    printf(CYAN "16. Vetor Dinâmico de Estatísticas" BLUE "║\n" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN "17. Operações Aritméticas em Vetor" RESET);
    printf(BLUE "║" RESET);
    printf(CYAN "18. Sistema de Pagamento          " BLUE "║\n" RESET);
    printf(BLUE "║" RESET);
    printf(RED " 0. Sair do Programa              " RESET);
    printf(BLUE "║" RESET);
    printf(RED "                                  " BLUE "║\n" RESET);
    printf(BLUE "╚═════════════════════════════════════════════════════════════════════╝\n" RESET);
    printf(YELLOW "\nEscolha uma opção (0-18): " RESET);
}

int main()
{
    int opcao;

    printf(MAGENTA "\n     ╔════════════════════════════════════════════════════════════╗\n" RESET);
    printf(MAGENTA "     ║" GREEN "          BEM-VINDO AO SISTEMA DE EXERCÍCIOS EM C           " MAGENTA "║\n" RESET);
    printf(MAGENTA "     ╚════════════════════════════════════════════════════════════╝\n" RESET);

    do
    {
        mostrar_menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            exercicio1();
            break;
        case 2:
            exercicio2();
            break;
        case 3:
            exercicio3();
            break;
        case 4:
            exercicio4();
            break;
        case 5:
            exercicio5();
            break;
        case 6:
            exercicio6();
            break;
        case 7:
            exercicio7();
            break;
        case 8:
            exercicio8();
            break;
        case 9:
            exercicio9();
            break;
        case 10:
            exercicio10();
            break;
        case 11:
            exercicio11();
            break;
        case 12:
            exercicio12();
            break;
        case 13:
            exercicio13();
            break;
        case 14:
            exercicio14();
            break;
        case 15:
            exercicio15();
            break;
        case 16:
            exercicio16();
            break;
        case 17:
            exercicio17();
            break;
        case 18:
            exercicio18();
            break;
        case 0:
            printf(RED "\nSaindo do programa...\n" RESET);
            break;
        default:
            printf(RED "\nOpção inválida!\n" RESET);
            break;
        }

        if (opcao != 0)
        {
            printf(YELLOW "\nPressione Enter para continuar..." RESET);
            getchar();
            getchar();
        }

    } while (opcao != 0);

    return 0;
}