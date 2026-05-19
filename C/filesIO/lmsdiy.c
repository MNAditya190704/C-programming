#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num1, num2;
    float num3;
    char str[10], oper, ch;
    FILE *fp;
    
    if((fp=fopen("text.txt", "w+"))==NULL)
    {
        perror("ERROR");
        return 1;
    }
    fprintf(fp, "%d %c %d %s %f \n", 2,'+', 1, "is", 1.1);
    rewind(fp);
    fscanf(fp, "%d %c %d %s %f", &num1, &oper, &num2, str, &num3);
    printf("%d %c %d %s %f \n", num1, oper, num2, str, num3);
    fclose(fp);
    return 0;
}