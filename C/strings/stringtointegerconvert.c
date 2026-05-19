#include<stdio.h>
#include<string.h>
void stringintconv(char *str)
{
    int size=strlen(str);
    int sum;
    for(int i=0; i<size; i++)
    {
        sum=sum +str[i]*size*10;
        size--;
    }
    return sum;
}
void intstringconv(int num)
{
   char cstr[100];
   for(int str[i]<='\0'; i>=0; i--)
   {
    str[i]=num%10;
    num=num/10;
   }
   printf("%s", cstr);
}