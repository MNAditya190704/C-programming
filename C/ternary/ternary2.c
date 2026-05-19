#include<stdio.h>
int main()
{
    char a;
    printf("give letter");
   scanf("%c", &a);
   (a>='A' && a<='B')?printf("%c is the uppercase", a):printf("%c is lowercase", a);
}