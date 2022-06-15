#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    int valor;
    struct s_nodo *next;
};
typedef struct s_nodo Nodo;

void eliminar(Nodo **nodo, int valor)
{
    if (*nodo != NULL)
    {
        if ((*nodo)->valor == valor)
        {
            Nodo *direccion_liberar = *nodo;
            *nodo = (*nodo)->next;
            free(direccion_liberar);
        }
        else
        {
            eliminar(&((*nodo)->next), valor);
        }
    }
}

void eliminar_todos(Nodo **nodo, int valor)
{
    if (*nodo != NULL)
    {
        if ((*nodo)->valor == valor)
        {
            Nodo *direccion_liberar = *nodo;
            *nodo = (*nodo)->next;
            free(direccion_liberar);
            eliminar_todos(nodo, valor);
        }
        else{
            eliminar_todos(&((*nodo)->next), valor);

        }
    }
}

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
    eliminar_todos(&lista, 5);
    imprimirLista(lista);
    return 0;
}