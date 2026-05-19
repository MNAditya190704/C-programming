#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
int main()
{
    while(1)
    {
        putc('A', stderr);
        sleep(9);
    }
    return 0;
}