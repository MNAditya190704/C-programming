#include<stdio.h>
int main()
{
    int a;
    printf("give number");
   scanf("%d", &a);
   (a%10==0)?printf("%d is divisible by 10", a):printf("%d is not divisible by 10", a);
}