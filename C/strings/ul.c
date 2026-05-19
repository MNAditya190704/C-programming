#include<stdio.h>
void strln(char *character)
{
    for(int i=0; character[i]!='\0';i++)
    {
        if(character[i]>='a' && character[i]<='z')
        {
            character[i]=character[i]-32;
        }
        else  if(character[i]>='A' && character[i]<='Z')
        {
            character[i]=character[i]+32;
        }
    }
    for(int i=0; character[i]!='\0';i++)
    {
        printf("%c",character[i]);
    }
}
int main()
{
   int a;
    char str[100];
    scanf("%[^\n]s", str);
    strln(str);
}