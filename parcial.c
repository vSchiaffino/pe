#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FITEMS "1/items.txt"
#define FDATOS "1/datos.txt"

struct s_string
{
    char *arreglo;
    int size;
};

typedef struct s_string String;

struct s_fila
{
    String equipo;
    int pts;
    int pj;
    int pg;
    int pe;
    int pp;
    int gf;
    int gc;
    int dif;
};

typedef struct s_fila Fila;

struct s_filas
{
    Fila *arreglo;
    int size;
};
typedef struct s_filas Filas;

String crearString()
{
    String string;
    string.arreglo = (char *)malloc(sizeof(char));
    *string.arreglo = '\0';
    string.size = 0;
    return string;
}

String limpiarString(String *string)
{
    string->size = 0;
    string->arreglo = realloc(string->arreglo, sizeof(char));
    string->arreglo[0] = '\0';
}

void append(String *string, char c)
{
    printf("intento apendear string: %c -", c);
    string->size++;
    // falta un +1 en el realloc?
    string->arreglo = (char *)realloc(string->arreglo, sizeof(char) * (string->size));
    char *puntero = string->arreglo;
    while (*puntero != '\0')
    {
        puntero++;
    }
    *puntero = c;
    *(puntero + 1) = '\0';
    printf("termine\n", c);
}

Filas crearFilas()
{
    Filas filas;
    filas.arreglo = malloc(1);
    filas.size = 0;
    return filas;
}

void appendFila(Filas *filas, Fila fila)
{
    filas->size++;
    filas->arreglo = realloc(filas->arreglo, sizeof(Fila) * filas->size);
    char *nuevoString = malloc(sizeof(char) * filas->arreglo->equipo.size + 1);
    strcpy(nuevoString, fila.equipo.arreglo);
    fila.equipo.arreglo = nuevoString;
    filas->arreglo[filas->size - 1] = fila;
}

void mostrarFila(Fila fila)
{
    int pts;
    int pj;
    int pg;
    int pe;
    int pp;
    int gf;
    int fc;
    int dif;
    printf("%-15s %4d %4d %4d %4d %4d %4d %4d %4d\n", fila.equipo.arreglo, fila.pts, fila.pj, fila.pg, fila.pe, fila.pp, fila.gf, fila.gc, fila.dif);
}

void mostrarFilas(Filas filas)
{
    printf("%-15s %4s %4s %4s %4s %4s %4s %4s %4s\n", "Equipo", "PTS", "PJ", "PG", "PE", "PP", "GF", "GC", "DIF");
    for (int i = 0; i < 55; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < filas.size; i++)
    {
        mostrarFila(filas.arreglo[i]);
    }
}

void cargarItems(Filas *filas)
{
    FILE *f = fopen(FITEMS, "r");
    String string = crearString();
    char aux;
    while (aux != EOF)
    {
        aux = fgetc(f);
        if (aux == '\n')
        {
            Fila fila = {string, 0, 0, 0, 0, 0, 0, 0, 0};
            appendFila(filas, fila);
            limpiarString(&string);
        }
        else if (aux != EOF)
        {
            append(&string, aux);
        }
    }
}

void cargarDatos(Filas *filas)
{
    FILE *f = fopen(FDATOS, "r");
    int i = 0;
    while (i < filas->size && !feof(f))
    {
        Fila *fila = &filas[0].arreglo[i];
        fscanf(f, "%d,%d,%d,%d,%d,%d,%d,%d\n", &fila->pts, &fila->pj, &fila->pg, &fila->pe, &fila->pp, &fila->gf, &fila->gc, &fila->dif);
        i++;
    }
}

int main()
{
    Filas filas = crearFilas();
    cargarItems(&filas);
    cargarDatos(&filas);
    mostrarFilas(filas);
    printf("sali bien");
    return 0;
}