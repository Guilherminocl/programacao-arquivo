#include <stdio.h>

void dobro(int x)
{
    printf("O dobro é: %d", x * 2 ,"\n");
}

int main()
{
    dobro(2);
    dobro(3);
    dobro(4);
    return 0;
}