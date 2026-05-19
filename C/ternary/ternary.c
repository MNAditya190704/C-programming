#include<stdio.h>
int main()
{
    int a, b, c, d;
    printf("give numbers");
   scanf("%d %d %d", &a, &b, &c);
   (a>b)?(a>c)? printf("%d is the largest", a):printf("%d is the largest", c):(b>c)? printf("%d is the largest", b): printf("%d is the largest number", c);
   printf("give a number");
   scanf("%d", &d);
   (d<0)?printf("%d",d*(-1)):printf("%d", d);
}