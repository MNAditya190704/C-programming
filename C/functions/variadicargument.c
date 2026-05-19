// #include<stdio.h>
// #include<stdarg.h>
// int add(int count1, int count2, ...)
// {
//     va_list ap;
//     int iter, sum;
//     va_start(ap, count2);
//     sum=0;
//     for(iter=0; iter<count1; iter++)
//     {
//         sum+=va_arg(ap,int);
//     }
//     va_end(ap);
//     return sum;
// }
// int main()
// {
//     int ret;
//     ret=add(3,2,4,4);
//     printf("sum is %d \n", ret);
// }
// #include <stdio.h>
// #include <stdarg.h> // Required for ... arguments

// void my_printf(const char *fmt, ...)
// {
//     va_list args;
//     va_start(args, fmt);
    
//     vprintf(fmt, args); // Standard helper for custom printf
    
//     va_end(args);
// }

// int main()
// {
//     my_printf("hello world \n");
//     return 0;
// }
#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
void my_print(const char *fmt, ...)
{
    int num;
    va_list ap;
    va_start(ap, fmt);
    while(*fmt!='\0')
    {
        if(*fmt=='%')
        {
            num=va_arg(ap, int);
            fprintf(stdout, "%d", num);
        }
        else
        {
            putchar(*fmt);
        }
        fmt++;
    }
}
int main()
{
    my_print("hello world \n");
    return 0;
}