#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define SUB_LEN  50

// User-defined datatype for Student
typedef struct
{
    int roll;
    char *name;
    int *marks;
    float avg;
    char grade;
} Student;

// Function to calculate grade
char calculateGrade(float avg)
{
    if(avg >= 90)
    {
         return 'A';
    }
    else if(avg >= 75)
    {
         return 'B';
    }
    else if(avg >= 50)
    {
        return 'C';
    }
    else
    {
        return 'D';
    }
}

void displayStudent(Student *s, char **subjects, int sub)// Function to display one student
{
    int j;

    printf("Roll No.\tName\t");

    for(j = 0; j < sub; j++)
    {
        printf("%s\t", *(subjects + j));
    }

    printf("Average\tGrade\n");

    printf("%d\t\t%s\t", s->roll, s->name);

    for(j = 0; j < sub; j++)
    {
        printf("%d\t", *(s->marks + j));
    }

    printf("%.2f\t\t%c\n", s->avg, s->grade);
}

int main()
{
    int n, sub;
    int i, j;
    int choice, option;
    int search_roll;
    char search_name[NAME_LEN];
    char cont;

    Student *s;// Dynamic memory allocation for number of students

    char **subjects;// Dynamic memory allocation for subjects

    printf("Enter no. of students : ");
    scanf("%d", &n);

    printf("Enter no. of subjects : ");
    scanf("%d", &sub);

    s = (Student *)malloc(n * sizeof(Student));// Allocate memory for students

    if(s == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    subjects = (char **)malloc(sub * sizeof(char *));// Allocate memory for subject names

    if(subjects == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(i = 0; i < sub; i++)// Allocate memory for each subject name
    {
        *(subjects + i) = (char *)malloc(SUB_LEN * sizeof(char));

        if(*(subjects + i) == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter the name of subject %d : ", i + 1);
        scanf("%s", *(subjects + i));
    }

    for(i = 0; i < n; i++)// Input student details
    {
        int sum = 0;

        printf("\nEnter student %d details\n", i + 1);

        printf("Enter Roll no. : ");
        scanf("%d", &(s + i)->roll);

        (s + i)->name = (char *)malloc(NAME_LEN * sizeof(char));// Allocate memory for student name

        if((s + i)->name == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter student name : ");
        scanf("%s", (s + i)->name);

        (s + i)->marks = (int *)malloc(sub * sizeof(int));// Allocate memory for marks

        if((s + i)->marks == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        for(j = 0; j < sub; j++) // Input marks
        {
            printf("Enter %s mark : ", *(subjects + j));

            scanf("%d", ((s + i)->marks + j));

            sum += *((s + i)->marks + j);
        }

        (s + i)->avg = (float)sum / sub;// Calculate average and grade

        (s + i)->grade = calculateGrade((s + i)->avg);
    }

    // Menu
    do
    {
        printf("1. All student details\n");
        printf("2. Particular student details\n");
        printf("Enter choice:");
        scanf("%d", &choice);

        if(choice == 1)
        {
            for(i = 0; i < n; i++)
            {
                displayStudent((s + i), subjects, sub);
                printf("\n");
            }
        }

        else if(choice == 2)
        {
            printf("1. Search by Name\n");
            printf("2. Search by Roll no.\n");
            printf("Enter your choice : ");
            scanf("%d", &option);

            if(option == 1)
            {
                printf("Enter the name of the student : ");
                scanf("%s", search_name);

                for(i = 0; i < n; i++)
                {
                    if(strcmp((s + i)->name, search_name) == 0)
                    {
                        displayStudent((s + i), subjects, sub);
                    }
                }
            }

            else if(option == 2)
            {
                printf("Enter the roll no. of the student : ");
                scanf("%d", &search_roll);

                for(i = 0; i < n; i++)
                {
                    if((s + i)->roll == search_roll)
                    {
                        displayStudent((s + i), subjects, sub);
                    }
                }
            }
        }

        printf("\nDo you want to continue (Y/y) : ");
        scanf(" %c", &cont);

    } while(cont == 'Y' || cont == 'y');

    // Free allocated memory

    for(i = 0; i < n; i++)
    {
        free((s + i)->name);
        free((s + i)->marks);
    }

    for(i = 0; i < sub; i++)
    {
        free(*(subjects + i));
    }

    free(subjects);
    free(s);

    return 0;
}