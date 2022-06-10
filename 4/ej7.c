#include <stdio.h>
#include <stdlib.h>

int esVocal(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

unsigned int contar_vocales(char *str)
{
    char letra = str[0];
    if (letra == '\0')
    {
        return 0;
    }
    else
    {
        return esVocal(letra) + contar_vocales(str + 1);
    }
}

int main()
{
    char *str = "aeioujjjjjjjjhhhhhii";
    printf("%d", contar_vocales(str));

    return 0;
}