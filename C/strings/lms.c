#include <stdio.h>
#include <ctype.h>

void squeeze_spaces(char *str) 
{
    int i = 0, j = 0;
    int in_blank = 0;
    while (isspace(str[i])) i++;
    while (str[i] != '\0')\
    {
        if (!isspace(str[i]))
        {
            str[j++] = str[i];
            in_blank = 0;
        }
        else 
        {
            if (!in_blank) 
            {
                str[j++] = ' ';
                in_blank = 1;
            }
        }
        i++;
    }
    if (j > 0 && str[j - 1] == ' ') j--;
    str[j] = '\0';
}

int main() {
    char text[] = "Pointers         are      sharp           knives.";

    printf("Input string:\n%s\n", text);
    
    squeeze_spaces(text);
    
    printf("Output String:\n%s\n", text);

    return 0;
}
