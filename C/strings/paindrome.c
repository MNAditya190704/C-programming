#include<stdio.h>
int Strln(char *character)
{
    int count=0;
    for(int i=0; character[i]!='\0';i++)
    {
        count++;
    }
    return count;
}
void palindrome(char *character)
{
    int size=Strln(character);
    for(int i=0; i<size/2; i++)
    {
        if(character[i]==character[size-1-i])
        {
            printf("is a palindrome");
            break;
        }
        else
        {
            printf("not a palindrome");
            break;
        }
    }
}
int main()
{
   int a;
    char str[100];
    scanf("%[^\n]", str);
    palindrome(str);
}