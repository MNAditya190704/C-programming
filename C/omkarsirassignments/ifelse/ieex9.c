#include <stdio.h>
int main() 
{
    int button;
    printf("Enter button status (1 = Pressed, 0 = Not Pressed): ");
    scanf("%d", &button);
    if (button == 1) 
    {
        printf("Button is pressed. LED is ON.\n");
    } 
    else 
    {
        printf("Button is not pressed. LED is OFF.\n");
    }
    return 0;
}