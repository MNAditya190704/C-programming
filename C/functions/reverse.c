#include<stdio.h>
int reverse(int num);
int main()
{
    int n, sum;
    printf("enter number to be reversed");
    scanf("%d", &n);
    sum=reverse(n);
    printf("%d", sum);
}
int reverse(int num)
{
    int digit, sum=0;
    while(num!=0)
    {
        digit=num%10;
        sum=(sum*10)+digit;
        num=num/10;
    }
    return sum;
}