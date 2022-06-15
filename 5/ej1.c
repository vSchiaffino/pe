#include <stdio.h>
#include <stdlib.h>

typedef struct s_persona
{
    int dni;
    char *nombre;
    char *apellido;
} Persona;

typedef struct s_nodo
{
    Persona valor;
    struct s_nodo* next;
} Nodo;

typedef struct s_nodo_int
{
    int valor;
    struct s_nodo_int* next;
} Nodo_int;

void imprimirListaInverso(Nodo_int nodo)
{
    if(nodo.next != NULL){
        imprimirListaInverso(*nodo.next);
    }
    printf("%d,", nodo.valor);
}

void imprimirListaStructInverso(Nodo nodo)
{
    if(nodo.next != NULL){
        imprimirListaStructInverso(*nodo.next);
    }
    printf("%s,%s,%d\n", nodo.valor.nombre, nodo.valor.apellido, nodo.valor.dni);
}

int main()
{
    Nodo_int cuarto;
    cuarto.valor = 23;
    cuarto.next = NULL;
    Nodo_int tercero;
    tercero.valor = 20;
    tercero.next = &cuarto;
    Nodo_int segundo;
    segundo.valor = 17;
    segundo.next = &tercero;
    Nodo_int primero;
    primero.valor = 14;
    primero.next = &segundo;
    imprimirListaInverso(primero);
    printf("\n\n");

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

    Nodo n_cuarto;
    n_cuarto.valor = pers[3];
    n_cuarto.next = NULL;
    Nodo n_tercero;
    n_tercero.valor = pers[2];
    n_tercero.next = &n_cuarto;
    Nodo n_segundo;
    n_segundo.valor = pers[1];
    n_segundo.next = &n_tercero;
    Nodo n_primero;
    n_primero.valor = pers[0];
    n_primero.next = &n_segundo;
    imprimirListaStructInverso(n_primero);

    return 0;
}