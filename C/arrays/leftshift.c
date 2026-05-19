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
    temp=integer[0];
    printf("the left shifted array is");
    for(i=0; i<size; i++)
    {
        integer[i]=integer[i+1];
    }
    integer[size-1]=temp;
    for(i=0; i<size; i++)
    {
        printf("%d ", integer[i]);
    }
}