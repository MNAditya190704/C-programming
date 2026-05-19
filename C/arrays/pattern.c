/*#include <stdio.h>
int main() 
{
    int n,i,j;
    scanf("%d", &n);
    for(i=1; i<n; i++)
    {
        for(j=n-i; j<=n; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    for(i=n-2; i>=0; i--)
    {
        for(j=n-i; j<=n; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int n, i, j=1;
    printf("give number of elements");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf("%d \n", j);
         j=j*2;
    }
}
#include <stdio.h>

int main(void)
{
    int lines;
    int current = 1;

    printf("Enter the number of lines: ");
    scanf("%d", &lines);

    for (int i = 1; i <= lines; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", current);
            current++;
        }
        printf("\n");
    }

    return 0;
}
#include<stdio.h>
int main()
{
    int size, i, j,temp=0;
    printf("give size of array");
    scanf("%d", &size);
    int arr[size];
    printf("give array elements");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<size; i++)
    {
        for(j=0; j<size-1-i; j++)
        {
            if(arr[j]<arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
        }
    }
    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
}
#include<stdio.h>
int main()
{
    int base, e, i, j=1;
    printf("enter base value");
    scanf("%d", &base);
    printf("give exponential value");
    scanf("%d", &e);
    for(i=0; i<=e; i++)
    {
        printf("%d ", j);
        j=j*base;
    }
}
#include <stdio.h>

int main() 
{
    int rows; 
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 1; j <= rows - i; j++) 
        {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) 
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
#include<stdio.h>
int main()
{
    int size, size1, i, j,temp=0;
    float median, median1, median2;
    printf("give size of  2 arrays");
    scanf("%d %d", &size, &size1);
    int arr[size];
    int arr1[size1];
    printf("give array elements");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<size1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for(i=0; i<size; i++)
    {
        for(j=0; j<size-1-i; j++)
        {
            if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
        }
    }
    for(i=0; i<size1; i++)
    {
        for(j=0; j<size1-1-i; j++)
        {
            if(arr1[j]>arr1[j+1])
        {
            temp=arr1[j];
            arr1[j]=arr1[j+1];
            arr1[j+1]=temp;
        }
        }
    }
   if(size%2!=0)
   {
    median=(arr[size/2]);
    printf("%f \n", median);
   }
   else
   {
    median=(arr[size/2]+arr[(size/2)-1])/2;
    printf("%f \n", median);
   } 
    if(size1%2!=0)
   {
    median1=(arr[size1/2]);
    printf("%f \n", median1);
   }
   else
   {
    median1=(arr1[size1/2]+arr1[(size1/2)-1])/2;
    printf("%f \n", median1);
   }
   printf("%f", (median+median1)/2);
}*/
#include <stdio.h>
int main() 
{
    int rows = 3;
    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 1; j <= rows - i; j++) 
        {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) 
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = rows - 1; i >= 1; i--) 
    {
        for (int j = 1; j <= rows - i; j++) 
        {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) 
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
