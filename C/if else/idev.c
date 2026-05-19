#include <stdio.h>
int main (void)
{
    int a, b;
    printf("give a number");
    scanf("%d",&a);
    b=a%10;
    if (b%2)
    {
        printf("number is odd \n");
    }
    else
    {
        printf("number is even");
    }
    return 0;
}