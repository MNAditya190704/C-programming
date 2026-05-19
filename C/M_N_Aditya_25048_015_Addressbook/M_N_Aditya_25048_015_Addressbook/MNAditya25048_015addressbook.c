/*M N Aditya
25048_015
submission date 27/03/2026
Description: 
This C code implements a File-Based Address Book Management System. It provides a complete set of CRUD (Create, Read, Update, Delete) operations for managing contacts, with data persistence using a CSV file.
Contact Management: You can add, edit, delete, and list contacts. Each contact includes a Name, Phone Number, and Email.
Data Validation:Ensures phone numbers are exactly 10 digits.
Validates email formats (checks for @ and . placement).
Prevents duplicate phone numbers.
Auto-Sorting: Automatically keeps the contact list alphabetised by name using a bubble sort algorithm every time a contact is added or edited.
Persistence: Uses load_contacts and save_contacts to sync data with a database.csv file, so information is saved even after the program closes.
Function Breakdown:
Input Handling: clear_input_buffer and remove_newline manage stdin to prevent trailing characters or newline bugs during data entry.
Search: The search_contact function is designed to find contacts by matching the first name specifically.
Logic:
add_contact: Collects validated info, checks for duplicates, and appends to the array.
delete_contact: Finds a contact by full name and shifts the remaining array elements to fill the gap.
load_contacts: Uses fscanf with a specific format string (%49[^,],...) to parse comma-separated values from the database file.*/
#include "MNAditya25048_015addressbook.h"
#include <stdio.h>
#include <string.h>

void clear_input_buffer()// clears any garbage value residue that exists from any previous operations
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void remove_newline(char *str)// removes residue new lines to ensure number of new line is 1 only. can remove data if pointed to the right index
{
    str[strcspn(str, "\n")] = '\0';
}

int is_valid_phone(char *phone)// checks whether given string is 10 elements long and has only numbers
{
    if (strlen(phone) != 10)
        return 0;

    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
            return 0;
    }
    return 1;
}

int is_valid_email(char *email)// checks whether @is coming after . to ensure proper email address
{
    int at = -1, dot = -1;

    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@') at = i;
        if (email[i] == '.') dot = i;
    }

    if (at <= 0) return 0;
    if (dot <= at + 1) return 0;
    if (dot == strlen(email) - 1) return 0;

    return 1;
}

void sort_contacts(struct AddressBook *addressBook)// sorts contacts for more organized storage
{
    for (int i = 0; i < addressBook->contactCount - 1; i++)
    {
        for (int j = i + 1; j < addressBook->contactCount; j++)
        {
            if (strcmp(addressBook->contacts[i].name,
                       addressBook->contacts[j].name) > 0)
            {
                struct Contact temp = addressBook->contacts[i];
                addressBook->contacts[i] = addressBook->contacts[j];
                addressBook->contacts[j] = temp;
            }
        }
    }
}

void add_contact(struct AddressBook *addressBook)// add contact name, phone, and email
{
    if (addressBook->contactCount >= 100)// check whether addressbook is full
    {
        printf("Address Book is full.\n");
        return;
    }

    struct Contact temp;

    clear_input_buffer();

    printf("Enter Name: ");// add name to structure
    fgets(temp.name, 50, stdin);
    remove_newline(temp.name);

    do //check for phone number validity and add to the structure
    {
        printf("Enter Phone (10 digits): ");
        fgets(temp.phone, 15, stdin);
        remove_newline(temp.phone);

        if (!is_valid_phone(temp.phone))
            printf("Invalid phone number. Try again.\n");

    } while (!is_valid_phone(temp.phone));

    do //check for email format validity and add to the structure
    {
        printf("Enter Email: ");
        fgets(temp.email, 50, stdin);
        remove_newline(temp.email);

        if (!is_valid_email(temp.email))
            printf("Invalid email format. Try again.\n");

    } while (!is_valid_email(temp.email));

    for (int i = 0; i < addressBook->contactCount; i++) //check if any of the structure variables are repeated
    {
        if (strcmp(addressBook->contacts[i].phone, temp.phone) == 0)
        {
            printf("Duplicate phone number. Contact not added.\n");
            return;
        }
    }

    addressBook->contacts[addressBook->contactCount++] = temp;

    sort_contacts(addressBook); // sort the contacts
    save_contacts(addressBook); // save the contacts

    printf("Contact added successfully.\n");
}

void search_contact(struct AddressBook *addressBook) //search for a particular contact
{
    char search[50];
    int found = 0;

    clear_input_buffer();

    printf("Enter first name to search: ");
    fgets(search, 50, stdin); //read input name to search
    remove_newline(search);

    printf("\n--- Search Results ---\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        char temp[50];
        strcpy(temp, addressBook->contacts[i].name);

        char *first = strtok(temp, " ");

        if (first && strcmp(first, search) == 0) // print contact details if found
        {
            printf("\nName  : %s\n", addressBook->contacts[i].name);
            printf("Phone : %s\n", addressBook->contacts[i].phone);
            printf("Email : %s\n", addressBook->contacts[i].email);
            found = 1;
        }
    }

    if (!found)
        printf("No matching contacts found.\n"); // print not found if name doesnt exist
}

void edit_contact(struct AddressBook *addressBook) // search for contact, and edit it.
{
    char search[50];
    int found = -1;

    clear_input_buffer();

    printf("Enter full name to edit: ");
    fgets(search, 50, stdin);
    remove_newline(search);

    for (int i = 0; i < addressBook->contactCount; i++) // search fo input contact
    {
        if (strcmp(addressBook->contacts[i].name, search) == 0)
        {
            found = i;
            break;
        }
    }

    if (found == -1) // print not found
    {
        printf("Contact not found.\n");
        return;
    }

    struct Contact *c = &addressBook->contacts[found];

    printf("Editing %s\n", c->name);

    printf("Enter new Name: ");
    fgets(c->name, 50, stdin); // enter the new name
    remove_newline(c->name); // remove the previous name through its index using function of rmoving new line

    do
    {
        printf("Enter new Phone: ");
        fgets(c->phone, 15, stdin);// enter the new phone numer
        remove_newline(c->phone); // remove the previous phone number through its index using function of rmoving new line

    } while (!is_valid_phone(c->phone));

    do
    {
        printf("Enter new Email: ");
        fgets(c->email, 50, stdin);// enter the new email
        remove_newline(c->email); // remove the previous email through its index using function of rmoving new line

    } while (!is_valid_email(c->email));

    sort_contacts(addressBook); // sort edited contact
    save_contacts(addressBook); //save the changes

    printf("Contact updated.\n");
}

void delete_contact(struct AddressBook *addressBook) //delete existing contact
{
    char search[50];
    int found = -1;

    clear_input_buffer();

    printf("Enter full name to delete: "); //read input for contact name
    fgets(search, 50, stdin);
    remove_newline(search);

    for (int i = 0; i < addressBook->contactCount; i++) // search contact
    {
        if (strcmp(addressBook->contacts[i].name, search) == 0)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Contact not found.\n");
        return;
    }

    for (int i = found; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1]; // left shift contacts to delete current contact
    }

    addressBook->contactCount--; // reduce count of number of contact

    save_contacts(addressBook); // save changes

    printf("Contact deleted.\n");
}

void list_contacts(struct AddressBook *addressBook) // list all existing contacts
{
    if (addressBook->contactCount == 0) //print no contacts available if .csv file is empty
    {
        printf("No contacts available.\n");
        return;
    }

    printf("\n--- All Contacts ---\n");

    for (int i = 0; i < addressBook->contactCount; i++) //using for loop and starting from 0 to contact count print all structure variables
    {
        printf("\nName  : %s\n", addressBook->contacts[i].name);
        printf("Phone : %s\n", addressBook->contacts[i].phone);
        printf("Email : %s\n", addressBook->contacts[i].email);
    }
}

void load_contacts(struct AddressBook *addressBook) //loading data from database to cuurent code memory
{
    FILE *fp = fopen("database.csv", "r"); // open file

    if (fp == NULL) // check for existance of file
    {
        printf("No database found. Starting fresh.\n");
        return;
    }

    while (fscanf(fp, "%49[^,],%14[^,],%49[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3) // read data from the database
    {
        addressBook->contactCount++; // condition for continuation of loop

        if (addressBook->contactCount >= 100)
            break;
    }

    fclose(fp); // close the file after loading

    sort_contacts(addressBook);
}

void save_contacts(struct AddressBook *addressBook) // save contact
{
    FILE *fp = fopen("database.csv", "w"); //open the database file

    if (fp == NULL) // check for existance of file
    {
        printf("Error saving file.\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++) // use file printf function to print data into the database file
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);
}