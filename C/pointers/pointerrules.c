// #include<stdio.h>
// int main()
// {
//     int num=0;
//     scanf("%d", num);
//     printf("%d\n", *num);
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     double x=7.2;
//     void *vptr=&x;
//     printf("%hhx \n", *(char *)vptr);
//     printf("%hhx \n", *(char *)(vptr+7));
//     printf("%hx \n", *(short *)(vptr+3));
//     printf("%x \n", *(int *)(vptr+0));
//     return 0;
// }
#include<stdio.h>
void swap(int *first, int *second)
{
    int temp;
    temp=*first;
    *first=*second;
    *second= temp;
}
int main()
{
    int n1=10, n2=20;
    printf("before %d %d \n", n1, n2);

}