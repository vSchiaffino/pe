
#include <stdio.h>
#define MAX_S 400
#define N 20
#define FNAME "personas.txt"
#include <string.h>

struct s_persona
{
    int documento;
    char nombre[MAX_S];
    char pais[MAX_S];
};

typedef struct s_persona Persona;

int pedirOpcion();
void cargarTabla(Persona personas[]);
void leerString(FILE *f, char s[], char separador);
void imprimirTabla(Persona personas[]);
void ordenarTabla(Persona personas[], int opcion);
int lenTabla(Persona personas[]);

int main()
{
    int opcion = 0;
    Persona personas[20];
    while (opcion != 4)
    {
        cargarTabla(personas);
        opcion = pedirOpcion();
        if (opcion != 4)
        {
            ordenarTabla(personas, opcion);
            imprimirTabla(personas);
        }
    }
    return 0;
}

void cargarTabla(Persona personas[])
{
    FILE *f = fopen(FNAME, "r");
    int i = 0;
    while (!feof(f) && i < N)
    {
        Persona p;
        fscanf(f, "%d,", &p.documento);
        leerString(f, p.nombre, ',');
        leerString(f, p.pais, '\n');
        if (!feof(f))
            personas[i] = p;

        ++i;
    }
    if (i != N)
        personas[i].documento = 0;
}

void leerString(FILE *f, char s[], char separador)
{
    char aux = 'c';
    int i = 0;
    while (i < MAX_S && aux != separador)
    {
        aux = fgetc(f);

        s[i] = aux;
        ++i;
    }
    s[i - 1] = '\0';
}

void imprimirTabla(Persona personas[])
{
    int i = 0;
    printf("%-10s %-20s %-20s\n", "Documento", "Nombre", "Pais");
    for (int i = 0; i < 53; i++)
    {
        printf("=");
    }
    printf("\n\n");
    for (int i = 0; i < lenTabla(personas); i++)
    {
        Persona p = personas[i];
        printf("%-10d %-20s %-20s\n", p.documento, p.nombre, p.pais);
    }
}

void ordenarTabla(Persona personas[], int opcion)
{
    int len = lenTabla(personas);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (
                (opcion == 1 && strcmpi(personas[i].nombre, personas[j].nombre) > 0) ||
                (opcion == 2 && personas[i].documento > personas[j].documento) ||
                (opcion == 3 && strcmpi(personas[i].pais, personas[j].pais) > 0))
            {
                Persona aux = personas[i];
                personas[i] = personas[j];
                personas[j] = aux;
            }
        }
    }
}

int lenTabla(Persona personas[])
{
    int i = 0;
    while (i < N && personas[i].documento != 0)
    {
        ++i;
    }
    return i;
}

int pedirOpcion()
{
    printf("1. Ver listado ordenado por nombre\n");
    printf("2. Ver listado ordenado por documento\n");
    printf("3. Ver listado ordenado por país\n");
    printf("4. Salir del programa\n");
    int opcion;
    scanf("%d", &opcion);
    return opcion;
}