#include<stdio.h>
#include<unistd.h>
int main()
{
    int i, j, k;
    for(i=1; i<=100; i++)
    {
        printf("\rloading[");
        for(j=1; j<=100; j++)
        {
            j<=i ? putchar('=') : putchar (' ');
        }
        printf("]%3d%%", i);
        fflush(stdout);
        //usleep(50000);
        for(k=0xffffff; k--;);
    }
    printf("\n finished\n");

}