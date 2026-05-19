#include <stdio.h>
int main()
{
    int i, size;
    printf("enter size of array");
    scanf("%d", &size);
    int arr[size];
    printf("enter elements \n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]*arr[i]);
    }
}