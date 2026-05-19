#include<stdio.h>
int main()
{
    int tbc, digit, sum=0, num;
    printf("enter number to be checked");
    scanf("%d", &num);
    tbc=num;
    while(num!=0)
    {
        digit=num%10;
        sum=(sum*10)+digit;
        num=num/10;
    }
    if(sum==tbc)
    {
       printf("is a palindrome");
    }
    else
    {
        printf("not a palindrome");
    }
}