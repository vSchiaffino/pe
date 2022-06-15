#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    int valor;
    struct s_nodo *next;
};
typedef struct s_nodo Nodo;

void append(Nodo **nodo, int valor)
{
    if (*nodo == NULL)
    {
        *nodo = malloc(sizeof(Nodo));
        (*nodo)->valor = valor;
        (*nodo)->next = NULL;
    }
    else
    {
        append(&((*nodo)->next), valor);
    }
}

void insertOrdenado(Nodo **nodo, int valor)
{
    if (*nodo == NULL || (*nodo)->valor > valor)
    {
        Nodo *nuevoNodo = malloc(sizeof(Nodo));
        nuevoNodo->next = *nodo;
        nuevoNodo->valor = valor;
        *nodo = nuevoNodo;
    }
    else
    {
        insertOrdenado(&(*nodo)->next, valor);
    }
}

void imprimirLista(Nodo *nodo)
{
    if (nodo != NULL)
    {
        printf("%d,", nodo->valor);
        imprimirLista(nodo->next);
    }
}

int main()
{
    Nodo *lista = NULL;

    insertOrdenado(&lista, 11);
    insertOrdenado(&lista, 7);
    insertOrdenado(&lista, 9);
    insertOrdenado(&lista, 4);
    insertOrdenado(&lista, 2);
    insertOrdenado(&lista, 1);

    imprimirLista(lista);

    return 0;
}