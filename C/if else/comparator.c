#include <stdio.h>
int main (void)
{
   int a,b,c;
   char greater,smaller,equal;
    printf("give first number a");
    scanf("%d", &a);
     printf("give second number b");
    scanf("%d", &b);
    printf("give third number c");
    scanf("%d", &c);
    if (a>b)
    {
        if(a>c)
        {
            printf("a is the largest number");
        }
        else
        {
            printf("c is the largest number");
        }
    }
   else
    {
         if(b>c)
        {
            printf("b is the largest number");
        }
        else
        {
            printf("c is the largest number");
        }
    }
    return 0;
}