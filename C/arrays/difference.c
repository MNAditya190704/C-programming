#include<stdio.h>
int main()
{
    int i, size, largest=0, smallest=0;
    printf("give size of array");
    scanf("%d", &size);
    int integer[size];
    printf("give the values");
    for(i=0; i<size; i++)
    {
        scanf("%d", &integer[i]);
    }
    for(i=0; i<size-1; i++)
    {
        if(integer[i+1]>integer[i])
        {
            largest=integer[i+1];
        }
        else{
            largest=integer[i];
        }
    }
    for(i=0; i<size-1; i++)
    {
        if(integer[i+1]<integer[i])
        {
            smallest=integer[i+1];
        }
        else{
            smallest=integer[i];
        }
    }
    printf("%d", largest-smallest);
}