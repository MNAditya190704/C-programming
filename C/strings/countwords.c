#include<stdio.h>
#include<string.h>
int rmspace(char *str)
{
    int size= strlen(str);
    int count=0;
    for(int i=0; i<size; i++)
    {
        if(str[i]==' ')
        {
            count++;
        }
    }
    return count;
}
int main()
{
    char str[100];
    scanf("%[^\n]", str);
    int a=rmspace(str);
    printf("%d", a);
}