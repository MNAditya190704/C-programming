#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    (num >= 0 && num <= 10) ? 
        printf("Within range") : 
        printf("Out of range");
    return 0;
}