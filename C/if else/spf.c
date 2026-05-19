#include <stdio.h>
int main (void)
{
    int a;
    printf("give marks scored by student out of 100");
    scanf("%d",&a);
    if (a>100 && a<0)
    {
        printf("not valid marks \n");
    }
    else if (a>90 && a<=100)
    {
        printf("grade is A");
    }
    else if (a>70 && a<=90)
    {
        printf("grade is B");
    }
    else if (a>50 && a<=70)
    {
        printf("grade is C");
    }
    else if (a>30 && a<=50)
    {
        printf("grade is D");
    }
    else
    {
        printf("grade is fail");
    }
    return 0;
}