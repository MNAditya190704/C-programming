#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fptr;
    char ch;
    fptr= fopen("/mnt/c/Users/aditya/Desktop/emertxe course/filesIO/ex1.c", "r");
    while(ch=fgetc(fptr))
    {
        if(feof(fptr))
        break;
        fputc(ch, stdout);
    }
    fclose(fptr);
    return 0;
}