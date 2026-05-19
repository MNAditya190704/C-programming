#include<stdio.h>
int main()
{
    int digit, sum=0, num;
    printf("enter number to be reversed");
    scanf("%d", &num);
    while(num!=0)
    {
        digit=num%10;
        sum=(sum*10)+digit;
        num=num/10;
    }
    printf("%d", sum);
}