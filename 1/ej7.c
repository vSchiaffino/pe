#include <stdio.h>
#define F 3
#define C 4

void cargarMat(int mat[F][C]);
void imprimirMat(int mat[F][C]);
void imprimirCabeceraMatriz(char inicio, char final);
float promMat(int mat[F][C]);

int main()
{
    int mat[F][C];
    cargarMat(mat);
    imprimirMat(mat);
    printf("Promedio: %f", promMat(mat));
    return 0;
}

void cargarMat(int mat[F][C])
{
    int aux;
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("Ingrese numero (pos [%d][%d]): ", i, j);
            scanf("%d", &aux);
            mat[i][j] = aux;
        }
    }
}

void imprimirMat(int mat[F][C])
{
    int aux;
    imprimirCabeceraMatriz(218, 191);
    for (int i = 0; i < F; i++)
    {
        printf("%c", 179);
        for (int j = 0; j < C; j++)
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
    for (int i = 0; i < C * 6; i++)
    {
        printf(" ");
    }

    printf("%c\n", final);
}

float promMat(int mat[F][C])
{
    int sum = 0;
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            sum += mat[i][j];
        }
    }
    // casteo el (f * c) a float porque sino me trunca
    // el resultado porque piensa que estoy queriendo
    // hacer una division entera
    return sum / (float)(F * C);
}