#include <stdio.h>

int main(void) {
    int a, b, result;
    char operation, c, greater, smaller, equal;

    printf("Give first number: ");
    scanf("%d", &a);

    printf("Give second number: ");
    scanf("%d", &b);

    printf("Mention operation (+, -, *, /,comp,e): ");
    scanf(" %c", &operation);

    if (operation == '+') {
        result = a + b;
        printf("Answer is %d\n", result);
    } 
    else if (operation == '-') {
        result = a - b;
        printf("Answer is %d\n", result);
    } 
    else if (operation == '*') {
        result = a * b;
        printf("Answer is %d\n", result);
    } 
    else if (operation == '/') {
        if (b != 0) {
            result = a / b;
            printf("Answer is %d\n", result);
        } else {
            printf("Error: Division by zero is not allowed.\n");
        }
    } 
    else if(operation == 'c') {
         if (a>b)
    {printf ("%d is greater %d",a,b);}
    else if (a<b)
    {printf ("%d is smaller than %d");}
    else    {printf ("equal");}
    }
     else if (operation == 'e') 
    {
         int e;
    printf ("give a number");
    scanf ("%d",&e);
    if (e%2==0){
        printf("the number is even");
    }
    else {printf("number is odd");}
    }
    else {
        printf("Not applicable\n");
    }

    return 0;
}