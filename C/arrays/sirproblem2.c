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

    rotation = rotation % n;

    for(i = 1; i <= rotation; i++)
    {
        temp = arr[n - 1];

        for(j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }

        arr[0] = temp;
    }

    printf("Array after right rotation: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}