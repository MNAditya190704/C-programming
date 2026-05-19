#include<stdio.h>
void circle(float r);
int main()
{
    float a;
    printf("give radius of circle");
    scanf("%f", &a);
    circle (a);
}
void circle(float r)
{
    printf("%f", (3.142857*r*r));
}