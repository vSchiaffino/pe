#include <stdio.h>
#include <stdlib.h>

int producto(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    else
    {
        return a + producto(a, b - 1);
    }
}

int main()
{
    int a = 10;
    int b = 4;
    printf("%d * %d = %d", a, b, producto(a, b));

    return 0;
}