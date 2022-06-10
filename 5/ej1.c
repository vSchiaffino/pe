#include <stdio.h>
#include <stdlib.h>

typedef struct s_persona
{
    int dni;
    char *nombre;
    char *apellido;
} Persona;

void imprimirArrayInverso(int *arr, int l)
{
    printf("%d,", arr[l - 1]);
    if (l != 1)
    {
        imprimirArrayInverso(arr, l - 1);
    }
    else
    {
        printf("\n");
    }
}

void imprimirStructInverso(Persona *arr, int l)
{
    printf("%s,%s,%d\n", arr[l - 1].nombre, arr[l - 1].apellido, arr[l - 1].dni);
    if (l != 1)
    {
        imprimirStructInverso(arr, l - 1);
    }
}

int main()
{
    int l = 4;
    int array[4];
    array[0] = 14;
    array[1] = 17;
    array[2] = 20;
    array[3] = 23;
    imprimirArrayInverso(array, l);
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
    imprimirStructInverso(pers, l);
}