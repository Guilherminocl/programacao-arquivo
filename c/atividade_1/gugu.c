#include <stdio.h>

int main()
{
    int soma(int a, int b)
    {

        return a + b;
    }
    
    {
        int resultado = soma(7, 3);
        printf("resultado é %d", resultado);
    }
    return 0;
}