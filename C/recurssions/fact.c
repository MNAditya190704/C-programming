#include<stdio.h>
int fact (int a);
int main()
{
    int m, n;
    printf("give number");
    scanf("%d", &m);
    n=fact(m);
    printf("%d", n);
}
int fact(int a)
{
    if(a==1)
    return a;
    else
    return a=a*fact(a-1);
}