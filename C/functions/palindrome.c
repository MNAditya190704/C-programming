#include<stdio.h>
void palindrome(int num);
int main()
{
    int n;
    scanf("%d", &n);
    palindrome(n);
}
void palindrome(int num)
{
    int tbc, digit, sum;
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