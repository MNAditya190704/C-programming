#include <stdio.h>
int main()
{
    int qualification, experience, score, age;
    int certification, internship;
    char gender;
    printf("Enter qualification (1-Graduate, 2-Postgraduate, 3-PhD): ");
    scanf("%d", &qualification);
    printf("Enter years of experience: ");
    scanf("%d", &experience);
    printf("Enter aptitude test score: ");
    scanf("%d", &score);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Has certification? (1-Yes, 0-No): ");
    scanf("%d", &certification);
    printf("Has internship? (1-Yes, 0-No): ");
    scanf("%d", &internship);
    printf("Enter gender (M/F): ");
    scanf(" %c", &gender);
    if (qualification == 3)
    {
        if (experience >= 2 && score >= 60 && age <= 45)
        {
            if (certification == 1)
            {
                printf("Directly Shortlisted\n");
            }
            else
            {
                if (internship == 1)
                {
                    printf("Shortlisted with Condition\n");
                }
                else
                {
                    printf("Not Shortlisted\n");
                }
            }
        }
        else
        {
            printf("Not Shortlisted\n");
        }
    }
    else if (qualification == 2)
    {
        if (experience >= 4 && score >= 70)
        {
            if (certification == 1)
            {
                if (age <= 35)
                {
                    printf("Priority Shortlisted\n");
                }
                else
                {
                    printf("Normal Shortlisted\n");
                }
            }
            else
            {
                if (internship == 1)
                {
                    printf("Waitlisted\n");
                }
                else
                {
                    printf("Not Shortlisted\n");
                }
            }
        }
        else if (experience >= 2 && score >= 80)
        {
            if (gender == 'F')
            {
                printf("Shortlisted under Diversity Quota\n");
            }
            else
            {
                printf("Waitlisted\n");
            }
        }
        else
        {
            printf("Not Shortlisted\n");
        }
    }
    else if (qualification == 1)
    {
        if (experience >= 6 && score >= 75)
        {
            if (certification == 1)
            {
                printf("Shortlisted (Extra Skills)\n");
            }
            else
            {
                if (internship == 1)
                {
                    printf("Waitlisted\n");
                }
                else
                {
                    printf("Not Shortlisted\n");
                }
            }
        }
        else if (experience >= 3 && score >= 85)
        {
            if (gender == 'F')
            {
                printf("Waitlisted with Preference\n");
            }
            else
            {
                printf("Waitlisted\n");
            }
        }
        else
        {
            if (experience < 3)
            {
                if (certification == 1 && score > 90)
                {
                    printf("Special Case Waitlisted\n");
                }
                else
                {
                    printf("Not Shortlisted\n");
                }
            }
            else
            {
                printf("Not Shortlisted\n");
            }
        }
    }
    else
    {
        printf("Candidate is Not Eligible\n");
    }
    return 0;
}