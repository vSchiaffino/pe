#include <stdio.h>
#include <string.h>
#define F 10
#define C 100
#define STERM '\0'
#define LTERM '\n'
#define ERRF -1
#define FNAME_ITEMS "../1/items.txt"
#define FNAME_PUNTOS "../1/puntos.txt"

struct s_fila
{
    char equipo[C];
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

void imprimirFilas(Fila filas[]);
int cargarFilas(Fila filas[], char items_fname[], char equipos_fname[]);

int main()
{
    Fila filas[F];
    if (cargarFilas(filas, FNAME_ITEMS, FNAME_PUNTOS) == ERRF)
    {
        printf("ERROR: El archivo no fue encontrado.\n");
        return ERRF;
    }
    printf("\n\nNORMAL: \n");
    imprimirFilas(filas);
    ordenarFilas(filas, 1);
    printf("\n\nPor puntos\n");
    imprimirFilas(filas);
    ordenarFilas(filas, 9);
    printf("\n\nPor diferencia de gol\n");
    imprimirFilas(filas);
    ordenarFilas(filas, 6);
    printf("\n\nGoles a favor\n");
    imprimirFilas(filas);
    return 0;
}

int lenMatriz(Fila filas[])
{
    int i = 0;
    while (filas[i].pj != -1 && i < C)
    {
        ++i;
    }
    return i;
}

void ordenarFilas(Fila filas[], int columna)
{
    int len = lenMatriz(filas);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (
                columna == 1 && (filas[i].pts < filas[j].pts) ||
                columna == 9 && (filas[i].dif < filas[j].dif) ||
                columna == 6 && (filas[i].gf < filas[j].gf))
            {
                Fila aux = filas[i];
                filas[i] = filas[j];
                filas[j] = aux;
            }
        }
    }
}

int cargarFilas(Fila filas[], char items_fname[], char puntos_fname[])
{
    FILE *f_items, *f_puntos;
    f_items = fopen(items_fname, "r");
    f_puntos = fopen(puntos_fname, "r");
    if (f_puntos == NULL || f_items == NULL)
    {
        // Retorna error porque no encontró el archivo.
        return ERRF;
    }
    int i = 0;
    while (i < F && !feof(f_items) && !feof(f_puntos))
    {
        Fila fila;
        fscanf(
            f_puntos,
            "%d,%d,%d,%d,%d,%d,%d,%d\n",
            &fila.pts, &fila.pj, &fila.pg, &fila.pe, &fila.pp, &fila.gf, &fila.gc, &fila.dif);

        int j = 0;
        char aux = 'c';
        while (j < C && aux != LTERM)
        {
            aux = fgetc(f_items);
            fila.equipo[j] = aux;
            ++j;
        }
        fila.equipo[j - 1] = STERM;
        filas[i] = fila;
        ++i;
    }
    if (i != F)
        // esta es mi flag
        filas[i].pj = -1;
    fclose(f_items);
    fclose(f_puntos);
    return 0;
}

void imprimirFilas(Fila filas[])
{
    int i = 0;
    printf("%-15s %5s %5s %5s %5s %5s %5s %5s %5s\n", "Equipo", "PTS", "PJ", "PG", "PE", "PP", "GF", "GC", "DIF");
    for (int i = 0; i < 63; i++)
    {
        printf("-");
    }
    printf("\n");
    while (filas[i].pj != -1)
    {
        Fila f = filas[i];
        printf("%-15s %5d %5d %5d %5d %5d %5d %5d %5d\n", f.equipo, f.pts, f.pj, f.pg, f.pe, f.pp, f.gf, f.gc, f.dif);
        ++i;
    }
    for (int i = 0; i < 63; i++)
    {
        printf("-");
    }
    printf("\n");
}