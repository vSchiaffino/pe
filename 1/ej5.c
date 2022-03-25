#include <stdio.h>
#define T 100
int esPos(int n);
void cargarArrPNR(int arr[]);
int estaEnArr(int arr[], int elemento);
int imprimirArr(int arr[]);

int main()
{
    int arr[T + 1];
    // pongo la bandera para saber donde
    // esta el final de los elementos
    // utiles del array
    arr[0] = 0;
    cargarArrPNR(arr);
    imprimirArr(arr);
    return 0;
}

void cargarArrPNR(int arr[])
{
    int aux;
    int i = 0;
    while (aux != 0)
    {
        imprimirArr(arr);
        scanf("%d", &aux);
        if (estaEnArr(arr, aux))
        {
            printf("El numero ingresado ya esta en el array.\n");
        }
        else if (!esPos(aux))
        {
            printf("El numero ingresado es negativo.\n");
        }
        else
        {
            arr[i] = aux;
            // pongo la bandera para saber donde
            // esta el final de los elementos
            // utiles del array
            arr[i + 1] = 0;
            i++;
        }
    }
}

int estaEnArr(int arr[], int elemento)
{
    int i = 0;
    while (arr[i] != 0 || i > T)
    {
        if (arr[i] == elemento)
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int esPos(int n)
{
    return n >= 0;
}

int imprimirArr(int arr[])
{
    printf("[");
    int i = 0;
    while (arr[i] != 0)
    {
        printf("%d", arr[i]);
        if (arr[i + 1] != 0)
        {
            printf(", ");
        }
        i++;
    }
    printf("]\n");
}