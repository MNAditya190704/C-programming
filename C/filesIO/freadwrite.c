#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num1, num2, num3, num4;
    FILE *fp;
    fp=fopen("text.txt", "w+");
    if(fp==NULL)
    {
        perror("ERROR");
        return 1;
    }
    printf("give 2 numbers");
    scanf("%d %d", &num1, &num2);
    fwrite(&num1, sizeof(num1), 1, fp);
    fwrite(&num2, sizeof(num2), 1, fp);
    rewind(fp);
    fread(&num3, sizeof(num3), 1, fp);
    fread(&num4, sizeof(num4), 1, fp);
    printf("%d %d", num3, num4);
    fclose(fp);
    return 0;
}