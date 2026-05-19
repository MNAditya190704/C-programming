#include <stdio.h>
int main() 
{
    int attendance;
    printf("Enter attendance (1 for Present, 0 for Absent): ");
    scanf("%d", &attendance);
    if (attendance == 1) 
    {
        printf("Student is Present.\n");
    } 
    else if (attendance == 0) 
    {
        printf("Student is Absent.\n");
    } else 
    {
        printf("Invalid input.\n");
    }
    return 0;
}