#include <stdio.h>
#include <string.h>
int mystrcmp(char *str1, char *str2) 
{
    int i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0') 
    {
        i++;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}
int main() 
{
    char str1[100];
    char str2[100];
    int a;
    printf("Give string 1: ");
    scanf(" %[^\n]", str1);
    printf("Give string 2: ");
    scanf(" %[^\n]", str2);
    a = mystrcmp(str1, str2);
    if (a == 0) 
    {
        printf("Strings are equal\n");
    } 
    else if (a > 0) 
    {
        printf("String 1 is greater\n");
    } 
    else 
    {
        printf("String 2 is greater\n");
    }
}
