#include<stdio.h>
#include<string.h>
int power(int n, int p)
{
    if(p==0)
    {
        return 1;
    }
    else
    {
        return n=n*power(n, p-1);
    }
}
void conv(char *str)
{
    int len, sum=0, ex=0;
    len=strlen(str);
    for(int i=len-1; i>=0; i--)
    {
        int bit = str[i] - '0';
        sum=sum + (bit* power(2, ex));
        ex++;
    }
    printf("%d", sum);
}
int main()
{
    char str[100];
    printf("give binary number");
    scanf("%s", str);
    conv(str);
}