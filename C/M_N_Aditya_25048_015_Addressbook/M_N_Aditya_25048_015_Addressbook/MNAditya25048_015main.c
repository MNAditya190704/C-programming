#include<stdio.h>
#include<string.h>
#include "MNAditya25048_015addressbook.h"

int main() 
{
    int choice;

    struct AddressBook addressBook = {0};

    load_contacts(&addressBook);

    printf("Address Book Initialized\n");
    printf("Contacts loaded: %d\n", addressBook.contactCount);

    do 
    {
        printf("\n========== Address Book Menu ==========\n");
        printf("1. Add/Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        
        while (getchar() != '\n');
        
        switch (choice) 
        {
            case 1:
                add_contact(&addressBook);
                break;

            case 2:
                search_contact(&addressBook);
                break;

            case 3:
                edit_contact(&addressBook);
                break;

            case 4:
                delete_contact(&addressBook);
                break;

            case 5:
                list_contacts(&addressBook);
                break;

            case 6:
                save_contacts(&addressBook);
                printf("Saving and Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}