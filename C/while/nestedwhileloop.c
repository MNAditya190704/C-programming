#include<stdio.h>
int main()
{
    int i, j,n=3;
    char ch='a';
    for(i=0; i<=3; i++)
    {
        ch='a'+i;
        for(j=0; j<=3; j++)
        {
            if(j<=n/2)
            {
                printf("%c", ch);
                ch++;
            }
            else
            {
                ch--;
                printf("%c",ch);
            }
        }
        printf("\n");
    }
}