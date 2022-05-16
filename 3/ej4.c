#include <stdio.h>
#define TAM 3

struct s_carta 
{ 
    int numero;
    int valor; 
    char palo; 
};
typedef struct s_carta Carta;

void ponerValor(Carta* c)
{
    if(c->numero == 1)
    {
        if(c->palo == 'e')
        {
            c->valor = 14;
        }
        else if(c->palo == 'b'){
            c->valor = 13;
        }
        else{
            c->valor = 7;
        }
    }
    else if(c->numero == 7)
    {
        if(c->palo == 'e')
        {
            c->valor = 12;
        }
        else if(c->palo == 'b')
        {
            c->valor = 11;
        }
        else{
            c->valor = 4;
        }
    }
    else if(c->numero == 3)
    {
        c->valor = 10;
    }
    else if(c->numero == 2)
    {
        c->valor = 9;
    }
    else if(c->numero >= 10 && c->numero <= 12)
    {
        c->valor = c->numero - 5;
    }
    else if(c->numero >= 7 && c->numero >= 4)
    {
        c->valor = c->numero - 3;
    }
}

void ordenar(Carta* carta1, Carta* carta2, Carta* carta3)
{
    Carta* cartas[TAM] = {carta1, carta2, carta3};
    for (int i = 0; i < TAM-1; i++)
    {
        for (int j = i+1; j < TAM; j++)
        {
            Carta c1 = *cartas[i];
            Carta c2 = *cartas[j];
            ponerValor(&c1);
            ponerValor(&c2);
            if(c1.valor < c2.valor)
            {
                Carta aux = *cartas[i];
                *cartas[i] = *cartas[j];
                *cartas[j] = aux;
            }
        }
        
    }
}

int main()
{
    // e: Espada, b: Basto, c: Copa, o: oro
    Carta c1 = {7, 0, 'e'};
    Carta c2 = {1, 0, 'e'};
    Carta c3 = {1, 0, 'b'};
    ordenar(&c1, &c2, &c3);
    printf("carta 1 -> %d %c\n",c1.numero, c1.palo);
    printf("carta 2 -> %d %c\n",c2.numero, c2.palo);
    printf("carta 3 -> %d %c\n",c3.numero, c3.palo);
    return 0;
}
