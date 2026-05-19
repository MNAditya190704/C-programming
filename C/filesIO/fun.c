#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    /*int i;
    for(i=0; i<=100; i++)
    {
        printf(" \r loading [] %3d%%", i);
        fflush(stdout);
        sleep(1);
    }*/
   int ret;
   ret =printf("hello world \n");
   printf("previous printf printed %d chars \n ", ret);
   printf("%d %d\n", printf("emertxe\n"), printf("vikas\n"));
}