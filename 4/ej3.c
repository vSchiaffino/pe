#include <stdio.h>
#include <stdlib.h>

int resto(int dividendo, int divisor)
{
    if (dividendo < divisor)
    {
        return dividendo;
    }
    else
    {
        return resto(dividendo - divisor, divisor);
    }
}

int main()
{
    int a = 151;
    int b = 3;
    printf("%d %% %d = %d", a, b, resto(a, b));

    return 0;
}