#include<stdio.h>
int main()
{
    int i, size, sum=0;
    printf("give size of array");
    scanf("%d", &size);
    int arr[size];
    printf("give the values");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<size; i++)
    {
        sum=sum+arr[i];
    }
    printf("%d", sum);
}