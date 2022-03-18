#include <stdio.h>

int operacion(int a, int b, char op);

int main()
{
    int a, b;
    char op;
    printf("Ingrese primer numero: ");
    scanf("%d", &a);
    printf("Ingrese segundo numero: ");
    scanf("%d", &b);
    printf("Ingrese operacion[+ - * /]: ");
    fflush(stdin);
    op = getchar();

    printf("%d %c %d = %d", a, op, b, operacion(a, b, op));
    return 0;
}

int operacion(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        break;
    }
}