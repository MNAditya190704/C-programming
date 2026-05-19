#include <stdio.h>
int main()
{
    int num = 2467, sum = 0, rem;
    while (num != 0)
    {
        rem = num % 10;
        if (rem % 2 == 0)
        {
            sum = sum + rem;
        }
        num = num / 10;
    }
    printf("Sum of even digits = %d", sum);
    return 0;
}