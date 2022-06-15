#include <stdio.h>
#include <stdlib.h>

typedef struct s_persona
{
    int dni;
    char *nombre;
    char *apellido;
} Persona;

struct s_nodo
{
    Persona valor;
    struct s_nodo *next;
};
typedef struct s_nodo Nodo;

void append(Nodo **nodo, Persona valor)
{
    if (*nodo == NULL)
    {
        *nodo = malloc(sizeof(Persona));
        (*nodo)->valor = valor;
        (*nodo)->next = NULL;
    }
    else
    {
        append(&((*nodo)->next), valor);
    }
}

void insertOrdenado(Nodo **nodo, Persona valor)
{
    if (*nodo == NULL || (*nodo)->valor.dni > valor.dni)
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
        printf("%d,", nodo->valor.dni);
        imprimirLista(nodo->next);
    }
}

int main()
{
    Nodo *lista = NULL;
    Persona p;
    p.dni = 43725441;
    insertOrdenado(&lista, p);
    p.dni = 33725441;
    insertOrdenado(&lista, p);
    p.dni = 13725441;
    insertOrdenado(&lista, p);
    p.dni = 53725441;
    insertOrdenado(&lista, p);
    p.dni = 83725441;
    insertOrdenado(&lista, p);
    p.dni = 23725441;
    insertOrdenado(&lista, p);


    imprimirLista(lista);

    return 0;
}