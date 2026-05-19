#include<stdio.h>
int main()
{
    int size, i;
    scanf("%d", &size);
    int arr[size];
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<size; i++)
    {
        
        printf("Odd array elements:");
        printf("Even array elements:");
        if(arr[i]%2!=0)
        {
            printf("%d ", arr[i]);
        }
        
        else
        {
            printf("%d ", arr[i]);
        }
    }
}