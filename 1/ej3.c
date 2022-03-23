#include <stdio.h>
#define LEN 100
#define TERM '\n'
void reemplazar(char arr[LEN], char find, char rep);
void leer(char msj[], char arr[]);

int main()
{
    char find, rep, arr[LEN];
    fflush(stdin);
    leer("Ingrese texto: ", arr);
    printf("Ingrese caracter a reemplazar: ");
    fflush(stdin);
    find = getchar();
    printf("Ingrese caracter de reemplazo: ");
    fflush(stdin);
    rep = getchar();
    reemplazar(arr, find, rep);
    printf("Resultado: %s", arr);
    return 0;
}

void reemplazar(char arr[LEN], char find, char rep)
{
    for (int i = 0; i < LEN; i++)
    {
        if (arr[i] == '\0')
        {
            // llego al final del string
            break;
        }
        if (arr[i] == find)
        {
            arr[i] = rep;
        }
    }
}

void leer(char msj[], char arr[LEN])
{
    printf("%s", msj);
    int i = 0;
    char aux;
    while (aux != TERM && i < LEN - 1)
    {
        aux = getchar();

        arr[i] = aux;
        i++;
    }
    arr[i - 1] = '\0';
}