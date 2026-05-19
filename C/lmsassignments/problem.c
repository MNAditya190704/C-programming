#include<stdio.h>
int main()
{
    int i, count=0, u;
    printf("which even number do you want from 1 to 100");
    scanf("%d", &u);
    if(u>50)
    {
        printf("50th even number is 100. cant give a bigger number than that");
    }
    else
    {
        for(i=1;i<=100;i++)
    {
        if(i%2==0)
        {
            count++;
        }
        if(count==u)
        {
            printf("%d", i);
            break;
        }
    }
    }
}