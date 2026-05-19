#include<stdio.h>
int power(int n, int p)
{
    if(p==0)
    {
        return 1;
    }
    else
    {
        return n=n*power(n, p-1);
    }
}
int main()
{
    int a,c, d;
    scanf("%d %d", &a, &d);
    c=power(a, d);
    printf("%d", c);
}