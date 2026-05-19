#include <stdio.h>
#include <string.h>
#include <unistd.h>
void arrot(char str[]) 
{
    int len = strlen(str);
    char temp[len + 1];
    while (1) 
    {
        printf("\r%s ", str);
        fflush(stdout);
        char first = str[0];
        for (int i = 0; i < len - 1; i++) 
        {
            str[i] = str[i + 1];
        }
        str[len - 1] = first;
        usleep(100000); 
    }
}
int main() 
{
    char message[100] = "hello my name is aditya. wecome to my program.";
    arrot(message);
}
