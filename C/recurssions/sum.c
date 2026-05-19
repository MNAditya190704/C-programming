#include<stdio.h>
int sum (int a);
int main()
{
    int m, n;
    printf("give limit");
    scanf("%d", &m);
    n=sum(m);
    printf("%d", n);
}
int sum(int a)
{
    if(a==0)
    return a;
    else
    return a=a+sum(a-1);
}