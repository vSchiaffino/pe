#include <stdio.h>
#include <stdlib.h>

char *cargarStrDin1()
{
    char *puntero = malloc(1);
    int i = 0;
    char aux = 'c';
    while (aux != '\n')
    {
        ++i;
        aux = getchar();
        puntero = realloc(puntero, i * sizeof(char));
        puntero[i - 1] = aux;
    }
    puntero[i - 1] = '\0';
    return puntero;
}

void cargarStrDin2(char **str)
{
    char *puntero = cargarStrDin1();
    *str = puntero;
}

int main()
{
    char *str = cargarStrDin1();
    printf("Cargado 1: %s\n", str);
    char *str2;
    cargarStrDin2(&str2);
    printf("Cargado 2: %s\n", str2);
}