//M N Aditya
//25048_015
// start time 20/04/2026 15:00
// take number and number of times to be shifted from user. left shift accordingly and if msb is 1 lsb should be 1 and if msb 0 lsb is 0.
// then print number in the form of binary
#include<stdio.h>
int circular(unsigned int num, unsigned int n)
{
    unsigned int i;
    for(i=0; i<n; i++)
    {
        int msb=(num&(1<<31));
        num=(num<<1);
        if(msb)
        {
            num= num|1;
        }
    }
    return num;
}
void print(unsigned int num, unsigned n)
{
    int a=circular(num, n);
    printf("Result in Binary:");
        for(int i=31; i>=0; i--)
        {
            printf(" %u", (a>>i)&1);
        }
}
int main()
{
    unsigned int num, n, a;
    int i;
    printf("Enter the num: \n");
    scanf("%u %u", &num, &n);
    print;
}