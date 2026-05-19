// #include<stdio.h>
// int main(int argc, char *argv[])
// {
//     printf("no. of argc : %d\n", argc);
//     printf(" \n list of argcs \n");
//     for(int i=0; i<argc; i++)
//     {
//         printf("%d. %s\n", i+1, argv[i]);
//     }
// }
// #include<stdio.h>
// int main(int argc, char *argv[])
// {
//     printf("no. of argc : %d\n", argc);
//     printf(" \n list of argcs \n");
//     for(int i=0; argv[i]; i++)
//     {
//         printf("%d. %s\n", i+1, argv[i]);
//     }
// }
// #include <stdio.h>

// int main(int argc, char *argv[], char *envp[]) {
//     int count = 0;

//     printf("Listing Environment Variables:\n");
//     printf("-----------------------------\n");

//     // envp is a NULL-terminated array of environment strings
//     for (char **env = envp; *env != NULL; env++) {
//         printf("[%d]: %s\n", count + 1, *env);
//         count++;
//     }

//     printf("Total number of environment variables found: %d\n", count);

//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
// int main(int argc, char *argv[])
// {
//     int i, sum=0;
//     float avg;
//     for(i=1; i<argc; i++)
//     {
//         sum+=atoi(argv[i]);
//     }
//     avg=(float)sum/(argc-1);
//     printf("%g", avg);
// }
int main(int arc, int *argv[], char *envp[])
{
    char *ptr;
    setenv("var1", "environmenta12345", 0);
    ptr=getenv("var1");
    if(ptr==NULL)
    {
        printf("found, %s", ptr);
    }
    else
    {
        printf("found, %s", ptr);
    }
}