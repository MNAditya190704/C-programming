#include <stdio.h>// standard input output header file
#include "lexer.h"// user defined header file defining required functions
int main(int argc,char *argv[])//argument count and argument vector pointer created and initialized
{
    if(argc != 2)// requires 2 command line arguments: name of exwcutabe program and name of c file to be analyzed
    {
        printf("Usage: %s file.c\n",argv[0]);// error message to tell user how to run program
        return 1;
    }
    lexical_analyze(argv[1]);// call function with target file name string
    return 0;
}