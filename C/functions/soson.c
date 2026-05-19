#include<stdio.h>
void sodon(int num)
{
    int  sum=0, digit;
    while(num!=0)
    {
        digit=num%10;
        sum=sum+digit;
        num =num/10;
    }
    printf("%d is the sum of individual digits", sum);
}
int main()
{
    int n;
    printf("give a number");
    scanf("%d", &n);
    sodon(n);
}