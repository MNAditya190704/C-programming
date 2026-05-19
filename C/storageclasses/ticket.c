#include<stdio.h>
// int book_ticket()
// {
//     static int ticket_sold=0;
//     ticket_sold++;
//     return ticket_sold;
// }
// int main()
// {
//     int count;
//     count=book_ticket();
//     count=book_ticket();
//     printf("%d", count);
// }
int main()
{
    static int i=5;
    if(--i)
    {
        return main();
    }
    printf("%d", i);
}