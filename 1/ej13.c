#include <stdio.h>
#include <string.h>
#define FCABECERAS "cabeceras.txt"
#define FITEMS "items.txt"
#define FDATOS "datos.txt"
#define LENDATOS 8
void leerArchivoPorRenglones(char mat[][100], char fname[]);
void intcpy(int dst[LENDATOS], int src[LENDATOS]);

void leerCabeceras(char mat[][100], char fname[]);
void leerItems(char mat[][100], char fname[]);
void leerDatos(int mat[][LENDATOS], char fname[]);

void imprimirCuerpo(char items[][100], int datos[][LENDATOS], int lenDatos);
void imprimirCabecera(char cabeceras[][100]);
void imprimirTabla(
    char cabeceras[][100],
    char items[][100],
    int datos[][LENDATOS]);
void ordenarTabla(
    char items[][100],
    int datos[][LENDATOS],
    int columnaOrdenamiento,
    int esDescendente);

int main()
{
    char cabeceras[10][100];
    char items[50][100];
    int datos[100][LENDATOS];
    leerCabeceras(cabeceras, FCABECERAS);
    leerItems(items, FITEMS);
    leerDatos(datos, FDATOS);
    imprimirTabla(cabeceras, items, datos);
    printf("---\n");
    ordenarTabla(items, datos, 6, 1);
    imprimirTabla(cabeceras, items, datos);

    return 0;
}

void leerCabeceras(char mat[][100], char fname[])
{
    leerArchivoPorRenglones(mat, fname);
}

void leerItems(char mat[][100], char fname[])
{
    leerArchivoPorRenglones(mat, fname);
}

void leerDatos(int mat[][LENDATOS], char fname[])
{
    int cantDatosPorRenglon = LENDATOS;
    FILE *f = fopen(fname, "r");
    int i = 0;
    int aux;
    while (!feof(f))
    {
        for (int j = 0; j < cantDatosPorRenglon - 1; j++)
        {
            fscanf(f, "%d,", &aux);
            mat[i][j] = aux;
        }
        fscanf(f, "%d\n", &aux);
        mat[i][cantDatosPorRenglon - 1] = aux;
        i++;
    }
}

void leerArchivoPorRenglones(char mat[][100], char fname[])
{
    char STERM = '\0';
    char ENDL = '\n';
    FILE *f = fopen(fname, "r");
    int i = 0, j = 0;
    while (!feof(f))
    {
        char aux = fgetc(f);
        if (aux == ENDL)
        {
            mat[i][j] = STERM;
            j = 0;
            i++;
        }
        else
        {
            mat[i][j] = aux;
            j++;
        }
    }
    mat[i][0] = STERM;
    fclose(f);
}

void ordenarTabla(
    char items[][100],
    int datos[][LENDATOS],
    int columnaOrdenamiento,
    int esDescendente)
{
    int lenItems = 0;
    char STERM = '\0';
    while (items[lenItems][0] != STERM)
    {
        lenItems++;
    }
    for (int i = 0; i < lenItems - 1; i++)
    {
        for (int j = i + 1; j < lenItems; j++)
        {
            if (
                esDescendente && (datos[i][columnaOrdenamiento] < datos[j][columnaOrdenamiento]) ||
                !esDescendente && (datos[i][columnaOrdenamiento] > datos[j][columnaOrdenamiento]))
            {
                int aux[LENDATOS];
                intcpy(aux, datos[i]);
                intcpy(datos[i], datos[j]);
                intcpy(datos[j], aux);
                char saux[100];
                strcpy(saux, items[i]);
                strcpy(items[i], items[j]);
                strcpy(items[j], saux);
            }
        }
    }
}

void imprimirTabla(
    char cabeceras[][100],
    char items[][100],
    int datos[][LENDATOS])
{
    imprimirCabecera(cabeceras);
    imprimirCuerpo(items, datos, LENDATOS);
}

void imprimirCabecera(char cabeceras[][100])
{
    int i = 0;
    char STERM = '\0';
    while (cabeceras[i][0] != STERM)
    {
        if (i == 0)
        {
            printf("%-15s", cabeceras[i]);
        }
        else
        {
            printf("%5s", cabeceras[i]);
        }
        i++;
    }
    printf("\n");
    int cantidadGuiones = 15 + 5 * (i - 1);
    for (int i = 0; i < cantidadGuiones; i++)
    {
        printf("-");
    }
    printf("\n");
}

void imprimirCuerpo(char items[][100], int datos[][LENDATOS], int lenDatos)
{
    char STERM = '\0';
    int i = 0;
    while (items[i][0] != STERM)
    {
        printf("%-15s", items[i]);
        for (int j = 0; j < lenDatos; j++)
        {
            printf("%5d", datos[i][j]);
        }
        printf("\n");
        i++;
    }
}

void intcpy(int dst[LENDATOS], int src[LENDATOS])
{
    for (int i = 0; i < LENDATOS; i++)
    {
        dst[i] = src[i];
    }
}