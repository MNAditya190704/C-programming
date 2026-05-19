#include <stdio.h>
int main()
{
    int i, j, k, size, size1, flag=0;
    printf("enter size of 1st array");
    scanf("%d", &size);
    int arr[size];
    printf("enter elements \n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter size of  2nd array \n");
    scanf("%d", &size1);
    int arr1[size1];
    printf("enter elements \n");
    for(j = 0; j < size1; j++)
    {
        scanf("%d", &arr1[j]);
    }
    if(size==size1)
    {
        for(i=0; i<size; i++)
    {
        for(j=0; j<size1; j++)
        {
            if(arr[i]==arr1[j])
            {
                flag=1;
                break;
            }
        }
    }
    }
    if(flag=0)
    {
        printf("arrays are not equal");
    }
    else
    {
        printf("arrays are equal");
    }
}