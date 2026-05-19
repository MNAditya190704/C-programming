#include<stdio.h>
void print_array(int row, int col, int *p)
{
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d \n", *((p+i*col)+j));
        }
    }
}
int main()
{
    int a[2][3]={{1,2,3},{4,5,6}};
    print_array(2,3,(int*)a);
    return 0;
}
//     int row, col, i, j;
//     int *p;
//     printf("give number of rows and columns");
//     scanf("%d %d", &row, &col);
//     int a[row][col];
//     printf("give the elements");
//     for(i=0; i<row; i++)
//     {
//         for(i=0; i<col; i++)
//         {
//             scanf("%d ", &a[i][j]);
//         }
//     }
//     print_array(row, col, (int*) a);