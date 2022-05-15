#include <stdio.h>
#include <stdlib.h>

void intercambiar(int *ptr1, int *ptr2)
{
    int aux = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = aux;
}

int main()
{
    int n1, n2;
    n1 = 1;
    n2 = 2;
    printf("%d %d -> ", n1, n2);
    intercambiar(&n1, &n2);
    printf("%d %d\n", n1, n2);
    return 0;
}