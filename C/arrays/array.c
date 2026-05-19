#include<stdio.h>
int main()
{
    int arr[4]={-7, 8,};
    printf("%u\n", &arr);
    for(int i=0; i<4; i++)
    {
        printf("%u\n", arr);
    }
}