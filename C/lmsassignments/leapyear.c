#include <stdio.h>
int main(void)
{
    int y;
    printf("give year");
    scanf("%d",&y);
    if (y%4==0 && y%100!=0 && y%400==0)
    {
        printf("this is a leap year");
    }
    else
    {
        printf("not a leap year");
    }
    return 0;
}