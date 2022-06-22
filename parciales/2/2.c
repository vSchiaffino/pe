#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_string
{
    int len;
    char *arr;
} String;

typedef struct s_persona
{
    char *nombre;
    int edad;
} Persona;

struct s_nodo
{
    Persona persona;
    struct s_nodo *sig;
};

typedef struct s_nodo Nodo;

void append_string(String *s, char c)
{
    if (s->arr == NULL)
    {
        s->arr = malloc(sizeof(char) * 2);
        s->len = 1;
        s->arr[0] = c;
        s->arr[1] = '\0';
    }
    else
    {
        s->len++;
        s->arr = realloc(s->arr, sizeof(char) * (s->len + 1));
        s->arr[s->len - 1] = c;
        s->arr[s->len] = '\0';
    }
}

void clear_string(String *s)
{
    free(s->arr);
    s->arr = NULL;
}

void push(Nodo **pila, Persona p)
{
    Nodo *aux = malloc(sizeof(Nodo));
    aux->persona = p;
    aux->sig = *pila;
    *pila = aux;
}

Persona pop(Nodo **pila)
{
    Nodo *popeado = *pila;
    *pila = (*pila)->sig;
    Persona ret = popeado->persona;
    free(popeado);
    return ret;
}

void insert_ordenado(Nodo **nodo, Persona p)
{
    if ((*nodo) == NULL || (*nodo)->persona.edad > p.edad)
    {
        Nodo *aux = malloc(sizeof(Nodo));
        aux->sig = *nodo;
        aux->persona = p;
        *nodo = aux;
    }
    else
    {
        insert_ordenado(&((*nodo)->sig), p);
    }
}

Nodo *armarPila()
{
    Nodo *pila = NULL;
    FILE *f = fopen("personas.txt", "r");
    String s;
    s.arr = NULL;
    if (f == NULL)
    {
        printf("Error abriendo archivo\n");
        return NULL;
    }
    char aux = 'c';
    while (aux != EOF && !feof(f))
    {
        aux = fgetc(f);
        if (aux == ',')
        {
            int edad;
            fscanf(f, "%d\n", &edad);
            Persona p;
            p.edad = edad;
            p.nombre = malloc(sizeof(char) * (s.len + 1));
            strcpy(p.nombre, s.arr);
            clear_string(&s);

            push(&pila, p);
        }
        else
        {
            append_string(&s, aux);
        }
    }

    return pila;
}

Nodo *desapilar(Nodo **pila)
{
    Nodo *lista = NULL;
    while (*pila != NULL)
    {
        Persona p = pop(pila);
        insert_ordenado(&lista, p);
    }
    return lista;
}

void imprimirLista(Nodo *nodo)
{
    if (nodo != NULL)
    {
        printf("%-30s %d\n", nodo->persona.nombre, nodo->persona.edad);
        imprimirLista(nodo->sig);
    }
}

int main()
{
    Nodo *pila = armarPila();
    Nodo *lista = desapilar(&pila);
    printf("%-30s %s\n", "Nombre", "Edad");
    imprimirLista(lista);
    return 0;
}