#include <stdio.h>
int main()
{
    int num = 7865, count = 0;
    while (num != 0)
    {
        count++;
        num = num / 10;
    }
    printf("Digits = %d", count);
    return 0;
}