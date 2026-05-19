#include<stdio.h>
int main()
{
    char a;
    printf("give character");
   scanf("%c", &a);
   (a>='A' && a<='Z')?printf("%c is uppercase", a):(a>='a' && a<='z')?printf("%c is lowercase", a):(a>='0' && a<='9')?printf("%c is digit", a):printf("%c is speacial character", a);
}