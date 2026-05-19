#include<stdio.h>
int main ()
{
    int e;
    printf ("give a number");
    scanf ("%d",&e);
    if (e==0){
        printf("zero is neither even or odd");
    }
    else if (e%2)
    {printf("number is odd");}
    else {
        printf ("number is even");
    }
    return 0;
}