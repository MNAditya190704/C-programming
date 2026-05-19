// #include<stdio.h>
// void print_arr(char arr[][10], int size)
// {
//     int i;
//     for(i=0; i<size; i++)
//     {
//         printf("%s", arr[i]);
//     }
//     printf("\n");
// }
// int sa(const void *p1, const void *p2)
// {
//     return strcmp(p1, p2)>0;
// }
// int sd(const void *p1, const void *p2)
// {
//     return strcmp(p1, p2)<0;
// }
// int main()
// {
//     char arr[5][10]={"ram","sham","rahul","navin","kiran","vikas"};
    
// }
#include <stdio.h>
#include <stdlib.h>

void print_arr(int arr[], int size) 
{
    for(int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int sa(const void *p1, const void *p2) 
{
    int a = *(int *)p1;
    int b = *(int *)p2;
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}
int main() 
{
    int arr[5] = {9, 2, 6, 1, 7};
    int key = 8;
    int size = 5;
    qsort(arr, size, sizeof(int), sa);
    print_arr(arr, size);
    int *ptr = bsearch(&key, arr, size, sizeof(int), sa);
    (ptr == NULL) ? printf("not found\n") : printf("found\n");
    return 0;
}
