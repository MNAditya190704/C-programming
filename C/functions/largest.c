#include<stdio.h>
void compare(int a, int b, int c)
{
    (a>b&&a>c)?printf("%d is larger",a):(b>a&&b>c)?printf("%d is larger",b):printf("%d is larger",c);
}
int main()
{
    int m, n, o;
    printf("give 3 numbers");
    scanf("%d %d %d", &m, &n, &o);
    compare(m, n, o);
}