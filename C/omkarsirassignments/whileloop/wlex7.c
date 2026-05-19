#include <stdio.h>
int main()
{
    int num = 122334, digit = 3, count = 0, rem;
    while (num != 0)
    {
        rem = num % 10;
        if (rem == digit)
        {
            count++;
        }
        num = num / 10;
    }
    printf("Digit %d appears %d times", digit, count);
    return 0;
}