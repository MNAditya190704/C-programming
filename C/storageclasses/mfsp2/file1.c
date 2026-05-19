#include<stdio.h>
#include<unistd.h>
int num;
void func1();
int main()
{
    while(1)
    {
        num++;
        func1();
        sleep(1);

    }
    return 0;
}