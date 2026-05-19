#include<stdio.h>
#include<string.h>
void cont(char *str1, char *str2)
{
    int a, b, size, i;
    a=strlen(str1);
    b=strlen(str2);
    size=a+b+1;
    char str3[size];
    for(i=0; i<a; i++)
    {
        str3[i]=str1[i];
        str3[i+a]=str2[i];
    }
    for(i=a; i<b; i++)
    {
        str3[i]=str2[i];
    }
    printf("%s", str3);
}
int main()
{
    char str1[100];
    char str2[100];
    printf("give 1st string");
    scanf("%[^\n]", str1);
    getchar();
    printf("give 2nd string");
    scanf("%[^\n]", str2);
    getchar();
    cont(str1,str2);
}