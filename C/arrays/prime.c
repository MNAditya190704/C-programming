#include<stdio.h>
int main()
{
    int i, j, size, count;
    printf("give size of array");
    scanf("%d", &size);

    int arr[size];

    printf("give data");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("prime numbers are");
    for(i=0; i<size; i++)
    {
        count=0;
        for(j=1; j<=arr[i]; j++)
        {
            if(arr[i]%j==0)
            {
                count++;
            }
        }
        if(count==2)
        {
            printf("%d \n", arr[i]);
        }
    }
}