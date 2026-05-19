#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define EMAIL_LEN 50

struct Contact
{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
};

struct AddressBook 
{
    struct Contact contacts[MAX_CONTACTS];
    int contactCount;
};

/* Utilities */
int is_valid_phone(char *phone);
int is_valid_email(char *email);
void sort_contacts(struct AddressBook *addressBook);
void remove_newline(char *str);

/* Core functions */
void add_contact(struct AddressBook *addressBook);
void search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);

/* File handling */
void load_contacts(struct AddressBook *addressBook);
void save_contacts(struct AddressBook *addressBook);

#endif