#include<stdio.h>
int prime(int a, int n)
{
    if(a==n)
    {
        return 1;
    }
    if(n%a==0)
    {
        return 0;
    }
    return prime(a+1, n);
}
int main()
{
    int m;
    scanf("%d", &m);
    int r=prime(2, m);
    if(r==0)
    {
        printf("not a prime");
    }
    else
    {
        printf("prime");
    }
}