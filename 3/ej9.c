#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *subcadena(char *p, unsigned int i, unsigned int n)
{
    // n caracteres + el \0 final
    char *sub = malloc((n + 1) * sizeof(char));
    p += i;
    int cont = 0;
    while (cont < n)
    {
        *(sub + cont) = *p;
        p++;
        ++cont;
    }
    return sub;
}

char *leerArch(const char *nomArch)
{
    char *puntero = malloc(1);
    FILE *f = fopen(nomArch, "r");
    int i = 0;
    char aux = 'c';
    while (aux != EOF)
    {
        ++i;
        aux = fgetc(f);
        puntero = realloc(puntero, i * sizeof(char));
        puntero[i - 1] = aux;
    }
    puntero[i - 1] = '\0';
    fclose(f);
    return puntero;
}

int main()
{
    char *str = NULL;
    char *subStr = NULL;
    int i = 0, n = 7;
    str = leerArch("frase.txt");
    subStr = subcadena(str, i, n);
    printf("Para i = %d y n = %d, Se encontro el substring: %s", i, n, subStr);

    return 0;
}