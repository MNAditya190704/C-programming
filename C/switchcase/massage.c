#include <stdio.h>
int main (void)
{
    int m;
    printf( "type number for the massage required \n 1. head massage \n 2. neck massage \n 3. back massage \n 4. thigh massage \n 5. leg massage \n 6. full body massage \n7. tuk tuk massage");
    scanf("%d",&m);
    switch (m)
    {
        case 1:
        printf("cost is 3000");
        break;
        case 2:
        printf("cost is 4000");
        break;
        case 3:
        printf("cost is 5000");
        break;
        case 4:
        printf("cost is 6000");
        break;
        case 5:
        printf("cost is 7000");
        break;
        case 6:
        printf("cost is 8000");
        break;
        case 7:
        printf("cost is 1000");
        break;
        default:
        printf("invalid input");
        break;
    }
    return 0;
}