#include <stdio.h>
int main()
{
    int i, size, temp;
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
        temp=integer[i];
        integer[i]=integer[size-1-i];
        integer[size-1-i]=temp;
    }
    printf("reverse of the array is");
    for(i=size-1; i>=0; i--)
    {
        
        printf(" %d", integer[i]);
    }
}