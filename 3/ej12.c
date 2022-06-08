#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct texto
{
    char *txt;
    unsigned int longitud;
} Texto;

typedef struct frases
{
    Texto *textos;
    unsigned int cantidad;
} Frases;

Frases crearFrases()
{
    Texto *textos = malloc(sizeof(Texto) * 1);
    textos->txt = NULL;
    Frases frases = {textos, 0};
    return frases;
}

Texto cargarTexto()
{
    Texto texto;
    texto.longitud = 0;
    texto.txt = malloc(1);
    fflush(stdin);
    char aux = 'c';
    while (aux != '\n')
    {
        aux = getchar();
        texto.longitud++;
        texto.txt = realloc(texto.txt, texto.longitud * sizeof(char));
        texto.txt[texto.longitud - 1] = aux;
    }
    texto.txt[texto.longitud - 1] = '\0';
    return texto;
}

void appendFrase(Frases *frases, Texto texto)
{
    frases->cantidad++;
    frases->textos = realloc(frases->textos, sizeof(Frases) * (frases->cantidad + 1)); // uno mas por el null del final
    frases->textos[frases->cantidad - 1] = texto;
}

void mostrarFrases(Frases frases)
{
    for (int i = 0; i < frases.cantidad; i++)
    {
        printf("%s\n", frases.textos[i].txt);
    }
}

void intercambiarValores(Texto *t1, Texto *t2)
{
    Texto taux = {NULL, 0};
    taux.longitud = t1->longitud;
    taux.txt = malloc(taux.longitud * sizeof(char));
    strcpy(taux.txt, t1->txt);

    *t1 = *t2;
    *t2 = taux;
}

void ordenarFrases(Frases *frases)
{
    for (int i = 0; i < frases->cantidad - 1; i++)
    {
        for (int j = i + 1; j < frases->cantidad; j++)
        {
            if (strcmp(frases->textos[i].txt, frases->textos[j].txt) >= 1)
            {
                intercambiarValores(&frases->textos[i], &frases->textos[j]);
            }
        }
    }
}

void guardarFrases(Frases frases)
{
    FILE *f = fopen("frases_con_longitud.csv", "w");
    for (int i = 0; i < frases.cantidad; i++)
    {
        // se guarda con uno de mas por el \0 al final
        fprintf(f, "%d,%s\n", frases.textos[i].longitud, frases.textos[i].txt);
    }
    fclose(f);
}

int main()
{
    Frases frases = crearFrases();
    Texto frase = {NULL, 4};
    while (frase.longitud > 1)
    {
        frase = cargarTexto();
        if (frase.longitud > 1)
        {
            appendFrase(&frases, frase);
        }
    }
    ordenarFrases(&frases);
    mostrarFrases(frases);
    guardarFrases(frases);
    printf("termine bien\n");
}
