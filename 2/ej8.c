#include <stdio.h>

int main()
{
    unsigned char c;
    printf("Ingrese un unsigned char: ");
    scanf("%d", &c);
    mostrarChar(c);
    return 0;
}

void mostrarChar(unsigned char c)
{
    unsigned char mask = 128;
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (mask & c) >> i );
        mask = mask >> 1;
    }
}