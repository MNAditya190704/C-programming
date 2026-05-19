#include <stdio.h>
int main()
{
    int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);
    result = (num % 2 == 0) ? (num * num) : (num * num * num);
    printf("Result = %d", result);
    return 0;
}