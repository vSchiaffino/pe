#include <stdio.h>
#include <math.h>

struct s_punto{
    int x;
    int y;
};
typedef struct s_punto Punto;

Punto pedirPunto();
float distanciaAlOrigen(Punto punto);

int main()
{
    Punto punto1 = pedirPunto();
    Punto punto2 = pedirPunto();
    float distancia1 = distanciaAlOrigen(punto1);
    float distancia2 = distanciaAlOrigen(punto2);
    if(distancia1 > distancia2)
    {
        printf("El primer punto esta mas lejos del origen\n");
    }
    else
    {
        printf("El segundo punto esta mas lejos del origen\n");
    }
    return 0;
}

float distanciaAlOrigen(Punto punto)
{
    return sqrtf(pow(punto.x, 2) + pow(punto.y, 2));
}

Punto pedirPunto(){
    Punto punto;
    printf("Ingrese coordenada x: ");
    scanf("%d", &punto.x);
    printf("Ingrese coordenada y: ");
    scanf("%d", &punto.y);
    return punto;
}