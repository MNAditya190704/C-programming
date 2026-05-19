#include <stdio.h>
int main (void)
{
    int a;
    printf("give positive number");
    scanf("%d",&a);
    if (a<0)
    {
        printf("give positive number\n");
    }
    else if (a%2==0)
    {
        printf("number is even \n");
    }
    else {
        printf("number is odd");
    }
    return 0;
}