#include <stdio.h>
int main() 
{
    char choice;
    printf("Movie Ticket Booking\n");
    printf("A. Action\n");
    printf("C. Comedy\n");
    printf("D. Drama\n");
    printf("H. Horror\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    switch (choice) 
    {
        case 'A':
        case 'a':
            printf("Available Action movies: Mission Impossible, Fast & Furious\n");
            break;

        case 'C':
        case 'c':
            printf("Available Comedy movies: The Hangover, 3 Idiots\n");
            break;

        case 'D':
        case 'd':
            printf("Available Drama movies: The Shawshank Redemption, Forrest Gump\n");
            break;

        case 'H':
        case 'h':
            printf("Available Horror movies: The Conjuring, Annabelle\n");
            break;

        default:
            printf("No Such movie found\n");
    }
    return 0;
}