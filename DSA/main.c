#include<stdio.h>
int add(int a, int b);
int sub(int c, int d);
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", add(a, b));
    printf("%d", sub(a, b));
    return 0;
}