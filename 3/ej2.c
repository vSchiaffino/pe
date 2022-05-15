#include <stdio.h>

int *punteroPosicion(int arr[], int posicion)
{
    return arr + posicion;
}

int main()
{
    int arr[] = {1, 2, 3};
    int posicion = 3;
    printf("posicion[%d] = %p\n", posicion, punteroPosicion(arr, posicion));
    return 0;
}