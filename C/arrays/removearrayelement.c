#include <stdio.h>
int main()
{
    int i, size, key, flag = 0, pos;
    printf("give size of array");
    scanf("%d", &size);
    int integer[size];
    printf("give the values \n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &integer[i]);
    }
    printf("give key element to remove");
    scanf("%d", &key);
    for(i = 0; i < size; i++)
    {
        if(integer[i] == key)
        {
            flag = 1;
            pos = i;
            break;
        }
    }
    if(flag == 0)
    {
        printf("element not found\n");
    }
    else
    {
        for(i = pos; i < size - 1; i++)
        {
            integer[i] = integer[i + 1];
        }
        size--;
        printf("element removed successfully\n");
        printf("updated array\n");
        for(i = 0; i < size; i++)
        {
            printf("%d ", integer[i]);
        }
    }
    return 0;
}