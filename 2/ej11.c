#include <stdio.h>

unsigned int armarInt(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4)
{
    unsigned int ret = c1;
    ret = ret << 8;
    ret = ret | c2;
    ret = ret << 8;
    ret = ret | c3;
    ret = ret << 8;
    ret = ret | c4;
    return ret;
}

int main()
{
    printf("int: %u", armarInt(128, 128, 128, 42));
    return 0;
}
