#include<stdio.h>
int main(void)
{
    int i, j, n, count=0;
    printf("give limit for list of prime numbers");
    scanf("%d", &j);
    printf("The list of prime numbers are: \n");
    for(i=2; i<=j; i++)
    {
        count=0;
        for(n=1; n<=i; n++)
        {
            if(i%n==0)
            {
                count++;
            }
        }
        if(count<=2)
        {
            printf("%d \n", i);
        }
    }
    return 0;
}