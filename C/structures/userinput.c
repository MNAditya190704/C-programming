/*#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    char address[60];
};

int main() {
    struct student s1;

    printf("Enter Student ID: ");
    scanf("%d", &s1.id);

    while (getchar() != '\n'); 

    printf("Enter Name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = '\0';

    printf("Enter Address: ");
    fgets(s1.address, sizeof(s1.address), stdin);
    s1.address[strcspn(s1.address, "\n")] = '\0';

    printf("\n--- Student Record ---\n");
    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Address: %s\n", s1.address);

    return 0;
}
*/
#include<stdio.h>
