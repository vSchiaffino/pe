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

void imprimirLista(Nodo *nodo)
{
    if (nodo != NULL)
    {
        printf("%d,", nodo->valor);
        imprimirLista(nodo->next);
    }
}

void eliminar_posicion(Nodo **nodo, int posicion)
{
    if (*nodo != NULL)
    {
        if (posicion == 0)
        {
            Nodo *aux = *nodo;
            *nodo = (*nodo)->next;
            free(aux);
        }
        else
        {
            eliminar_posicion(&(*nodo)->next, posicion - 1);
        }
    }
}

int main()
{
    Nodo *lista = NULL;
    append(&lista, 5);
    append(&lista, 1);
    append(&lista, 4);
    append(&lista, 2);
    append(&lista, 5);
    append(&lista, 6);
    append(&lista, 5);
    append(&lista, 5);
    imprimirLista(lista);
    printf("\n");
    eliminar_posicion(&lista, 2);
    imprimirLista(lista);
    return 0;
}