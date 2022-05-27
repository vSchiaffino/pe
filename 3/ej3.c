#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void redondear(double* numero)
{
    *numero = round(*numero);
}

int main()
{
    double n = 4.01;
    printf("%f = ", n);
    redondear(&n);
    printf("%f\n", n);
    return 0;
}