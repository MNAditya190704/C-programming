#include <stdio.h>

int main(void)
{
    int q, a, k, w; 
    char l;
    printf("this mall has 5 floors \n");
    printf("type 1 to 5 for information for each floor \n");
    scanf("%d", &q);

    switch(q)
    {
        case 1:
            printf("this floor has \n 1. H&M \n 2. zara \n 3. lifestyle \n 4. manyavar \n");
            printf("type 1 to 4 for information on each shop \n");
            scanf("%d", &w);
            switch(w)
            {
                case 1:
                    printf("h&m is in the northwest side of the mall");
                    break;
                case 2:
                    printf("zara is in the northeast side of the mall");
                    break;
                case 3:
                    printf("lifestyle is in the southwest side of the mall");
                    break;
                case 4:
                    printf("manyavar is in the southeast side of the mall");
                    break;
                default:
                    printf("invalid input");
                    break;
            }
            break;

        case 2:
            printf("ths floor has \n 1.samsung \n 2.oneplus \n 3.apple \n 4.lenovo \n");
            printf("type 1 to 4 for the required shop \n");
            scanf("%d", &w);
            switch(w)
            {
                case 1:
                    printf("samsung is in the northwest side of the mall");
                    break;
                case 2:
                    printf("oneplus is in the northeast side of the mall");
                    break;
                case 3:
                    printf("apple is in the southwest side of the mall");
                    break;
                case 4:
                    printf("lenovo is in the southeast side of the mall");
                    break;
                default:
                    printf("invalid input");
                    break;
            }
            break;

        case 3:
            printf("this floor has 4 theatres \n 1.mollywood \n 2.tollywood \n 3.sandalwood \n 4.bollywood \n");
            printf("which language do you want to watch movies in (m, t, s, b) \n");
            scanf(" %c", &l);
            switch(l)
            {
                case 'm':
                    printf("mollywood movies will be shown in screen1");
                    break;
                case 't':
                    printf("tollywood movies will be shown in screen2");
                    break;
                case 's':
                    printf("sandalwood movies will be shown in screen3");
                    break;
                case 'b':
                    printf("bollywood movies will be shown in screen4");
                    break;
            }
            break;

        case 4:
            printf("this floor has arcade games.give the number of adults and kids playing arcade games today: ");
            scanf("%d %d", &a, &k);
            printf("the total cost will be %d", (1000 * a) + (500 * k));
            break;

        case 5:
            printf("this is the food court. take food pass \n");
            scanf("%d", &a);
            printf("the total is %d \n", a * 500);
            printf("which restaurant would you like to visit \n indian (i) \n chinese (c) \n japanese (j) \n thai (t)\n");
            scanf(" %c", &l);
            switch(l)
            {
                case 'i':
                    printf("indian retaurant is in the northwest side of the mall");
                    break;
                case 'c':
                    printf("chinese resaturant is in the northeast side of the mall");
                    break;
                case 'j':
                    printf("japanese resatrant is in the southwest side of the mall");
                    break;
                case 't':
                    printf("thai restaurantis in the southeast side of the mall");
                    break;
                default:
                    printf("invalid input");
                    break;
            }
            break;

        default:
            printf("invalid input");
            break;
    }
    return 0;
}