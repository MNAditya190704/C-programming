#include<stdio.h>
int main()
{
    int d, m, n;
    printf("give number for the day when the year starts");
    scanf("%d", &d);
    if(d<0 && d>7)
    {
        printf("invalid input");
    }
    printf("which day of the year would you like to know the day of");
    scanf("%d", &n);
     if(n<0 && n>365)
    {
        printf("invalid input");
    }
    m=((d+n)-1)%7;
    switch(m)
    {
        case 0:
        printf("the day is sunday");
        break;
        case 1:
        printf("the day is monday");
        break;
        case 2:
        printf("the day is tuesday");
        break;
        case 3:
        printf("the day is wednesday");
        break;
        case 4:
        printf("the day is thursday");
        break;
        case 5:
        printf("the day is friday");
        break;
        case 6:
        printf("the day is saturday");
        break;
    }
}