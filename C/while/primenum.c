#include<stdio.h>
int main(void)
{
    int a, i=1, count=0;
    printf("give numbers");
    scanf("%d", &a);
    while(i<=a)
    {
        if(a%i==0)
        {
            count++;
        }
        i++;
    }
    if(count<=2 && a>=0)
    {
        printf("it is a prime number");
    }
    else if (count>2 && a>=0)
    {
        printf("not a prime number");
    }
    else
    {
        printf("prime rule doesnt apply");
    }
    return 0;
}