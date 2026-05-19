#include<stdio.h>
int main()
// {
//     char arr[sizeof(int) + 1];
//     int *ptr1, *ptr2;
//     ptr1=&arr[0];
//     ptr2=&arr[1];
//     scanf("%x %x", ptr1, ptr2);
//     printf("%x %x", *ptr1, *ptr2);
//     return 0;
// }
{
    unsigned a=0x67;
    unsigned char b=0x39;
    printf("%hhx \n", a&b);
    printf("%hhx \n", a|b);
    printf("%hhx \n", a^b);
}