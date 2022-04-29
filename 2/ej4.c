#include <stdio.h>
#define N 10
#define MAX_S 400
#define FNAME "personas.txt"

struct s_persona
{
    int documento;
    char nombre[MAX_S];
    char pais[MAX_S];
};

typedef struct s_persona Persona;

void pedirString(char s[]);
Persona pedirPersona();
void guardarPersonas(Persona personas[]);

int main()
{
    int i = 0;
    Persona personas[N];
    personas[i].documento = 1;
    while (i == 0 || (i < N && personas[i - 1].documento != 0))
    {
        personas[i] = pedirPersona();
        ++i;
    }
    guardarPersonas(personas);
    return 0;
}

void guardarPersonas(Persona personas[])
{
    FILE *f = fopen(FNAME, "w");
    int i = 0;
    while (i < N && personas[i].documento != 0)
    {
        Persona p = personas[i];
        fprintf(f, "%d,%s,%s\n", p.documento, p.nombre, p.pais);
        ++i;
    }
    fclose(f);
}

Persona pedirPersona()
{
    Persona persona = {1, "", ""};
    printf("Ingrese documento: ");
    scanf("%d", &persona.documento);
    if (persona.documento != 0)
    {
        printf("Ingrese nombre: ");
        pedirString(persona.nombre);
        printf("Ingrese pais: ");
        pedirString(persona.pais);
    }
    return persona;
}

void pedirString(char s[])
{
    char LTERM = '\n';
    char STERM = '\0';
    fflush(stdin);
    char aux;
    int i = 0;
    while (aux != LTERM && i <= MAX_S)
    {
        aux = getchar();
        s[i] = aux;
        i++;
    }
    s[i - 1] = STERM;
}