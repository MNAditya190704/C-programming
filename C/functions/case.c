#include <stdio.h>
char toUpper(char ch);
char toLower(char ch);
int main() 
{
    char input;
    printf("Enter a character: ");
    scanf("%c", &input);
    if (input >= 'A' && input <= 'Z') 
    {
        printf("Uppercase detected. Converting to Lowercase: %c\n", toLower(input));
    } 
    else if (input >= 'a' && input <= 'z') 
    {
        printf("Lowercase detected. Converting to Uppercase: %c\n", toUpper(input));
    } 
    else 
    {
        printf("The character '%c' is not an alphabetic letter.\n", input);
    }
}
char toUpper(char ch) 
{
    return ch - 32;
}
char toLower(char ch) 
{
    return ch + 32;
}