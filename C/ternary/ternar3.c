#include<stdio.h>
int main()
{
    int a;
    printf("give number");
   scanf("%d", &a);
   (a>=0 && a<=10)?printf("%d is in the range of 0 to 10", a):printf("%d is not in the range of 0 to 10", a);
}