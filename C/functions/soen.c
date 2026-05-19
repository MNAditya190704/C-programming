#include<stdio.h>
int soen(int n)
{
    int count=0;
    for(int i=1; i<=n; i++)
    {
        if(i%2==0)
        {
            count=count+i;
        }
    }
    return count;
}
int main()
{
    int x, count;
    printf("give limit");
    scanf("%d", &x);
    count=soen(x);
    printf("%d", count);
}