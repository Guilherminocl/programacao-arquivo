#include <stdio.h>

int ehPar(int n)
{
    return n % 2 == 0;
}

int main()
{
    if (ehPar(0))
    {
        printf("0 é par\n");
    }
    else
    {
        printf("0 é ímpar\n");
    }
    if (ehPar(1))
    {
        printf("1 é par\n");
    }
    else
    {
        printf("1 é ímpar\n");
    }
    if (ehPar(2))
    {
        printf("2 é par\n");
    }
    else
    {
        printf("2 é ímpar\n");
    }
    if (ehPar(3))
    {
        printf("3 é par\n");
    }
    else
    {
        printf("3 é ímpar\n");
    }
    if (ehPar(10))
    {
        printf("10 é par\n");
    }
    else
    {
        printf("10 é ímpar\n");
    }
    if (ehPar(15))
    {
        printf("15 é par\n");
    }
    else
    {
        printf("15 é ímpar\n");
    }
    return 0;
}
