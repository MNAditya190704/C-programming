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
void reverse(char *character)
{
    int size=Strln(character);
    for(int i=0; i<size/2; i++)
    {
        char temp=character[i];
        character[i]=character[size-1-i];
        character[size-1-i]=temp;
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
    a= Strln(str);
    printf("%d \n", a);
    reverse(str);
}