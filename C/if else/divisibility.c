#include <stdio.h>
int main (void)
{
    int a;
    printf("give a number");
    scanf("%d",&a);
    if (a%5==0)
    {
        printf("number is disible by 5 \n");
    }
    if (a%10==0)
    {
        printf("number is disible by 10");
    }
    return 0;
}