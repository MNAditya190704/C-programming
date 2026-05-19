#include <stdio.h>

int main()
{
    int arr[100], n, i, j, rotation, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter rotation count: ");
    scanf("%d", &rotation);

    rotation = rotation % n;   // useful if rotation > n

    for(i = 1; i <= rotation; i++)
    {
        temp = arr[0];

        for(j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }

        arr[n - 1] = temp;
    }

    printf("Array after left rotation: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}