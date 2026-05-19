#include<stdio.h>

void squareNum(int a)
{
    if(a==0)return;
    
    printf("%d ", a*a);
    squareNum(a/2);
    printf("%d ", a*a);
    
}

void reverse(int a)
{

    
    if(a==0)
    
        return;
    
    printf("%d ", a%10);

    reverse(a/10);
    
    printf("%d ", a%10);
    
    reverse(a/10);
    
    printf("%d ", a%10);
    
    squareNum(a/100);
}
int main()
{
    int n;
    // condition is you have to always take a 3 digit number.
    
    // tell me what will be the output for 121
    scanf("%d", &n);
    reverse(n);
}