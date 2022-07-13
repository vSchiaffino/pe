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

void print_preoder(Nodo nodo)
{
    if(nodo != NULL)
    {
        printf("%d, ", nodo->valor);
        print_preoder(nodo->izq);
        print_preoder(nodo->der);
    }

}

void print_inorder(Nodo nodo)
{
    if(nodo != NULL)
    {
        print_inorder(nodo->izq);
        printf("%d, ", nodo->valor);
        print_inorder(nodo->der);
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

    return 0;
}