#include<stdio.h>
#include<unistd.h>
int num;
void fun1();
void fun2();
int main()
{
    while(1)
    {
        num++;
        fun1();
    }
}