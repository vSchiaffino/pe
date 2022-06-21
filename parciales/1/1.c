#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char* arr;
    int len;
} String;

typedef struct {
    String texto;
    char caracter;
    int cantidad_caracter;
} Refran;

struct s_nodo{
    Refran refran;
    struct s_nodo* sig;
};

typedef struct s_nodo Nodo;

void append(String* s, char c)
{
    if(s->arr == NULL)
    {
        s->len = 1;
        s->arr = malloc(sizeof(char) * 2);
        s->arr[0] = c;
        s->arr[1] = '\0';
    }
    else{
        s->len++;
        s->arr = realloc(s->arr, (s->len + 1) * sizeof(char));
        s->arr[s->len - 1] = c;
        s->arr[s->len] = '\0';
    }
}

void push(Nodo** pila, Refran refran)
{
    Nodo* aux = malloc(sizeof(Nodo));
    aux->refran = refran;
    aux->sig = *pila;
    *pila = aux;
}

Nodo pop(Nodo** pila)
{
    Nodo aux = **pila;
    free(*pila);
    *pila = (*pila)->sig;

    return aux;
}

Nodo* crearPila()
{
    FILE* f = fopen("refranes.txt", "r");
    Nodo* pila = NULL;
    while(!feof(f))
    {
        char aux = 'c';
        Refran r;
        String s;
        s.arr = NULL;
        while( aux != ',' && aux != EOF)
        {
            aux = fgetc(f);
            append(&s, aux);
        }
        if(aux != EOF)
        {
            s.arr[s.len-1] = '\0';
            s.len--;
            r.texto = s;
            fscanf(f, "%c\n", &aux);
            r.caracter = aux;
            push(&pila, r);
        }
    }
    return pila;
}

void append_lista(Nodo** lista, Refran r)
{
    if(*lista == NULL)
    {
        Nodo* aux = malloc(sizeof(Nodo));
        aux->refran = r;
        aux->sig = NULL;
        *lista = aux;
    }
    else{
        append_lista(&((*lista)->sig), r);
    }
}

Nodo* desapilar(Nodo* nodo)
{
    Nodo* lista = NULL;
    while (nodo != NULL)
    {
        Nodo n = pop(&nodo);
        append_lista(&lista, n.refran);
    }

    return lista;
}

void imprimirLista(Nodo* lista)
{
    if(lista != NULL)
    {
        printf("%-50s %-10c %10d\n", lista->refran.texto.arr, lista->refran.caracter, lista->refran.cantidad_caracter);
        imprimirLista(lista->sig);
    }

}

int contarCaracteres(Refran refran)
{
    if(refran.texto.len > 0)
    {
        int es = 0;
        if(refran.texto.arr[refran.texto.len-1] == refran.caracter)
        {
            es = 1;
        }
        refran.texto.len -= 1;
        return es + contarCaracteres(refran);
    }
    else{
        return 0;
    }
}

void contarCaracteresLista(Nodo** nodo)
{
    if(*nodo != NULL)
    {
        (*nodo)->refran.cantidad_caracter = contarCaracteres((*nodo)->refran);
        contarCaracteresLista(&((*nodo)->sig));
    }
}

int main()
{
    Nodo* pila = crearPila();
    Nodo* lista = desapilar(pila);
    contarCaracteresLista(&lista);
    printf("%-50s %-10s %10s\n\n", "Refran", "Caracter", "Cantidad");
    imprimirLista(lista);
    return 0;
}