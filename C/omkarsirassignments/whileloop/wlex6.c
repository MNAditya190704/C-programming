#include <stdio.h>
int main()
{
    int num = 12, i = 1;
    printf("Factors: ");
    while (i <= num)
    {
        if (num % i == 0)
        {
            printf("%d ", i);
        }
        i++;
    }
    return 0;
}