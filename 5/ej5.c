#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    int valor;
    struct s_nodo *anterior;
};
typedef struct s_nodo Nodo;

void push(Nodo **pila, int valor)
{
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->anterior = *pila;
    nuevoNodo->valor = valor;
    *pila = nuevoNodo;
}

int pop(Nodo **pila)
{
    int ret = (*pila)->valor;
    Nodo *aux = *pila;
    *pila = (*pila)->anterior;
    free(aux);
    return ret;
}

void mostrarPila(Nodo *pila)
{
    if (pila != NULL)
    {
        printf("- %d - \n", (*pila).valor);
        mostrarPila((*pila).anterior);
    }
}

int main()
{
    Nodo *pila = NULL;
    push(&pila, 5);
    push(&pila, 3);
    push(&pila, 2);
    printf("hola\n");
    mostrarPila(pila);
    printf("saco %d\n", pop(&pila));
    mostrarPila(pila);
    printf("saco %d\n", pop(&pila));
    mostrarPila(pila);
    printf("saco %d\n", pop(&pila));
    mostrarPila(pila);

    return 0;
}