#include <stdio.h>
#include <stdlib.h>
#define T 100

void invertir(int *arreglo, int tamano)
{
    if (tamano > 1)
    {
        int aux = arreglo[0];
        arreglo[0] = arreglo[tamano - 1];
        arreglo[tamano - 1] = aux;
        invertir(arreglo + 1, tamano - 2);
    }
}

void imprimir(int *arreglo, int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        printf("%d ", *arreglo);
        arreglo++;
    }
}

int main()
{
    int arreglo[5] = {5, 2, 3, 4, 5};
    invertir(arreglo, 5);
    imprimir(arreglo, 5);

    return 0;
}