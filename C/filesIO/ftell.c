#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    fp=fopen("text.txt", "r");
    if(fp== NULL)
    {
        perror("ERROR");
        return -1;
    }
    char ch;
    printf("file offset is at: %ld \n \n", ftell(fp));
    while((ch=fgetc(fp))!=EOF)
    {
        fputc(ch, stdout);
    }
    printf("\n at the end file offset is at: %ld \n", ftell(fp));
    fclose(fp);
    return 0;
}