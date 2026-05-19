#include <stdio.h>
int main() 
{
    int languageChoice, movieChoice;
    int tickets;
    int seatChoice;
    int pricePerTicket = 0;
    int totalAmount = 0;
    char confirm;
    printf("=== Movie Ticket Booking System ===\n");
    printf("Select Language:\n");
    printf("1. Hindi\n");
    printf("2. Marathi\n");
    printf("3. Kannada\n");
    printf("4. Tamil\n");
    printf("Enter your choice: ");
    scanf("%d", &languageChoice);
    if (languageChoice < 1 || languageChoice > 4) 
    {
        printf("Invalid language choice. Exiting...\n");
        return 0;
    }
    printf("\nSelect Movie:\n");
    switch (languageChoice) 
    {
        case 1:
            printf("1. Pathaan\n2. Jawan\n3. Dangal\n");
            break;
        case 2:
            printf("1. Sairat\n2. Natsamrat\n3. Katyar Kaljat Ghusli\n");
            break;
        case 3:
            printf("1. Kantara\n2. KGF\n3. Ugramm\n");
            break;
        case 4:
            printf("1. Leo\n2. Vikram\n3. Master\n");
            break;
    }
    printf("Enter movie choice: ");
    scanf("%d", &movieChoice);
    if (movieChoice < 1 || movieChoice > 3) 
    {
        printf("Invalid movie choice. Exiting...\n");
        return 0;
    }
    printf("\nEnter number of tickets: ");
    scanf("%d", &tickets);
    if (tickets <= 0) 
    {
        printf("Invalid number of tickets. Exiting...\n");
        return 0;
    }
    printf("\nSelect Seat Type:\n");
    printf("1. Regular (₹180)\n");
    printf("2. Premium (₹300)\n");
    printf("Enter your choice: ");
    scanf("%d", &seatChoice);
    if (seatChoice == 1) 
    {
        pricePerTicket = 180;
    } 
    else if (seatChoice == 2) 
    {
        pricePerTicket = 300;
    } 
    else 
    {
        printf("Invalid seat type. Exiting...\n");
        return 0;
    }
    totalAmount = tickets * pricePerTicket;
    printf("\n=== Booking Summary ===\n");
    printf("Tickets: %d\n", tickets);
    printf("Seat Type: %s\n", seatChoice == 1 ? "Regular" : "Premium");
    printf("Total Amount: ₹%d\n", totalAmount);
    printf("\nConfirm Booking (Y/N): ");
    scanf(" %c", &confirm);
    if (confirm == 'Y' || confirm == 'y') 
    {
        printf("Booking Confirmed! Enjoy your movie 🎉\n");
    } 
    else if (confirm == 'N' || confirm == 'n') 
    {
        printf("Booking Cancelled.\n");
    } 
    else 
    {
        printf("Invalid response.\n");
    }
    return 0;
}