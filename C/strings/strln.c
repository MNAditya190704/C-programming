#include<stdio.h>
int strln(char *character)
{
    int count=0;
    for(int i=0; character[i]!='\0';i++)
    {
        count++;
    }
    return count;
}
int main()
{
   int a;
    char str[100];
    scanf("%[^\n]", str);
    a= strln(str);
    printf("%d", a);
}