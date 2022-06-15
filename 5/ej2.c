#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
    int valor;
    struct s_nodo* next;
} Nodo;

void insert(Nodo lista, int posicion, int valor)
{
    int i = 0;
    Nodo actual = lista;
    while(i < posicion && actual.next != NULL)
    {
        actual = *actual.next;
        i++;
    }
}

int main()
{
    return 0;
}