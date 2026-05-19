#include<stdio.h>
#include<string.h>

char* my_strtok(char *str, char *delim)
{
    static int i;
    int start=1;
    static char *next;
    if(str!=NULL)
    {
        next=str;
    }
    if(next==NULL)
    {
        return NULL;
    }
    for(i=0; str[i]!='\0'; i++)
    {
        for(int j=0; delim[j]!='\0'; j++)
        {
            if(str[i]==delim[j])
            {
                str[i]='\0';
                return str;
            }
        }
    }
}

int main()
{
    char str[30];
    char delim[10];
    char original[30];
    scanf("%s", str);
    scanf("%s", delim);
    int len=strlen(str);
    strcpy(original, str);

    char *token=my_strtok(str, delim);
    
    while(token!=NULL)
    {
        printf("%s \n", token);
        token=my_strtok(NULL, delim);
    }
    len = strlen(original);
    for (int i = 0; i < len; i++)
    {
        printf("%c ", original[i]);
    }
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
    char str[30]; 
    char delim[10]; 
    printf("Enter a string : "); 
    scanf("%s", str);

    int len = strlen(str); 
    printf("Enter a delimeter: "); 
    scanf("%s", delim);
    char *token = strtok(str, delim);

    while(token != NULL)
    {

        printf("%s\n", token);
        token = strtok(NULL, delim);
    } 
    for(int i = 0; i < len; i++) 
    { 
        printf("%c", str[i]); 
    }
}*/