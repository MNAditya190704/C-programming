#include<stdio.h>

extern int num;
static void func2()
{
    printf("num is %d from file 1 \n", num);
}
void func1()
{
    func2;
}