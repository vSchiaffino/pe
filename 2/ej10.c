#include <stdio.h>

int cantidadUnos(unsigned int n)
{
    int CANTIDAD_BITS = 32;
    unsigned int mask = 1;
    int cantidad = 0;
    for (int i = 0; i < CANTIDAD_BITS; i++)
    {
        int bit = n & mask;
        n = n >> 1;
        cantidad += bit;
    }
    return cantidad;
}

int main()
{
    printf("unos: %d", cantidadUnos(44));
    return 0;
}
