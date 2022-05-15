#include <stdio.h>
#include <stdlib.h>

int maxArray(int *arr, int maximo)
{
    if (*arr == 0)
        return maximo;
    if (*arr > maximo)
        maximo = *arr;
    return maxArray(arr + 1, maximo);
}

int *maxArrayPuntero(int *arr, int *maximo)
{
    if (*arr == 0)
        return maximo;
    if (maximo == NULL || *arr > *maximo)
        maximo = arr;
    return maxArrayPuntero(arr + 1, maximo);
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 90, 1, 2, 58, 0};
    int *pmax = arr + 5;
    printf("maximo es: %p = %d", pmax, *pmax);

    printf("max = %d\n", maxArray(arr, 0));

    int *p = maxArrayPuntero(arr, NULL);
    printf("max puntero %p = %d\n", p, *p);
    return 0;
}