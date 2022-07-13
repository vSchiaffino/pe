#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct s_indice {
    int linea;
    int primero;
    int segundo;
} t_indice;

typedef struct s_nodo {
    struct s_nodo* sig;
    t_indice valor;
} *t_nodo;

typedef struct {
    char* arr;
    int len; 
} String;

t_indice buscarSub(char* str, char* sub)
{
    t_indice ret;
    ret.primero = -1;
    ret.segundo = -1;
    int lensub = strlen(sub);
    int i = 0;
    int empezo = -1;
    int racha = 0;
    while(str[i] != '\0' && (racha != lensub))
    {
        if(racha == 0 && str[i] == sub[0])
        {
            empezo = i;
            racha = 1;
        }
        else{
            if(str[i] == sub[racha])
            {
                racha++;
            }
            else{
                empezo = -1;
                racha = 0;
            }
        }
        i++;
    }
    if(racha == lensub)
    {
        ret.primero = empezo;
        ret.segundo = empezo + (lensub-1);
    }
    return ret;
}

void append(t_nodo* nodo,  t_indice valor){
    if(*nodo == NULL)
    {
        t_nodo aux = malloc(sizeof(struct s_nodo));
        aux->sig = NULL;
        aux->valor = valor;
        (*nodo) = aux;
    }
    else{
        append(&((*nodo)->sig), valor);
    }
}

void push_string(String* s, char a)
{
    if(s->arr == NULL)
    {
        s->arr = malloc(sizeof(char)*2);
        s->len = 1;
    }
    else{
        s->len++;
        s->arr = realloc(s->arr, sizeof(char) * s->len+1);
    }
    s->arr[s->len-1] = a;
    s->arr[s->len] = '\0';
}

void clear_string(String* s)
{
    s->arr = NULL;
}

t_nodo indices (char* sub)
{
    t_nodo lista = NULL;
    String string;
    string.arr = NULL;
    int i = 0;
    FILE* f = fopen("txt.txt", "r");
    char aux = '3';
    while(!feof(f))
    {
        aux = fgetc(f);
        if(aux == '\n')
        {
            t_indice v = buscarSub(string.arr, sub);
            if(v.primero != -1 && v.segundo != -1)
            {
                v.linea = i;
                append(&lista, v);
            }

            clear_string(&string);
            i++;
        }
        else if(aux != EOF){
            push_string(&string, aux);
        }
    }

    return lista;
}

int main()
{
    t_nodo lista = indices("da");
    while(lista != NULL)
    {
        printf("(%d,%d,%d)\n", lista->valor.linea, lista->valor.primero, lista->valor.segundo);
        lista = lista->sig;
    }

    printf("\nsalgo");
    return 0;
}