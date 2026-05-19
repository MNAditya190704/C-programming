#include<stdio.h>
int math(int a, int *b, int *c)
{
    *b= a*a;
    *c= a*a*a;
}
int main()
{
    int m, n, b, c;
    scanf("%d", &n);
    m=math(n, &b, &c);
    printf("%d %d", b, c);
}