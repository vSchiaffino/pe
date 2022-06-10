#include <stdio.h>
#include <stdlib.h>

int cociente(int a, int b)
{
    if (a == 0)
    {
        return 0;
    }
    else
    {
        return 1 + cociente(a - b, b);
    }
}

int main()
{
    int a = 50;
    int b = 5;
    printf("%d / %d = %d", a, b, cociente(a, b));

    return 0;
}