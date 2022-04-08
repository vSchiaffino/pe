#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int esNumero(char c);
int esSigno(char c);
long int __atoi(char src[]);
long int int_pow(long int base, long int exp);

int main(){
    char s[] = "12345";
    printf("%s -> %d", s, __atoi(s));
    
}

int esNumero(char c){
    return c >= 48 && c <= 57;
}

int esSigno(char c){
    char SIGNO_MAS = 43;
    char SIGNO_MENOS = 45;
    return c == SIGNO_MAS || c == SIGNO_MENOS;
}

int convertirSignoANumero(char c){
    char SIGNO_MAS = 43;
    char SIGNO_MENOS = 45;
    if(c == SIGNO_MAS)
        return 1;
    if(c == SIGNO_MENOS)
        return -1;
    // error
    return 0;
}

int convertirCharANumero(char c){
    // printf("%c -> %d", c, (int)c-48);
    return c - 48;
}

int lenStr(char str[]){
    char STERM = '\0';
    int i = 0;
    while(str[i] != STERM){
        i++;
    }
    return i;
}

long int int_pow(long int base, long int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp % 2)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

long int __atoi(char src[]){
    int len = lenStr(src);
    char STERM = '\0';
    long int result = 0;
    int seEncontroSigno = 0;
    int i = 0;
    char aux = 'c';
    for (int pos = len-1; pos >= 0; pos--)
    {
        aux = src[pos];
        if(esNumero(aux)){
            // printf("[%d] ", i);
            long int multiplicadorDePosicion = int_pow(10, i);
            long int numero = convertirCharANumero(aux);
            result += (long int)(numero * multiplicadorDePosicion);
            // printf("(%d * %d = %d)\n", numero, multiplicadorDePosicion, numero*multiplicadorDePosicion);
        }
        else if(esSigno(aux) && !seEncontroSigno){
            // printf("-\n");
            result = result * convertirSignoANumero(aux);
            seEncontroSigno = 1;
        }
        else
        {
            // Error
            return 0;
        }

        i++;
    }
    
    return result;
}