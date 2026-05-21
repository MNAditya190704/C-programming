#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define swap(t, x, y) { t temp = x; x = y; y = temp; }
int main() 
{
    int choice;
    printf("1. Int\n2. char\n3. short\n4. float\n5. double\n6. string\n");
    printf("Enter your choice : ");
    if (scanf("%d", &choice) != 1) {
        return 1;
    }
    switch (choice) 
    {
        case 1: 
        {
            int num1, num2;
            printf("\Enter the num1 : ");
            scanf("%d", &num1);
            printf("Enter the num2 : ");
            scanf("%d", &num2);
            swap(int, num1, num2);
            printf("After Swapping :\n");
            printf("num1 : %d\n", num1);
            printf("num2 : %d\n", num2);
            break;
        }
        case 2: 
        {
            char c1, c2;
            printf("\nEnter the char1 : ");
            scanf(" %c", &c1);
            printf("Enter the char2 : ");
            scanf(" %c", &c2);
            swap(char, c1, c2);
            printf("After Swapping :\n");
            printf("char1 : %c\n", c1);
            printf("char2 : %c\n", c2);
            break;
        }
        case 3: 
        {
            short s1, s2;
            printf("\nEnter the short1 : ");
            scanf("%hd", &s1);
            printf("Enter the short2 : ");
            scanf("%hd", &s2);
            swap(short, s1, s2);
            printf("After Swapping :\n");
            printf("short1 : %hd\n", s1);
            printf("short2 : %hd\n", s2);
            break;
        }
        case 4: 
        {
            float f1, f2;
            printf("\nEnter the float1 : ");
            scanf("%f", &f1);
            printf("Enter the float2 : ");
            scanf("%f", &f2);
            swap(float, f1, f2);
            printf("After Swapping :\n");
            printf("float1 : %g\n", f1);
            printf("float2 : %g\n", f2);
            break;
        }
        case 5: 
        {
            double d1, d2;
            printf("\nEnter the double1 : ");
            scanf("%lf", &d1);
            printf("Enter the double2 : ");
            scanf("%lf", &d2);
            swap(double, d1, d2);
            printf("After Swapping :\n");
            printf("double1 : %lg\n", d1);
            printf("double2 : %lg\n", d2);
            break;
        }
        case 6:
        {
            char *str1 = malloc(100 * sizeof(char));
            char *str2 = malloc(100 * sizeof(char));
            if (str1 == NULL || str2 == NULL)
            {
                return 1;
            }
            printf("\nEnter the string1 : ");
            scanf("%99s", str1);
            printf("Enter the string2 : ");
            scanf("%99s", str2);
            swap(char*, str1, str2);
            printf("After Swapping :\n");
            printf("string1 : %s\n", str1);
            printf("string2 : %s\n", str2);
            free(str1);
            free(str2);
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}