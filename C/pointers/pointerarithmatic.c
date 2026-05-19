#include<stdio.h>
int main()
{
    int a=5;
    int *ptr=&a;
    printf("%d \n", ptr);
    printf("%d \n", ptr+1);
    char ch='A';
    char *cptr=&ch;
    printf("%d \n", cptr);
    printf("%d \n", cptr+1);
}