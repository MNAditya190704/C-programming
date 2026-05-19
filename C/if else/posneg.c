#include <stdio.h>
int main(void)
{
     int a;
    printf("give a number");
    scanf("%d",&a);
    if (a>0)
    {
        
        if (a%2==0)
        {
            printf("number is positive even\n");
        }
        else 
        {
            printf ("number is positive odd");
        }
    }
    else if (a<0)
    {
        if (a%2==0)
        {
            printf("number is negetive even\n");
        }
        else 
        {
            printf ("number is negetive odd");
        }
    }
    else {
        printf("zero is neither positive or negetive and neither even or odd");
    }
    return 0;
}