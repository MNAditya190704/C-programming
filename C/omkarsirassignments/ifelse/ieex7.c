#include <stdio.h>
int main() 
{
    int marks;
    printf("Enter student marks: ");
    scanf("%d", &marks);
    if (marks >= 35) 
    {
        printf("Student has PASSED.\n");
    } 
    else 
    {
        printf("Student has FAILED.\n");
    }
    return 0;
}