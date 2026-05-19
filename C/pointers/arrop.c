#include<stdio.h>
//int main()
// {
//     int a[2]={10, 20};
//     int b[2]={30, 40};
//     int c[2]={50, 60};
//     int *ptr[3];
//     ptr[0]=a;
//     ptr[2]=b;
//     ptr[3]=c;
//     return 0;
// }
// void print_elements(int **ptr)
// {
//     int i, j;
//     for(i=0; i<3; i++)
//     {
//         for(i=0; i<3; i++)
//         {
//             printf("%d", ptr[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main()
// {
    
//     int a[2]={10, 20};
//     int b[2]={30, 40};
//     int c[2]={50, 60};
//     print_elements(ptr);
//     return 0;
// }
// int main()
// {
//     char s[3][8]={"array", "of", "string"};
//     printf("%s %s %s", s[0], s[1], s[2]);
// }
int main()
{
    char *s[3];
    s[0]="array";
    s[1]="of";
    s[2]="strings";
    printf("%s %s %s \n", s[0], s[1], s[2]);
    for(int i=0; i<3; i++)
    {
        printf("%s", s[i]);
    }
    printf("\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; s[i][j]; j++)
        {
            printf("%c", s[i][j]);
        }
    }
}