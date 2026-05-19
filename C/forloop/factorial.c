#include <stdio.h>
int main (void)
{
    int i,num, fact=1;
    printf("give number whose factorial you want");
    scanf("%d", &num);
     for(i=1; i<=num; i++)
     {
        fact=fact*i;
     }
      printf("factorial is %d", fact);
    return 0;
}