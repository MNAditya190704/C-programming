#include <stdio.h>
int main()
{
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    (ch >= 'A' && ch <= 'Z') ? printf("Uppercase Letter") :(ch >= 'a' && ch <= 'z') ? printf("Lowercase Letter") :(ch >= '0' && ch <= '9') ? printf("Digit") :printf("Special Character");
    return 0;
}