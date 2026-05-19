#include <stdio.h>
int main() 
{
    int enteredPin;
    int correctPin = 1234;
    printf("Enter ATM PIN: ");
    scanf("%d", &enteredPin);
    if (enteredPin == correctPin) 
    {
        printf("PIN is correct. Access granted.\n");
    } else 
    {
        printf("Incorrect PIN. Access denied.\n");
    }
    return 0;
}