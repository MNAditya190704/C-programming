#include <stdio.h>
int main()
{
    int num = 5, fact = 1;
    while (num > 0)
    {
        fact = fact * num;
        num--;
    }
    printf("Factorial = %d", fact);
    return 0;
}