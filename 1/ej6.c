#include <stdio.h>
#define T 100
// Terminacion de linea, se usa para detectar
// cuando el getchar recibe un salto de linea
#define LTERM '\n'
// Terminacion de string, se usa para saber cuando
// un string llego a su fin
#define STERM '\0'
void imprimirText(char arr[]);
void cargarText(char arr[]);
void normalizar(char arr[]);
char toUpper(char lower);
int esMinuscula(char c);
int len(char arr[]);
void eliminarPosicion(char arr[], int pos);

int main()
{
    char arr[T + 1];
    arr[0] = STERM;
    printf("Ingrese texto: ");
    cargarText(arr);
    normalizar(arr);
    imprimirText(arr);
    return 0;
}

void cargarText(char arr[])
{
    fflush(stdin);
    char aux;
    int i = 0;
    while (aux != LTERM && i <= T)
    {
        aux = getchar();
        arr[i] = aux;
        i++;
    }
    arr[i - 1] = STERM;
}

void imprimirText(char arr[])
{
    printf("%s", arr);
}

void normalizar(char arr[])
{
    // letra mayus
    if (esMinuscula(arr[0]))
    {
        arr[0] = toUpper(arr[0]);
    }
    // punto
    int lenArr = len(arr);
    if (arr[lenArr - 1] != '.')
    {
        arr[lenArr] = '.';
        arr[lenArr + 1] = STERM;
        lenArr++;
    }
    // espacios
    int i = 0;
    while (i < (lenArr - 1))
    {
        if (arr[i] == ' ' && arr[i + 1] == ' ')
        {
            printf("elimino\n");
            eliminarPosicion(arr, i);
            lenArr--;
            i--;
        }
        i++;
    }
}

// devuelve 1 si el char es minuscula y 0 caso
// contrario
int esMinuscula(char c)
{
    if (c >= 97 && c <= 122)
    {
        return 1;
    }
    return 0;
}

// Convierte una letra de minuscula a mayuscula
char toUpper(char lower)
{
    return lower - 32;
}

int len(char arr[])
{
    int i = 0;
    while (arr[i] != STERM && i < T)
    {
        i++;
    }
    return i;
}

// Elimina un char en la posicion indicada
// y mueve todos los chars hacia la izquierda
// ej: recibe ("hola", 2) -> "hoa"
void eliminarPosicion(char arr[], int pos)
{
    int i = pos;
    char aux;
    while (aux != STERM)
    {
        aux = arr[i + 1];
        arr[i] = aux;
        i++;
    }
}