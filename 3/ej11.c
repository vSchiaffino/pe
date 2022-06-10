#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a, b;
} Dosint;

void intercambiar(int *ptr1, int *ptr2)
{
    int aux = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = aux;
}

int main()
{
    Dosint dosint = {4, 5};
    printf("Antes: %d - %d\n", dosint.a, dosint.b);
    intercambiar(&dosint.a, &dosint.b);
    printf("Despues: %d - %d\n", dosint.a, dosint.b);

    return 0;
}
