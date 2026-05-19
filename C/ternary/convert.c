#include<stdio.h>
int main()
{
    char ch;
    printf("give a character");
    scanf("%c", &ch);
    (ch>='A' && ch<='Z')?printf("%c", ch+32):(ch>='a' && ch<='z')?printf("%c", ch-32):printf("%c", ch);
}