#include<stdio.h>
int main()
{
    FILE *fp;
    //fp=fopen("new.txt", "r");
    //fp=fopen("new.txt", "w");
    fp=fopen("new.txt", "a");
    if(fp==NULL)
    {
        //printf("file ot present, failure \n");
        perror("error");
        return -1;
    }
    fclose(fp);
    return 0;
}