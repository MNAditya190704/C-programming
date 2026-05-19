#include<stdio.h>
void update (int *a, int *b)
{
    *a=*a+1;
    *b=*b+1;
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d %d \n", a, b);
    update(&a, &b);
    printf("%d %d \n", a, b);
}