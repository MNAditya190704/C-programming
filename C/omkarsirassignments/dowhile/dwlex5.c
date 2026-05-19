#include <stdio.h>
int main()
{
    int num = 1234, sum = 0;
    do
    {
        sum = sum + (num % 10);
        num = num / 10;
    } while (num != 0);
    printf("Sum = %d", sum);
    return 0;
}