#include <stdio.h>
int main()
{
    int choice;
    do
    {
        printf("\n1. Start\n2. Stop\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Started\n");
        }
        else if (choice == 2)
        {
            printf("Stopped\n");
        }
        else if (choice == 3)
        {
            printf("Exiting...\n");
        }
        else
        {
            printf("Invalid choice\n");
        }

    } 
    while (choice != 3);
    return 0;
}