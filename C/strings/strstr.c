#include<stdio.h>
#include<string.h>
int main()
{
    char str[]="Good morning. How are you";
    char search[]="are";
    char *ptr= strstr(str, search);
    if(ptr==NULL)
    {
        printf("substring not found");
    }
    else
    {
        printf("substring found, %s", ptr);
    }
}