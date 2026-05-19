#include <stdio.h>
int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num >= 0 && num <= 100) 
    {
        printf("The number is in the range 0 to 100.\n");
    } 
    else 
    {
        printf("The number is NOT in the range 0 to 100.\n");
    }
    return 0;
}