#include <stdio.h>
int main (void)
{
    int a, b;
    printf("give 2 numbers");
    scanf("%d %d",&a,&b);
    if (a<=b)
    {
        printf("%d is greater than or equal \n",b);
    }
    else
    {
        printf("%d is greater",a);
    }
    return 0;
}