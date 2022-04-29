#include <stdio.h>

#define FNAME "personas.txt"
#define MAX_S 400

struct s_persona
{
    int documento;
    char nombre[MAX_S];
    char pais[MAX_S];
};

typedef struct s_persona Persona;

int main()
{
    FILE *f = fopen(FNAME, "r");
    for (int i = 0; i < 53; i++)
    {
        printf("-");
    }
    printf("\n%10s %20s %20s\n", "Documento", "Nombre", "Pais");
    for (int i = 0; i < 53; i++)
    {
        printf("-");
    }
    printf("\n");
    while (!feof(f))
    {
        Persona p;
        fscanf(f, "%d,", &p.documento);
        leerString(f, p.nombre, ',');
        leerString(f, p.pais, '\n');
        if (!feof(f))
            printf("%10d %20s %20s\n", p.documento, p.nombre, p.pais);
    }
    for (int i = 0; i < 53; i++)
    {
        printf("-");
    }
    fclose(f);
    return 0;
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