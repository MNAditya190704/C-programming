#include <stdio.h>
int main (void)
{
    float a;
    printf("give total amount from shopping");
    scanf("%f",&a);
    if (a<1000)
    {
        printf("discounts not available \n");
    }
    else if (a>=3000)
    {
        printf("%f is the new total amount",a-(.20*a));
    }
    else if (a>=2000 && a<3000)
    {
        printf("%f is the new total amount",a-(.15*a));
    }
    else if (a>=1000 && a<2000)
    {
        printf("%f is the new total amount",a-(.05*a));
    }
    return 0;
}