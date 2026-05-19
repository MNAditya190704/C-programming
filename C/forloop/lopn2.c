#include<stdio.h>
int main()
{
    int flag=0;
    for(int i=2; i<=100; i++)
    {
        for(int j=2; j<i; j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
            if(flag==0)
            {
                printf("%d",i);
            }
        }
    }
}