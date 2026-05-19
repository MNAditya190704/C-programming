#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<stdio_ext.h>
int main()
{
    // while(1)
    // {
    //     printf("hello \n");
    //     fflush(stdout);
    //     sleep(1);
    // }
    // return 0;
    // char str[BUFSIZ]="iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
    // while(1)
    // {
    //     printf("%s", str);
    //     sleep(1);
    // }
    // return 0;
    // char ch ='y';
    // printf("enter a string");
    // while(ch!='n')
    // {
    //     scanf("%c", &ch);
    //     printf("%c", ch);
    // }
    // char ch='y';
    // printf("enter a string");
    // while(1)
    // {
    //     scanf("%c", &ch);
    //     //while(getchar() != '\n');
    //     __fpurge(stdin);
    //     printf("%c", ch);
    // }
    while(1)
    {
        fprintf(stdout, "hello");
        fprintf(stderr, "hello");
        sleep(1);
    }
    return 0;
}