#include<stdlib.h>
#include<stdio.h>

typedef struct s_localidad{
    int id_localidad;
    char* nombre_localidad;
    float promedio;
    float min;
    float max;
} Localidad;

typedef struct s_nodo{
    struct s_nodo* sig;
    Localidad valor;
}* Nodo;


typedef struct{
    char* arr;
    int len;
} String;

typedef struct s_altura{
    int id_localidad;
    float medida;
    unsigned int AMD;
} Altura;

void append_string(String* s, char c)
{
    if(s->arr == NULL)
    {
        s->len = 1;
        s->arr = malloc(sizeof(char)*2);
    }
    else{
        s->len++;
        s->arr = realloc(s->arr,sizeof(char)*(s->len+1));
    }
    s->arr[s->len-1] = c;
    s->arr[s->len] = '\0';
}

Altura* llenarAlturas()
{
    int i = 0;
    Altura* alturas = malloc(sizeof(Altura)*(i+1));
    FILE* f = fopen("alturas.txt", "r");
    while(!feof(f))
    {
        fscanf(f,"%d, %f, %u\n", &alturas[i].id_localidad, &alturas[i].medida, &alturas[i].AMD);

        ++i;
        alturas = realloc(alturas, sizeof(Altura) * (i+1));
    }
    alturas[i].id_localidad = 0;

    return alturas;
}

void insertarOrdenado(Nodo* lista, Localidad valor)
{
    if(*lista == NULL || (*lista)->valor.promedio < valor.promedio)
    {
        Nodo aux = malloc(sizeof(struct s_nodo));
        aux->valor = valor;
        aux->sig = *lista;
        *lista = aux;
    }
    else{
        insertarOrdenado(&((*lista)->sig), valor);
    }
}

Nodo maxCinco(int n, int anio)
{
    Altura* alturas = llenarAlturas();
    Nodo lista = NULL;

    FILE* f = fopen("localidades.txt", "r");


    Localidad valor_aux;
    String string_aux;
    char aux = 'c';
    string_aux.arr = NULL;
    while (!feof(f) || aux == EOF)
    {
        fscanf(f,"%d,", &valor_aux.id_localidad);
        char aux = 'c';
        if(!feof(f))
        {
            while(aux != '\n' && aux != EOF){
                aux = fgetc(f);
                if(aux != '\n')
                {
                    append_string(&string_aux, aux);
                }
            }
            valor_aux.nombre_localidad = string_aux.arr;
            string_aux.arr = NULL;
            // lleno las alturas para poder ponerlos ordenados, filtro por año y id localidad
            int matideburen = 0;
            int cantidad_medidas = 0;
            unsigned int mask = 16380; // es el binario 11111111111100
            valor_aux.promedio = 0;
            while (alturas[matideburen].id_localidad != 0)
            {
                if(
                    alturas[matideburen].id_localidad == valor_aux.id_localidad &&
                    ((alturas[matideburen].AMD & mask) >> 2) == anio
                )
                {
                    valor_aux.promedio += alturas[matideburen].medida;
                    cantidad_medidas++;
                }
                matideburen++;
            }
            if(cantidad_medidas != 0)
            {
                valor_aux.promedio = valor_aux.promedio / cantidad_medidas;
            }
            // los inserto ordenados
            insertarOrdenado(&lista, valor_aux);
        }
    }

    // corto la lista a los n valores pedidos
    int cantidad = 0;
    Nodo puntero = lista;
    while(puntero != NULL)
    {
        if(cantidad < n)
        {
            cantidad++;
            if(cantidad == n)
            {
                Nodo aux = puntero->sig;
                puntero->sig = NULL;
                puntero = aux;
            }
            else{
                puntero = puntero->sig;
            }
        }
        else{
            Nodo liberar = puntero;
            puntero = puntero->sig;
            free(liberar);
        }
    }
    
    return lista;
}

int main()
{
    Nodo lista = maxCinco(3, 2020);
    Nodo puntero = lista;
    while (puntero != NULL)
    {
        printf("%d,%s,%f\n", puntero->valor.id_localidad, puntero->valor.nombre_localidad, puntero->valor.promedio);
        puntero = puntero->sig;
    }
    

    printf("salgo");
    return 0;
}