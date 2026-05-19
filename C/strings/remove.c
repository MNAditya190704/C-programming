#include<stdio.h>
#include<string.h>
void rmky(char *str)
{
    int i, j;
    char key;
    printf("enter key");
    scanf(" %c", &key);
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]==key)
        {
            for(j=i; str[j]!='\0'; j++)
            {
                str[j]=str[j+1];
            }
            i--;
        }
    }
    printf("%s", str);
}
int main()
{
   int a;
    char str[100];
    scanf("%[^\n]", str);
    rmky(str);
}