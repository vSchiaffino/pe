#include <stdio.h>
#include <stdlib.h>

char *cargarStrDin()
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

int main()
{
    char *str = cargarStrDin();
    printf("Cargado: %s", str);

    return 0;
}
