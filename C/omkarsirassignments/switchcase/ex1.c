#include <stdio.h>
int main() 
{
    int feedback;
    printf("Customer Feedback System\n");
    printf("Enter feedback (0 to 4): ");
    scanf("%d", &feedback);
    switch (feedback) 
    {
        case 0:
            printf("Really disappointed\n");
            break;

        case 1:
            printf("Not great, could be better.\n");
            break;

        case 2:
            printf("It was okay, nothing special.\n");
            break;

        case 3:
            printf("Pretty good! I liked it\n");
            break;

        case 4:
            printf("Absolutely amazing! Loved it!\n");
            break;

        default:
            printf("Invalid Input\n");
    }
    return 0;
}