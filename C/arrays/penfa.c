#include<stdio.h>
int main()
{
    int i, size;
    printf("give size of array");
    scanf("%d", &size);
    int integer[size];
    printf("give the values");
    for(i=0; i<size; i++)
    {
        scanf("%d", &integer[i]);
    }
    for(i=0; i<size; i++)
    {
        if(integer[i]%2==0)
        {
            printf("%d ", integer[i]);
        }
    }
    printf("\n");
}