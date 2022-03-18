#include <stdio.h>

int redondeo(float n);
int piso(float n);
int techo(float n);

int main()
{
    float n;
    printf("Ingrese un numero real: ");
    scanf("%f", &n);

    printf("Redondeo = %d", redondeo(n));
    printf("\nPiso = %d", piso(n));
    printf("\nTecho = %d", techo(n));

    return 0;
}

int redondeo(float n)
{
    int in = n;
    float decimal = n - in;
    if (decimal >= .5)
    {
        n++;
    }
    return n;
}

int piso(float n)
{
    int in = n;
    return in;
}

int techo(float n)
{
    int in = n;
    float decimal = n - in;
    if (decimal != 0)
    {
        n++;
    }
    return n;
}