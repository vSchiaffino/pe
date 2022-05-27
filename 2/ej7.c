#include <stdio.h>
#define MAX_S 100
#define MAX_MATERIAS 30

struct s_alumno
{
    char nombre[MAX_S];
    int legajo;
    int materias[30];
};
typedef struct s_alumno Alumno;

struct s_materia
{
    char nombre[MAX_S];
    int codigo;
};
typedef struct s_materia Materia;

struct s_nota
{
    int legajo_alumno;
    int cod_materia;
    int nota;
};
typedef struct s_nota Nota;

int main()
{
    guardarMaterias();
    return 0;
}

void pedirString(char s[])
{
    int i = 0;
    char aux = 'd';
    fflush(stdin);
    while (i < MAX_S && aux != '\n')
    {
        aux = getchar();
        s[i] = aux;
        ++i;
    }
    if (i != MAX_S)
    {
        s[i - 1] = '\0';
    }
}

void guardarAlumnos()
{
    FILE *f = fopen("alumnos.txt", "w");
    int legajo = -1;
    char nombre[MAX_S];
    while (legajo != 0)
    {
        printf("Ingrese numero de legajo: ");
        scanf("%d", &legajo);
        if (legajo != 0)
        {
            printf("Ingrese nombre: ");
            pedirString(&nombre);
            int i = 0;
            int aux = -1;
            fprintf(f, "%d,%s\n", legajo, nombre);
            while (i < MAX_MATERIAS && aux != 0)
            {
                printf("Ingrese materias[%d]: ", i);
                scanf("%d", &aux);
                if (aux == 0)
                {
                    fprintf(f, "\n");
                }
                else
                {
                    if (i != 0)
                    {
                        fprintf(f, ",%d", aux);
                    }
                    else
                    {
                        fprintf(f, "%d", aux);
                    }
                }
                ++i;
            }
        }
    }
    fclose(f);
}

void guardarMaterias()
{
    FILE *f = fopen("materias.txt", "w");
    int i = 0;
    int codigo = -1;
    char nombre[MAX_S];
    while (i < MAX_MATERIAS && codigo != 0)
    {
        printf("Ingrese codigo: ");
        scanf("%d", &codigo);
        if (codigo != 0)
        {
            printf("Ingrese nombre: ");
            pedirString(nombre);
            fprintf(f, "%d,%s\n", codigo, nombre);
        }
    }
    fclose(f);
}