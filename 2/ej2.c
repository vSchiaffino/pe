#include <stdio.h>
#include <math.h>
#define FNAME "puntos.csv"
#define CANTIDAD 10

struct s_punto{
    int x;
    int y;
};
typedef struct s_punto Punto;

float distanciaEntreDosPuntos(Punto punto1, Punto punto2);
void leerArchivo(Punto puntos[], char fname[]);
float minimaDistanciaConsecutiva(Punto puntos[]);
float minimaDistanciaEntrePuntos(Punto puntos[]);

int main()
{
    Punto puntos[CANTIDAD];
    leerArchivo(puntos, FNAME);
    float minDistanciaConsecutiva = minimaDistanciaConsecutiva(puntos);
    float minDistancia = minimaDistanciaEntrePuntos(puntos);
    printf("La minima distancia entre puntos consecutivos es: %.4f\n", minDistanciaConsecutiva);
    printf("La minima distancia entre dos puntos es: %.4f\n", minDistancia);
    return 0;
}

void leerArchivo(Punto puntos[], char fname[])
{
    FILE* f = fopen(fname, "r");
    int i = 0;
    for (int i = 0; i < CANTIDAD; ++i)
    {
        Punto p;
        fscanf(f, "%d,%d,", &p.x, &p.y);
        puntos[i] = p;
    }
}

float distanciaEntreDosPuntos(Punto punto1, Punto punto2)
{
    return sqrt(pow(punto1.x - punto2.x, 2) + pow(punto1.y - punto2.y, 2));
}

float minimaDistanciaConsecutiva(Punto puntos[])
{
    float min_distancia;
    for (int i = 0; i < CANTIDAD-1; i++)
    {
        Punto punto = puntos[i];
        Punto punto_siguiente = puntos[i + 1];
        float distancia = distanciaEntreDosPuntos(punto, punto_siguiente);
        if(i == 0 || distancia < min_distancia)
        {
            min_distancia = distancia;
        }
    }
    return min_distancia;
}

float minimaDistanciaEntrePuntos(Punto puntos[])
{
    float min_distancia;
    for (int i = 0; i < CANTIDAD-1; i++)
    {
        for (int j = i + 1; j < CANTIDAD; j++)
        {
            Punto punto1 = puntos[i];
            Punto punto2 = puntos[j];
            float distancia = distanciaEntreDosPuntos(punto1, punto2);
            if(i == 0 || distancia < min_distancia)
            {
                min_distancia = distancia;
            }
        }
    }
    return min_distancia;
}