#include<stdio.h>
int main()
{
    int num, i, sum=0, mum;
    printf("give number to check for perfect number");
    scanf("%d", &num);
    mum=num;
    for(i=1; i<=num; i++)
    {
        if(num%i==0)
        {
            sum=sum+i;
        }
    }
    if(sum/2==mum)
    {
        printf("is a perfect number");
    }
    else
    {
        printf("not a perfect number");
    }
}