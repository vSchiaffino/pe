#include <stdio.h>
#include <string.h>
#define F 10
#define C 100
#define STERM '\0'
#define LTERM '\n'

void cargarMatText(char mat[F][C]);
void imprimirMatText(char mat[F][C]);
void ordenarMatText(char mat[F][C]);
int lenMatriz(char mat[F][C]);
void leer(char msj[], char arr[C]);

int main()
{
    char mat[F][C];
    cargarMatText(mat);
    printf("------------\n");
    ordenarMatText(mat);
    imprimirMatText(mat);

    return 0;
}

void ordenarMatText(char mat[F][C])
{
    int len = lenMatriz(mat);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (strcmp(mat[i], mat[j]) > 0)
            {
                char aux[C];
                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }
        }
    }
}

void cargarMatText(char mat[F][C])
{
    int i = 0;
    while ((i == 0 || mat[i - 1][0] != STERM) && i < F)
    {
        leer("Ingrese palabra: ", mat[i]);
        i++;
    }
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

void leer(char msj[], char arr[C])
{
    fflush(stdin);
    printf("%s", msj);
    int i = 0;
    // Le cargo un valor a aux porque sino
    // le pone como valor basura que ya tenia antes
    char aux = '\0';
    while (aux != LTERM && i < C - 1)
    {
        aux = getchar();

        arr[i] = aux;
        i++;
    }
    arr[i - 1] = '\0';
}
