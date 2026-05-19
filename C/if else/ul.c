#include <stdio.h>
int main(void)
{
    char ch;
    printf("give a letter");
    scanf("%c",&ch);
    if (ch>='A' && ch<='Z')
    {
        printf("letter is uppercase");
    }
    else {
        printf("letter is lowercase");
    }
    return 0;
}