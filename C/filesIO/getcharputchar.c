#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int ch;
    for(; (ch=getc(stdin))!=EOF;)
    {
        putchar(toupper(ch));
    }
    puts("\n EOF recieved");
    return 0;
}