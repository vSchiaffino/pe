#include <stdio.h>
#include <stdlib.h>

typedef struct s_lista
{
    int len;
    int *array;
} Lista;

void insert(Lista *lista, int posicion, int valor)
{
    if (lista->len == 0)
    {
        lista->array = malloc(sizeof(int) * 1);
    }
    else
    {
        lista->array = realloc(lista->array, sizeof(int) * (lista->len + 1));
    }
    int aux = valor;
    for (int i = posicion; i < lista->len + 1; i++)
    {
        int aux2 = lista->array[i];
        lista->array[i] = aux;
        aux = aux2;
    }

    lista->len++;
}

void insertarOrdenado(Lista *lista, int valor)
{
    int i = 0;
    while (i < lista->len && lista->array[i] < valor)
    {
        i++;
    }
    insert(lista, i, valor);
}

void mostrarLista(Lista lista)
{
    printf("[");
    for (int i = 0; i < lista.len; i++)
    {
        printf("%d", lista.array[i]);
        if (i != lista.len - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

int main()
{
    Lista lista;
    lista.len = 0;
    insertarOrdenado(&lista, 5);
    mostrarLista(lista);
    insertarOrdenado(&lista, 1);
    mostrarLista(lista);
    insertarOrdenado(&lista, 4);
    mostrarLista(lista);
    insertarOrdenado(&lista, 2);
    mostrarLista(lista);
    insertarOrdenado(&lista, 3);
    mostrarLista(lista);
    insertarOrdenado(&lista, -1);
    mostrarLista(lista);
    insertarOrdenado(&lista, 154);
    mostrarLista(lista);
    insertarOrdenado(&lista, 6);
    mostrarLista(lista);
    printf("salgo bien");
    return 0;
}