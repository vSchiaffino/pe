#include <stdio.h>
#define T 100

int cargarArr(int arr[]);
int imprimirArr(int arr[]);
int invertirArr(int arr[]);
int lenArr(int arr[]);
int ordernarArr(int arr[]);

int main()
{
    int arr1[T];
    int arr2[T];

    printf("-- Primer arreglo --\n");
    cargarArr(arr1);
    invertirArr(arr1);
    imprimirArr(arr1);
    printf("-- Segundo arreglo --\n");
    cargarArr(arr2);
    ordernarArr(arr2);
    imprimirArr(arr2);
    return 0;
}

int cargarArr(int arr[])
{
    int aux;
    int i = 0;
    while (aux != 0)
    {
        printf("Ingrese numeros enteros: ");
        scanf("%d", &aux);
        arr[i] = aux;
        i++;
    }
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

int invertirArr(int arr[])
{
    int len = lenArr(arr);
    int recorrer = len / 2;
    int j = len - 1;
    for (int i = 0; i < recorrer; i++)
    {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
        j--;
    }
}

int lenArr(int arr[])
{
    int i = 0;
    while (arr[i] != 0)
    {
        i++;
    }
    return i;
}

int ordernarArr(int arr[])
{
    int len = lenArr(arr);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}
