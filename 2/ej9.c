#include<stdio.h>
unsigned char shiftearDerechaConZero(unsigned char c, int veces);

int main()
{
    printf("%d", shiftearDerechaConZero(97, 1));
    return 0;
}

unsigned char shiftearDerechaConZero(unsigned char c, int veces)
{
    unsigned char mask = 255;
    for (int i = 0; i < veces; i++)
    {
        mask >> 1;
        c = (c >> 1) & mask;
    }
    return c;
}