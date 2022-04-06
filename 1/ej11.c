#include <stdio.h>
#include <string.h>
#define F 10
#define C 100
#define STERM '\0'
#define LTERM '\n'
#define ERRF -1
#define FNAME "equipos.txt"

int __strcmp(char str1[C], char str2[C]);
void __strcpy(char src[], char dst[]);
void ordenarTexto(char mat[F][C]);
void ordenarMatText(char mat[F][C]);
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
    ordenarMatText(mat);
    printf("------------\n");
    imprimirMatText(mat);
}

void ordenarMatText(char mat[F][C])
{
    int len = lenMatriz(mat);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (__strcmp(mat[i], mat[j]) > 0)
            {
                char aux[C];
                __strcpy(aux, mat[i]);
                __strcpy(mat[i], mat[j]);
                __strcpy(mat[j], aux);
            }
        }
    }
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
    char _STERM = '\0';
    int i = 0;
    while (mat[i][0] != _STERM && i < F)
    {
        i++;
    }
    return i;
}

void __strcpy(char dst[C], char src[C])
{
    char _STERM = '\0';
    int i = 0;
    char aux = 'c';
    while (aux != _STERM)
    {
        aux = src[i];
        dst[i] = aux;
        i++;
    }
}

int __strcmp(char str1[C], char str2[C])
{
    char _STERM = '\0';
    int i = 0;
    char aux1 = 'c';
    char aux2 = 'c';
    while (aux1 != _STERM && aux2 != _STERM)
    {
        aux1 = str1[i];
        aux2 = str2[i];
        if (aux1 == aux2)
        {
            i++;
        }
        else
        {
            if (aux1 > aux2)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    if (aux1 == _STERM)
    {
        if (aux2 == _STERM)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    return 1;
}