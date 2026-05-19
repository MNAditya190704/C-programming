#include<stdio.h>
#include<string.h>
void mystrcopy(char *source, char *dest)
{
    int i;
    for(i=0; source[i]!='\0'; i++)
    {
        dest[i]=source[i];
    }
    printf("copied string is");
    printf("%s", dest);
}
int main()
{
    char source[100];
    printf("give a string");
    scanf("%[^\n]", source);
    int size=strlen(source);
    char dest[size];
    mystrcopy(source, dest);
}