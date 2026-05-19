#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    char str[10];
    puts("enter the string");
    //gets(str);
    fgets(str, 10, stdin);
    puts(str);
    return 0;
}