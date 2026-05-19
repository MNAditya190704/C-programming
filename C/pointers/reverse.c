#include<stdio.h>
void reverse(int size, int arr[]);
int main()
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverse(size, arr);
}
void reverse(int size, int arr[])
{
    /*int temp;
    for(int i=0; i< size/2; i++)
    {
        temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }*/
   if(int i<size)
}