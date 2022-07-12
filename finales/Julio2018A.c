#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int primero;
    int segundo;
} t_indice;

t_indice buscarSub(char* str, char* sub)
{
    t_indice ret;
    ret.primero = -1;
    ret.segundo = -1;
    int lensub = strlen(sub);
    int i = 0;
    int empezo = -1;
    int racha = 0;
    while(str[i] != '\0' && (racha != lensub))
    {
        if(racha == 0 && str[i] == sub[0])
        {
            empezo = i;
            racha = 1;
        }
        else{
            if(str[i] == sub[racha])
            {
                racha++;
            }
            else{
                empezo = -1;
                racha = 0;
            }
        }
        i++;
    }
    if(racha == lensub)
    {
        ret.primero = empezo;
        ret.segundo = empezo + (lensub-1);
    }
    return ret;
}

int main()
{
    t_indice ret = buscarSub("La verdad absoluta no existe, y esto es absolutamente cierto.", "r");
    printf("ret: (%d,%d)\n",ret.primero, ret.segundo);
    t_indice ret1 = buscarSub("La verdad absoluta no existe, y esto es absolutamente cierto.", "d ab");
    printf("ret: (%d,%d)\n",ret1.primero, ret1.segundo);
    t_indice ret2 = buscarSub("La verdad absoluta no existe, y esto es absolutamente cierto.", "zz");
    printf("ret: (%d,%d)\n",ret2.primero, ret2.segundo);
}