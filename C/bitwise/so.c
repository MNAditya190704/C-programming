#include<stdio.h>
int main()
// {
//     unsigned int i;
//     int c;
//     while(1)
//     {
//         printf("give a hexadecimal value \n");
//         scanf("%x", &i);
//         for(c=0; i!=0; i>>=1)
//         {
//             if(i & 01)
//             {
//                 c++;
//             }
//         }
//         printf("%d \n", c);
//     }
// }
{
    int x=7, y=7;

    x=7 >> 30;
    printf("%x", x);

    x=y << 30;
    printf("%x", x);
}