#include <stdio.h>
int main()
{
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    (ch >= 'A' && ch <= 'Z') ? printf("Uppercase") : printf("Lowercase");
    return 0;
}