#include <stdio.h>
#include <stdlib.h>

char *cargarStrDin1()
{
    fflush(stdin);
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

void escribirArch(const char *file, char *str)
{
    FILE *f = fopen(file, "w");
    fprintf(f, "%s", str);
    fclose(f);
}

void imprimirArch(const char *file)
{
    FILE *f = fopen(file, "r");
    while (!feof(f))
    {
        char aux = fgetc(f);
        printf("%c", aux);
    }
    fclose(f);
}

int main()
{
    char *str = NULL;
    // str = cargarStrDin1();
    cargarStrDin2(&str);
    escribirArch("frase.txt", str);
    imprimirArch("frase.txt");
    return 0;
}