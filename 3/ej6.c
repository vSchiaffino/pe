#include <stdio.h>
#include <string.h>

typedef struct 
{ 
    int n;
    int o;
    int p; 
    char p1[26];
    char p2[50]; 
    double a;
    double b;
    double c; 
} 
Varios;

void intercambiarValores(Varios* varios)
{
    int aux = varios->n;
    varios->n = varios->p;
    varios->p = aux;
}

int main()
{
    Varios varios = {1, 2, 3, "hola como estas", "todo bien, vos?", 1.0, 2.0, 3.0};
    printf("%d\n", sizeof(Varios));
    printf("%d %d\n", varios.n, varios.p);
    intercambiarValores(&varios);
    printf("%d %d\n", varios.n, varios.p);
    return 0;
}