#include<stdio.h>

int x;
static int x=10;
int foo()
{
    printf("%d", x);
}
int main()
{
    foo();

}