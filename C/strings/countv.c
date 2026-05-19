#include<stdio.h>
#include<string.h>
int countv(char *str)
{
    int i, count=0;
    for( i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
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
    scanf("%[^\n]s", str);
    a= countv(str);
    printf("%d", a);
}