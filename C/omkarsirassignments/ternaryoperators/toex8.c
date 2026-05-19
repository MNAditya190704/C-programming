#include <stdio.h>
int main()
{
    float salary, bonus;
    int exp;
    printf("Enter salary and experience: ");
    scanf("%f %d", &salary, &exp);
    bonus = (exp >= 10) ? salary * 0.15 :(exp >= 5)  ? salary * 0.10 :salary * 0.05;
    printf("Bonus = %.2f", bonus);
    return 0;
}