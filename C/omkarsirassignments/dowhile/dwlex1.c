#include <stdio.h>
int main()
{
    int N, i = 1;
    printf("Enter N: ");
    scanf("%d", &N);
    if (N < 1)
    {
        printf("N must be greater than or equal to 1.");
    }
    else
    {
        do
        {
            printf("%d", i);
            i++;
        } 
        while (i <= N);
    }
    return 0;
}