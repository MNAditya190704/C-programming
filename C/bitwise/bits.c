#include<stdio.h>
int main()
{
    int num, i, count=0;
    while (1)
    {
         printf("enter number \n ");
        scanf("%d", &num);
        for(i=31; i>=0; i--)
        {
            printf("%d", (num>>i)&1);
            int a= (num>>i)&1;
            if(a==1)
            {
                count++;
            }
        }
        printf(" %d \n ", count);
    }
    return 0;
}