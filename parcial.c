#include <stdio.h>
#include <stdlib.h>
#define FITEMS "1/items.txt"
#define FDATOS "1/datos.txt"

struct s_fila{
    char* equipo;
    int pts;
    int pj;
    int pg;
    int pe;
    int pp;
    int gf;
    int fc;
    int dif;
};

typedef struct s_fila Fila;

Fila* cargarEquipos()
{
    Fila* filas = malloc(1);
    FILE* fitems = fopen(FITEMS, "r");
    FILE* fdatos = fopen(FDATOS, "r");
    int i = 0;
    while(!feof(fitems))
    {
        Fila fila;
        fila.equipo = malloc(1);
        filas = realloc(filas, (i+1) * sizeof(Fila));
        int j = 0;
        char aux = 'c';
        while(!feof(fitems))
        {
            aux = fgetc(fitems);
            fila.equipo = realloc(fila.equipo, (j+1) * sizeof(char));
            fila.equipo[j] = aux;
            ++j;
        }
        char aux = 'c';
        while(!feof(fdatos))
        {
            fscanf("%d,%d,%d")
        }
        fila.equipo = realloc(fila.equipo, (j) * sizeof(char));
        fila.equipo[j-1] = '\0';
        filas = realloc(filas, (i+1)*sizeof(Fila));
        filas[i] = fila;
        i++;
    }
    Fila fila;
    fila.pts = -1;
    filas = realloc(filas, (i+1)*sizeof(Fila));
    filas[i] = fila;

    return filas;
}

void mostrarEquipos(Fila* filas)
{
    int i = 0;
    while (filas[i].pts != -1)
    {
        printf("%s\n", filas[i].equipo);
        ++i;
    }
    
}

int main()
{
    Fila* filas = cargarEquipos();
    mostrarEquipos(filas);

    return 0;
}