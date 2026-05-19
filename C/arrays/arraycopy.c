#include <stdio.h>
int main()
{
    int i, size, size1;
    printf("enter size of array");
    scanf("%d", &size);
    int arr[size];
    printf("enter elements \n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int arr1[size1];
    size1=size;
    for(i=0; i<size; i++)
    {
        arr1[i]=arr[i];
        printf("%d ", arr1[i]);
    }
}