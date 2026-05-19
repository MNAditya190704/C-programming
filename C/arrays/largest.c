#include<stdio.h>
int main()
{
    int i, size, largest=0;
    printf("give size of array");
    scanf("%d", &size);

    int intArr[size];
    printf("give the values");

    for(i=0; i<size; i++)
    {
        scanf("%d", &intArr[i]);
    }

    for(i=0; i<size-1; i++)
    {
        if(intArr[i+1]>intArr[i])
        {
            largest=intArr[i+1];
        }
        else{
            largest=intArr[i];
        }
    }
    printf("%d", largest);
}