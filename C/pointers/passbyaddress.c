#include<stdio.h>
void math(int *add, int *sub, int a, int b)
{
    *add=a+b;
    *sub=a-b;
}
int main()
{
    int a=3, b=4;
    int add, sub;
    math (&add, &sub, a, b);
    printf("%d %d", add, sub );
}