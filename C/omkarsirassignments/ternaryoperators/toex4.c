#include <stdio.h>
int main()
{
    char ch;
    printf("Enter uppercase character: ");
    scanf(" %c", &ch);
    ch = (ch >= 'A' && ch <= 'Z') ? (ch + 32) : ch;
    printf("Converted character: %c", ch);
    return 0;
}