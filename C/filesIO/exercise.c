#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
int main()
/*{
    char ch;
    int flag=1;
    for(;(ch=getchar())!='\n';)
    {
        if((ch == ' ' || ch=='\t')&& flag)
        {
            putchar(' ');
            flag=0;
        }
        if(ch!= ' ' && ch!='\t')
        {
            putchar(ch);
            flag=1;
        }
    }
    puts("\n");
    return 0;
}*/
{
    char a[8]=" Emertxe";
    int x, ay;
    //printf(a);
    int printf(const char *fmt, ...);//elipses variable functions, any number of arguments of any type can be passed. in ta function comma is a seperator
    printf("hello world\n");
    printf("x=%a \n", 123.6);// variodic arguments
    printf("s=%e, av=%E \n", 1.2, 1.3); //3 arguments
    printf("%hX \n", 0xFFFFFFFF);
    //printf("%IIX \n", 0xFFFFFFFFFFFFFFFF);
    printf("%Lf\n ", 1.23456789L);
    printf("%3d %3d \n", 1, 1);
    printf("%10s \n", "hello");
    printf("%*d \n", 1, 1);
    printf("%*d \n", 2, 1);
    printf("%*d \n", 5, 1);
    printf("%3.1d \n", 1);
    printf("%3.2d \n", 1);
    printf("%3.3d \n", 1);
    printf("%0.3f \n", 1.0);
     printf("%0.10f \n", 1.0);
      printf("%12.8s \n", "hello world");
      printf("%#x %#X %#x \n", 0XA, 0XA, 10);
      printf("%#o \n", 10);
      printf("%-3d, %-3d \n", 1, 1);
      printf("%3d \n", -100);
      printf("Hello \r World \n");
      printf("Hello \t World \n");
      printf("Hello\bWorld \n");
      printf("Hello \v World \n");
      printf("Hello \f World \n");
      printf("Hello \e World \n");
      printf("Hello \\ World \n");
      printf("Hello \" World 80%% \n ");
      int num1=123;
      char ch='A';
      float num2=12.12345;
      char string[]="hello world";
      printf("%+05d\n", num1);
      printf("%.2f %.5s\n",  num2, string);
}