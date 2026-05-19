#include <stdio.h>
#include<stdlib.h>
int main()
{
 FILE *fptr;
 char ch;
 fptr = fopen("new.txt", "w");
 ch = fgetc(fptr);/* This should fail since reading a file in write mode*/
 if (ferror(fptr))
 fprintf(stderr, "error in reading from file : new.txt \n");
 clearerr(fptr);
 /* This loop should be false since we cleared the error indicator */
 if (ferror(fptr))
 fprintf(stderr, "error in reading from file : new.txt \n");
 fclose(fptr);
return 0;
}