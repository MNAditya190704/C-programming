#include <stdio.h>
int main() 
{
    int battery;
    printf("Enter mobile battery percentage: ");
    scanf("%d", &battery);
    if (battery <= 20) 
    {
        printf("Battery Low! Please charge your mobile.\n");
    } 
    else 
    {
        printf("Battery level is sufficient.\n");
    }
    return 0;
}