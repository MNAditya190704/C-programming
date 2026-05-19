#include<stdio.h>
#include<string.h>
void rmspace(char *str)
{
    int size= strlen(str);
    for(int i=0; i<size; i++)
    {
        if(str[i]=='a')
        {
            str[i]='*';
        }
    }
    printf("%s", str);
}
int main()
{
    char str[100];
    scanf("%[^\n]", str);
    rmspace(str);
}