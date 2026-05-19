#include <stdio.h>
int main()
{
    int password;
    do
    {
        printf("Enter password: ");
        scanf("%d", &password);
        if (password != 1234)
        {
            printf("Incorrect password. Try again.\n");
        }
    } 
    while (password != 1234);
    printf("Access granted.");
    return 0;
}