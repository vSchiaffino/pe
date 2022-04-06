#include <stdio.h>
#define F 10
#define C 100
#define STERM '\0'
#define LTERM '\n'
#define ERRF -1
#define FNAME "equipos.txt"

void imprimirMatText(char mat[F][C]);
int cargarMatTexDeArch(char mat[F][C], char fname[]);
int lenMatriz(char mat[F][C]);

int main()
{
    char mat[F][C];
    if (cargarMatTexDeArch(mat, FNAME) == ERRF)
    {
        printf("ERROR: El archivo %s no fue encontrado.\n", FNAME);
        return ERRF;
    }
    imprimirMatText(mat);
}

int cargarMatTexDeArch(char mat[F][C], char fname[])
{
    FILE *f;
    f = fopen(fname, "r");
    if (f == NULL)
    {
        // Retorna error porque no encontró el archivo.
        return ERRF;
    }
    char aux = STERM;
    int i = 0;
    int j = 0;
    while (!feof(f))
    {
        int aux = fgetc(f);
        if (aux == LTERM)
        {
            // Fin de linea
            mat[i][j] = STERM;
            i++;
            j = 0;
        }
        else
        {
            mat[i][j] = aux;
            j++;
        }
    }
    mat[i][j - 1] = '\0';
    fclose(f);
    return 0;
}

void imprimirMatText(char mat[F][C])
{
    for (int i = 0; i < lenMatriz(mat); i++)
    {
        printf("%s\n", mat[i]);
    }
}

int lenMatriz(char mat[F][C])
{
    int i = 0;
    while (mat[i][0] != STERM && i < F)
    {
        i++;
    }
    return i;
}