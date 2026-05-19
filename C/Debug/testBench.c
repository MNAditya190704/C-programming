#include <stdio.h>

int main()
{
    int num, fact = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    do
    {
        fact = fact * num;
        num--;
    } 
    while (num >=1);
    printf("Factorial = %d", fact);
}