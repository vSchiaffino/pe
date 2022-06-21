#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int notas[5];
    char estado;
} Dato;

struct s_nodo
{
    Dato dato;
    struct s_nodo *next;
};
typedef struct s_nodo Nodo;

void append(Nodo **nodo, Dato dato)
{
    if (*nodo == NULL)
    {
        Nodo *aux = malloc(sizeof(Dato));
        aux->dato = dato;
        aux->next = NULL;
        *nodo = aux;
    }
    else
    {
        append(&((*nodo)->next), dato);
    }
}

Nodo *armarLista()
{
    FILE *f = fopen("promocionados.txt", "r");
    Nodo *lista = NULL;
    Dato dato;
    char str_aux[50];
    char aux = 'c';
    int i = 0;
    while (aux != EOF && !feof(f))
    {
        aux = fgetc(f);
        if (aux == ',')
        {
            str_aux[i] = '\0';
            strcpy(dato.nombre, str_aux);
            fscanf(f, "%d,%d,%d,%d\n", &dato.notas[0], &dato.notas[1], &dato.notas[2], &dato.notas[3]);
            dato.notas[4] = -1;

            append(&lista, dato);
            i = -1;
        }
        else if (aux != EOF)
        {
            str_aux[i] = aux;
        }
        ++i;
    }
    return lista;
}

void contarAprobados(Nodo **nodo)
{
    if (*nodo != NULL)
    {
        int promocionadas = 0;
        for (int i = 0; i < 4; i++)
        {
            if ((*nodo)->dato.notas[i] >= 7)
            {
                promocionadas++;
            }
        }
        if (promocionadas >= 3)
        {
            (*nodo)->dato.estado = 'A';
        }
        else
        {
            (*nodo)->dato.estado = 'D';
        }
        contarAprobados(&((*nodo)->next));
    }
}

void imprimirLista(Nodo *nodo)
{
    if (nodo != NULL)
    {
        printf("%-40s - %c - %5d %5d %5d %5d\n", nodo->dato.nombre, nodo->dato.estado, nodo->dato.notas[0], nodo->dato.notas[1], nodo->dato.notas[2], nodo->dato.notas[3]);
        imprimirLista(nodo->next);
    }
}

int main()
{
    Nodo *lista = armarLista();
    contarAprobados(&lista);
    imprimirLista(lista);

    printf("\nchau\n");
    return 0;
}