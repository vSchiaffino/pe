#include <stdio.h>
#define T 4

void imprimirMat(int mat[T][T]);
void imprimirCabeceraMatriz(char inicio, char final);
void trasponer(int mat[T][T]);
void cargarMat(int mat[T][T]);

int main()
{
    int mat[T][T];
    cargarMat(mat);
    imprimirMat(mat);
    trasponer(mat);
    imprimirMat(mat);
    return 0;
}

void trasponer(int mat[T][T])
{
    int flag = 1;
    int aux;
    for (int i = 0; i < T; i++)
    {
        for (int j = flag; j < T; j++)
        {
            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
        flag++;
    }
}

void cargarMat(int mat[T][T])
{
    int aux;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            printf("Ingrese numero (pos [%d][%d]): ", i, j);
            scanf("%d", &aux);
            mat[i][j] = aux;
        }
    }
}

void imprimirMat(int mat[T][T])
{
    int aux;
    imprimirCabeceraMatriz(218, 191);
    for (int i = 0; i < T; i++)
    {
        printf("%c", 179);
        for (int j = 0; j < T; j++)
        {
            printf("%5d", mat[i][j]);
        }
        printf("%5c%c\n", 0, 179);
    }
    imprimirCabeceraMatriz(192, 217);
}

// No hace falta hacer esto, pero queda lindo 8)
void imprimirCabeceraMatriz(char inicio, char final)
{
    printf("%c", inicio);
    for (int i = 0; i < ((T + 1) * 5); i++)
    {
        printf(" ");
    }

    printf("%c\n", final);
}
