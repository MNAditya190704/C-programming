#include <stdio.h>
int main()
{
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    ch = (ch >= 'A' && ch <= 'Z') ? (ch + 32) :(ch >= 'a' && ch <= 'z') ? (ch - 32) :ch;
    printf("Converted character: %c", ch);
    return 0;
}