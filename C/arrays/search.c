#include<stdio.h>
int main()
{
    int i, size, key, flag=0;
    printf("give size of array");
    scanf("%d", &size);
    int integer[size];
    printf("give the values");
    for(i=0; i<size; i++)
    {
        scanf("%d", &integer[i]);
    }
    printf("give key element to search");
    scanf("%d", &key);
    for(i=0; i<=size; i++)
    {
        if(key==integer[i])
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        printf("element not found");
    }
    else
    {
        printf("element found");
    }
}