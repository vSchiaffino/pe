#include <stdio.h>
#include <stdlib.h>

typedef struct s_persona
{
    int dni;
    char *nombre;
    char *apellido;
} Persona;

typedef struct s_lista
{
    int len;
    Persona *array;
} Lista;

void insert(Lista *lista, int posicion, Persona persona)
{
    if (lista->len == 0)
    {
        lista->array = malloc(sizeof(Persona) * 1);
    }
    else
    {
        lista->array = realloc(lista->array, sizeof(Persona) * (lista->len + 1));
    }
    Persona aux = persona;
    for (int i = posicion; i < lista->len + 1; i++)
    {
        Persona aux2 = lista->array[i];
        lista->array[i] = aux;
        aux = aux2;
    }

    lista->len++;
}

void insertarOrdenado(Lista *lista, Persona persona)
{
    int i = 0;
    while (i < lista->len && lista->array[i].dni < persona.dni)
    {
        i++;
    }
    insert(lista, i, persona);
}

void mostrarLista(Lista lista)
{
    for (int i = 0; i < lista.len; i++)
    {
        Persona p = lista.array[i];
        printf("%s,%s,%d\n", p.nombre, p.apellido, p.dni);
    }
}

int main()
{
    Lista lista;
    lista.len = 0;
    Persona pers[4];
    pers[0].nombre = "Valentin";
    pers[0].apellido = "SChiaffino";
    pers[0].dni = 43725441;
    pers[1].nombre = "Maximo";
    pers[1].apellido = "Cosetti";
    pers[1].dni = 55887789;
    pers[2].nombre = "Olga";
    pers[2].apellido = "Puchettini";
    pers[2].dni = 2255665;
    pers[3].nombre = "Cristina";
    pers[3].apellido = "Aguilera";
    pers[3].dni = 225544478;
    insertarOrdenado(&lista, pers[0]);
    insertarOrdenado(&lista, pers[1]);
    insertarOrdenado(&lista, pers[2]);
    insertarOrdenado(&lista, pers[3]);
    mostrarLista(lista);
    printf("salgo bien");
    return 0;
}