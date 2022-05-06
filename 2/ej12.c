#include <stdio.h>

char cambiarCase(char c)
{
    return c ^ 32;
}

int main()
{
    char c = 'D';
    printf("%c = %c", c, cambiarCase(c));
    return 0;
}