#include<stdio.h>
void factorial(int num)
{
    int i, fact=1;
     for(i=1; i<=num; i++)
     {
        fact=fact*i;
     }
      printf("factorial is %d", fact);
}
int main()
{
    int n;
    printf("give number whose factorial you want");
    scanf("%d", &n);
    factorial(n);
}