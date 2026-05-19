#include <stdio.h>
int main()
{
    int base = 2, exponent = 4;
    int result = 1;
    while (exponent > 0)
    {
        result = result * base;
        exponent--;
    }
    printf("Result = %d", result);
    return 0;
}