#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    (num % 10 == 0) ? printf("Multiple of 10") : printf("Not a Multiple of 10");
    return 0;
}