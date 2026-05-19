#include <stdio.h>
int main (void)
{
    int a;
    printf("give a number");
    scanf("%d",&a);
    if (a%2==0)
    {
        printf("%d \n", a+2);
    }
    else
    {
        printf("%d", a+3);
    }
    return 0;
}