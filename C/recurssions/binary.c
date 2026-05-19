/*#include<stdio.h>
int main()
{
    int n, i;
    printf("give decimal number");
    scanf("%d", &n);
    while(i>0)
    {
        i=n%2;
        printf("%d", i);
        n=n/2;
    }
}*/
#include<stdio.h>
void binary(int n)
{
    if(n==0)
    {
        return;
    }
    binary(n/2);
    printf("%d", n%2);
}
int main()
{
    int a;
    scanf("%d", &a);
    binary(a);
}