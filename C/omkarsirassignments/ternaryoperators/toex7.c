#include <stdio.h>
int main()
{
    int x, y;
    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);
    (x == 0 && y == 0) ? printf("Origin") :
    (x == 0) ? printf("Y-axis") :(y == 0) ? printf("X-axis") :(x > 0 && y > 0) ? printf("First Quadrant") :(x < 0 && y > 0) ? printf("Second Quadrant") :(x < 0 && y < 0) ? printf("Third Quadrant") :printf("Fourth Quadrant");
    return 0;
}