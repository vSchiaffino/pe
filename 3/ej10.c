#include <stdio.h>
#include <stdlib.h>

typedef struct s_texto
{
    char *txt;
    unsigned int longitud;
} Texto;

Texto cargarTexto()
{
    Texto texto;
    texto.longitud = 0;
    texto.txt = malloc(1);
    fflush(stdin);
    char aux = 'c';
    while (aux != '\n')
    {
        aux = getchar();
        texto.longitud++;
        texto.txt = realloc(texto.txt, texto.longitud * sizeof(char));
        texto.txt[texto.longitud - 1] = aux;
    }
    texto.txt[texto.longitud - 1] = '\0';
    return texto;
}

void escribirArchTex(const char *name, Texto texto)
{
    FILE *f = fopen(name, "w");
    fprintf(f, "%d,%s", texto.longitud, texto.txt);
    fclose(f);
}

int main()
{
    escribirArchTex("frases_con_longitud.csv", cargarTexto());
    return 0;
}