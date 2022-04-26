#include <stdio.h>
#include <math.h>

struct s_punto{
    int x;
    int y;
};
typedef struct s_punto Punto;

Punto pedirPunto();
float distanciaEntreDosPuntos(Punto punto1, Punto punto2);

int main()
{
    Punto origen = {0, 0};
    Punto punto1 = pedirPunto();
    Punto punto2 = pedirPunto();
    float distancia1 = distanciaEntreDosPuntos(punto1, origen);
    float distancia2 = distanciaEntreDosPuntos(punto2, origen);
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

float distanciaEntreDosPuntos(Punto punto1, Punto punto2)
{
    return sqrt(pow(punto1.x - punto2.x, 2) + pow(punto1.y - punto2.y, 2));
}

Punto pedirPunto(){
    Punto punto;
    printf("Ingrese coordenada x: ");
    scanf("%d", &punto.x);
    printf("Ingrese coordenada y: ");
    scanf("%d", &punto.y);
    return punto;
}