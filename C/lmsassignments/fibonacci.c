#include<stdio.h>
int main()
{
    int f, p=0, c=1, n, temp;
    printf("give a limit for fibonacci series");
    scanf("%d", &f);
    if(f<0)
    {
        printf("give positive numbers only");
    }
    else
    {
        while(temp<=f)
        {
            printf("%d \n", c);
            n=p+c;
            temp==n;
            p=c;
            c=n;

        }
    }
}