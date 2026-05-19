#include <stdio.h>
int main()
{
    int i, size, flag=0;
    printf("give size of array");
    scanf("%d", &size);
    
    int integer[size];
    printf("give the values \n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &integer[i]);
    }
    for(i=0; i<size; i++)
    {
        if(integer[i]==integer[size-1-i])
        {flag=1;}
        else{flag=0;}
    }
    if(flag==1)
    {
        printf("array is a plaindrome");
    }
    else
    {
        printf("array is not a palindrome");
    }
}