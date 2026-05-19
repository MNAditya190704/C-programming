#include<stdio.h>
void prime(int a)
{
    int i,count=0; 
    for( i=1; i<=a; i++)
    {
        if(a%i==0)
        {
            count++;
        }
    }
    if(count==2)
    {
        printf("prime");
    }
    else
    {
        printf("not prime");
    }
}    
int main()
{
int n;
    printf("give number");
scanf("%d", &n);
prime(n);
}