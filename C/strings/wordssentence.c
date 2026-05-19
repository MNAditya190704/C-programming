#include<stdio.h>
int strln(char *character)
{
    int count=1;
    for(int i=0; character[i]!='\0';i++)
    {
        if(character[i]==32)
        {
        count++;
        }
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