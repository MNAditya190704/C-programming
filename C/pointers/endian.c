#include<stdio.h>
int main()
{
    int num=0X80;
    int *ptr=&num;
    printf("%x", *ptr);
    char*cptr=&num;
    printf("%hhx", *ptr);
    if(*cptr==0)
    {
        printf("little endian");
    }
    else
    {
        printf("bug endian");
    }
}