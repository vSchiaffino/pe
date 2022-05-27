#include <stdio.h>

typedef struct{ 
    int a;
    int b;
    int c; 
}
Tres;

void ordenarTres(Tres* tres)
{
    int* valores[3] = {&tres->a, &tres->b, &tres->c};
    for (int i = 0; i < 2; i++)
    {
        for (int j = i+1; j < 3; j++)
        {
            if(*valores[j] < *valores[i])
            {
                int aux = *valores[i];
                *valores[i] = *valores[j];
                *valores[j] = aux;
            }
        }
        
    }
    
}

int main()
{
    Tres t = {2, 1, 3};
    printf("%d %d %d\n", t.a, t.b, t.c);
    ordenarTres(&t);
    printf("%d %d %d\n", t.a, t.b, t.c);
    return 0;
}