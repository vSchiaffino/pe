#include<stdio.h>
#include<stdlib.h>

typedef struct s_vendedor{
    int codigo;
    char nombre[100];
    int objetivo;
    float sueldo;
} Vendedor;

typedef struct s_venta{
    int codigo;
    const char mes[15];
    int cantidadTarjetas;
} Venta;

typedef struct sNodoBin{
    struct sNodoBin* izq;
    struct sNodoBin* der;
    Vendedor vendedor;
} *tNodoBin;

void insertarOrdenado(tNodoBin* arbol, Vendedor vendedor)
{
    if(*arbol == NULL)
    {
        tNodoBin aux = malloc(sizeof(struct sNodoBin));
        aux->der = NULL;
        aux->izq = NULL;
        aux->vendedor = vendedor;
        *arbol = aux;
    }
    else{
        if(vendedor.codigo > (*arbol)->vendedor.codigo)
        {
            insertarOrdenado(&((*arbol)->der), vendedor);
        }
        else{
            insertarOrdenado(&((*arbol)->izq), vendedor);
        }
    }
}

int cargarArbolVendedores(tNodoBin* arbol, FILE* fVende)
{
    Vendedor vendedor;
    fscanf(fVende, "%d,", &vendedor.codigo);
    if(!feof(fVende))
    {
        char aux = 'c';
        int i = 0;
        while(aux!=',')
        {
            aux = fgetc(fVende);
            vendedor.nombre[i] = aux;
            i++;
        }
        vendedor.nombre[i-1] = '\0';
        fscanf(fVende,"%d,%f\n",&vendedor.objetivo,&vendedor.sueldo);
        insertarOrdenado(arbol, vendedor);
        cargarArbolVendedores(arbol, fVende);
    }
}

void printArbolPreoder(tNodoBin arbol)
{
    if(arbol != NULL)
    {
        printArbolPreoder(arbol->izq);
        printf("%d, ", arbol->vendedor.codigo);
        printArbolPreoder(arbol->der);
    }
}

Vendedor buscarVendedor(tNodoBin arbol,int idVen)
{
    if(arbol == NULL)
    {
        Vendedor v;
        v.codigo = -1;
        return v;
    }
    else if(arbol->vendedor.codigo == idVen){
        return arbol->vendedor;
    }
    else{
        if(idVen > arbol->vendedor.codigo)
        {
            return buscarVendedor((*arbol).der, idVen);
        }
        else{
            return buscarVendedor((*arbol).izq, idVen);
        }
    }
}

int liquidar(tNodoBin arbol,int idVen)
{
    Vendedor v = buscarVendedor(arbol, idVen);
    Venta venta;
    int cantidad = 0;
    FILE* f = fopen("ventasTarjetas.dat", "rb");
    while(!feof(f))
    {
        printf("hola");
        fread(&venta,sizeof(Venta), 1, f);
        if(venta.codigo == idVen)
        {
            cantidad += venta.cantidadTarjetas;
        }
    }
    printf("\nEl vendedor: %s (codigo %d), vendio %d tarjetas y su objetivo era %d" ,v.nombre, v.codigo, cantidad, v.objetivo);
}

int main()
{
    FILE* f = fopen("vendedores.txt", "r");
    tNodoBin arbol = NULL;
    cargarArbolVendedores(&arbol, f);
    printArbolPreoder(arbol);
    liquidar(arbol, 9);
    printf("\nsalgo bien");
    return 0;
}