#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int dni;
    char nombre [100], apellido [100];
    double monto_adeudado;
    unsigned int dia, mes,anio;
}t_datos;

void pedir_string(char* string)
{
    fflush(stdin);
    int i = 0;
    char aux = '2';
    while(i < 99 && aux != '\n')
    {
        aux = getchar();
        string[i] = aux;
        ++i;
    }
    string[i-1] = '\0';
}

void carga()
{
    FILE* f = fopen("deudores1.dat", "ab");
    t_datos aux;
    aux.dni = 1;
    while(aux.dni != 0){
        printf("Dni: ");
        scanf("%d", &aux.dni);
        if(aux.dni!=0)
        {
            printf("Nombre: ");
            pedir_string(aux.nombre);
            printf("Apellido: ");
            pedir_string(aux.apellido);
            printf("Monto: ");
            scanf("%lf", &aux.monto_adeudado);
            printf("Dia: ");
            scanf("%d", &aux.dia);
            printf("Mes: ");
            scanf("%d", &aux.mes);
            printf("Año: ");
            scanf("%d", &aux.anio);
            fwrite(&aux, sizeof(t_datos), 1, f);
        }
    }
    fclose(f);
}

void mostrar()
{
    FILE* f = fopen("deudores1.dat", "rb");
    t_datos aux;
    while(!feof(f))
    {
        if(fread(&aux, sizeof(t_datos), 1, f) > 0)
        {
            printf("%5d %-15s %-15s %-5.2f %2d/%2d/%2d\n", aux.dni, aux.nombre, aux.apellido, aux.monto_adeudado, aux.dia, aux.mes, aux.anio);
        }
    }
}

int main()
{
    char s[100];
    // carga();
    // mostrar();
    return 0;
}