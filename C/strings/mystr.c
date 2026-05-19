#include<stdio.h>
#include<string.h>
char *mystr(char *str, char *sub)
{
    int i, j;
    for(i=0; str[i]!='\0'; i++)
    {
        if(sub[0]==str[i])
        {
            for(j==1; sub[j]!='\0'; j++)
            {
                if(str[i+j]!=sub[j])
                {
                    i=i+j;
                    break;
                }
            }
            if(sub[j]=='\0')
            {
                &str[i];
            }
        }
    }
}
int main()
{
    char str[]="Good morning. How are you";
    char search[]="are";
    char *ptr= mystr(str, search);
    if(ptr==NULL)
    {
        printf("substring found, %s", ptr);
    }
    else
    {
        printf("substring not found");
    }
}