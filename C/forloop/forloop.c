#include <stdio.h>
int main (void)
{
    int a, i;
    printf("give the number whose table you want");
    scanf("%d", &a);
    for(i=1; i<11; i++)
    {
        printf("%d*%d=%d \n", a, i, a*i);
    }
    return 0;
}