#include <stdio.h>
#define F 5
#define C 8
#define FNAME "puntos.txt"

void cargarMatNumDeArch(int mat[F][C], char fname[]);
void imprimirMat(int mat[F][C]);

int main()
{
    int mat[F][C];
    cargarMatNumDeArch(mat, FNAME);
    imprimirMat(mat);
}

void cargarMatNumDeArch(int mat[F][C], char fname[])
{
    FILE *f = fopen(fname, "r");
    int aux = 0;
    char sep;
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C - 1; j++)
        {
            if (i == C - 1)
            {
                sep = '\n';
            }
            fscanf(f, "%d,", &aux);
            mat[i][j] = aux;
        }
        fscanf(f, "%d\n", &aux);
        mat[i][C - 1] = aux;
    }
    fclose(f);
}

void imprimirMat(int mat[F][C])
{
    int aux;
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if(mat[i][j] > 0 && j == C-1){
                // esto es para que aparezca el +
                printf("%+5d", mat[i][j]);
            }
            else{
                printf("%5d", mat[i][j]);
            }
        }
        printf("\n");
    }
}