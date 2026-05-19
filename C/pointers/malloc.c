#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
// char my_strdup(char *str)
// {
//     char *ptr;
//     int size=strlen(str);
//     ptr = malloc(size);
//     if (ptr == NULL)
//     {
//         printf("failed");
//         return -1;
//     }
//     strcpy(ptr, str);
//     return ptr;
// }
// int main()
// {
//     char str[100];
//     char *ptr;
//     printf("give a string to duplicate");
//     fgets(str, sizeof(str), stdin);
//     ptr= my_strdup(str);
//     puts(ptr);
//     free (ptr);
// }
// void read(int *arr, int size)
// {
//     int i;
//     for(i=0; i<size; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
// }
// void average(int *arr, int size)
// {
//     int i, sum=0;
//     float av;
//     for(i=0; i<size; i++)
//     {
//         sum=sum+arr[i];
//     }
//     av=(float)sum/size;
//     printf("%g", av);
// }
// int main()
// {
//     int size, i;
//     printf("give array size");
//     scanf("%d", &size);
//     int *arr;
//     arr= calloc(size, sizeof(int));
//     if (arr == NULL)
//     {
//         perror("error");
//         return -1;
//     }
//     printf("give %d numbers", size);
//     read(arr, size);
//     average(arr, size);
//     return 0;
// }
// int main()
// {
//     char *ptr;
//     ptr = malloc(6);
//     //ptr = malloc(741748596396878986545651321232165454878);
//     if (ptr == NULL)
//     {
//         printf("failed");
//         return -1;
//     }
//     int i;
//     for(i=0; i<6; i++)
//     {
//         ptr[i]='A'+i;
//     }
//     for(i=0; i<6; i++)
//     {
//         putchar(ptr[i]);
//     }
//     printf("\n");
//     free(ptr);
//     free(ptr);
//     free(ptr);
//     return 0;
// }
// int main()
// {
//     char *ptr;
//     ptr =strdup("aditya");
//     puts(ptr);
//     free(ptr);
//     return 0;
// }
// int main()
// {
//     char *ptr;
//     ptr = malloc(6);
//     if(ptr == NULL);
//     {
//         //printf("mem alloc fail\n");
//         perror("ERROR ");
//         return -1;
//     }
//     int i;
//     for(i = 0; i < 6; i++)
//     {
//         ptr[i] = 'A' + i;

//     }
//     for(i = 0; i < 6; i++)
//     {
//         putchar(ptr[i]);

//     }
//     printf("\n");
//     free(ptr);
//     free(ptr);
//     return 0;
// }
// int main()
// {
//     const int num=100;
//     int *iptr=&num;
//     printf("%d \n", *iptr);
//     num =200;
//     printf("%d", num);
//     return 0;
// }
// int main()
// {
//     int x=10, y=20;
//     int *const ptr =&x;
//     printf("*ptr : %d \n", *ptr);
//     //ptr=&y;
//     printf("*ptr : %d \n", *ptr);
// }
int main()
{
    int *p1, *p2;
    p1+10;
    p2-10;
    p1-p2;
    // p1*1;
    // p2/2;
    // p1+p2;
    // p1*p2;
    // p1/p2;

}