#include <stdio.h>
void my_wc(void)
{
    int c;
    int in_word = 0;
    int char_count = 0;
    int word_count = 0;
    int line_count = 0;
    while ((c = getchar()) != EOF)
    {
        char_count++;
        if (c == '\n')
        {
            line_count++;
        }
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (in_word == 1)
            {
                word_count++;
                in_word = 0;
            }
        }
        else if (in_word == 0)
            {
                in_word = 1;
            }
    }
    if (in_word == 1)
    {
        word_count++;
    }
    printf("Characters: %d\n", char_count);
    printf("Words: %d\n", word_count);
    printf("Lines: %d\n", line_count);
}
int main(void)
{
    my_wc();
    return 0;
}