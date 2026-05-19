#include <stdio.h>
int main (void)
{
    int i,num, fact=0;
    printf("give number for perfect number");
    scanf("%d", &num);
    for(i=1; i<=num; i++)
    {
        if(num%i==0)
        {
            fact=fact+i;
        }
    }
    if((fact/2)==num)
    {
        printf("number is a perfect number");
    }
    else
    {
        printf("number is not a perfect number");
    }
}