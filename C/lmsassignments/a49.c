#include <stdio.h>
#define SIZEOF(x) ((char *)(&x + 1) - (char *)(&x))
int main() 
{
    int i;
    char c;
    float f;
    double d;
    unsigned int ui;
    long int li;
    printf("Size of int : %ld bytes\n", SIZEOF(i));
    printf("Size of char : %ld bytes\n", SIZEOF(c));
    printf("Size of float : %ld bytes\n", SIZEOF(f));
    printf("Size of double : %ld bytes\n", SIZEOF(d));
    printf("Size of unsigned int : %ld bytes\n", SIZEOF(ui));
    printf("Size of long int : %ld bytes\n", SIZEOF(li));
    return 0;
}