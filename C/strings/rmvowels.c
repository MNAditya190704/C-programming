#include<stdio.h>
#include<string.h>
void rmky(char *str)
{
    int i, j;
    char key;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
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