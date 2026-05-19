#include<stdio.h>
void input(int arr[],int size)
{
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void output(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    int size;
    printf("give size of array");
    scanf("%d", &size);
    int arr[size];
    input(arr, size);
    output(arr, size);
}