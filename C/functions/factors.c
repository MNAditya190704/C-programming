#include<stdio.h>
void factor(int n);
int main()
{
    int a;
    scanf("%d", &a);
    factor (a);
}
void factor(int n)
{
   int i;
   for(i=1; i<=n; i++)
   {
      if(n%i==0)
      {
        printf("%d \n", i);
      }
    }
}