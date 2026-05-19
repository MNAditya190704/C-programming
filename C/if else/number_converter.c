#include <stdio.h>
int main (void)
{
    char adi, sam, d, h, o, b ;
    int z, x;
    printf ("give type of number d=decimal, h=hexadecimal, b=binary, o=octal:");
    scanf("%c",&sam);
    printf ("give the result number type d=decimal, b=binary, h=hexadecimal, o=octal:");
    scanf("%c",&adi);
    if (sam==d && adi==b)
    {printf("give number"); 
        scanf ("%d",&z); 
        printf("%b",z);}
    else if (sam==d && adi==h)
    {printf("give number"); 
        scanf ("%d",&z); 
        printf("%x",z);}
    else if (sam==d && adi==o)
    {printf("give number"); 
        scanf ("%d",&z); 
        printf("%o",z);}
    else if (sam==h && adi==d)
    {printf("give number"); 
        scanf ("%x",&z); 
        printf("%d",z);}
    else if (sam==h && adi==b)
    {printf("give number"); 
        scanf ("%x",&z); 
        printf("%b",z);}
    else if (sam==h && adi==o)
    {printf("give number"); 
        scanf ("%x",&z); 
        printf("%o",z);}
    else if (sam==b && adi==d)
    {printf("give number"); 
        scanf ("%b",&z); 
        printf("%d",z);}
    else if (sam==b && adi==h)
    {printf("give number"); 
        scanf ("%b",&z); 
        printf("%x",z);}
    else if (sam==b && adi==o)
    {printf("give number"); 
        scanf ("%b",&z); 
        printf("%o",z);}
    else if (sam==o && adi==d)
    {printf("give number"); 
        scanf ("%o",&z); 
        printf("%d",z);}
    else if (sam==o && adi==h)
    {printf("give number"); 
        scanf ("%o",&z); 
        printf("%x",z);}
    else if (sam==o && adi==b)
    {printf("give number"); 
        scanf ("%o",&z); 
        printf("%b",z);}
else {printf("not applicable");}
return 0;
}