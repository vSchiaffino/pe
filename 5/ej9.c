#include<stdio.h>
#include<stdlib.h>

typedef struct s_nodo{
    struct s_nodo* izq;
    struct s_nodo* der;
    int valor;
}* Nodo;

void insertar(Nodo* nodo, int valor)
{
    if (*nodo == NULL)
    {
        Nodo aux = malloc(sizeof(struct s_nodo));
        aux->der = NULL;
        aux->izq = NULL;
        aux->valor = valor;
        *nodo = aux;
    }
    else{
        if(valor > (*nodo)->valor)
        {
            insertar(&((*nodo)->der), valor);
        }
        else{
            insertar(&((*nodo)->izq), valor);
        }
    }
}

void print_postorder(Nodo nodo)
{
    if(nodo != NULL)
    {
        print_postorder(nodo->izq);
        print_postorder(nodo->der);
        printf("%d, ", nodo->valor);
    }
}

void liberar(Nodo nodo)
{
    if(nodo != NULL)
    {
        liberar(nodo->izq);
        liberar(nodo->der);
        free(nodo);
    }
}

int eliminar(Nodo* nodo, int valor)
{
    if(*nodo != NULL)
    {
        if((*nodo)->valor == valor)
        {

            liberar(*nodo);
            *nodo = NULL;
            return 1;
        }
        else if(eliminar(&(*nodo)->izq, valor))
        {
            return 1;
        }
        else if (eliminar(&(*nodo)->der, valor))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    Nodo nodo = NULL;
    insertar(&nodo, 15);
    insertar(&nodo, 4);
    insertar(&nodo, 8);
    insertar(&nodo, 25);
    insertar(&nodo, 13);
    insertar(&nodo, 155);
    insertar(&nodo, 3);
    insertar(&nodo, 22);
    insertar(&nodo, 554);
    insertar(&nodo, 7);
    insertar(&nodo, 57);

    print_postorder(nodo);
    printf("\n");
    eliminar(&nodo, 8);
    print_postorder(nodo);

    return 0;
}