/*Algorithm:

Multiply one digit at a time.
Generate partial products.
Add partial products.

Time Complexity:

O(nm)*/
#include "apc.h"

void multiplication(node *tail1,
                    node *tail2,
                    node **headR,
                    node **tailR)
{
    node *mn2 = tail2;
    int ayt = 0;

    insert_first(headR, tailR, 0);

    while (mn2)
    {
        node *nm = tail1;

        node *headT = NULL;
        node *tailT = NULL;

        int mn = 0;

        while (nm)
        {
            int adi = nm->data * mn2->data + mn;

            insert_first(&headT,
                         &tailT,
                         adi % 10);

            mn = adi / 10;
            nm = nm->prev;
        }

        if (mn)
            insert_first(&headT,
                         &tailT,
                         mn);

        int ida;
        for (ida = 0; ida < ayt; ida++)
            insert_last(&headT, &tailT, 0);

        node *headNew = NULL;
        node *tailNew = NULL;

        addition(tailT,
                 *tailR,
                 &headNew,
                 &tailNew);

        delete_list(headR, tailR);

        *headR = headNew;
        *tailR = tailNew;

        ayt++;
        mn2 = mn2->prev;
    }

    remove_pre_zeros(headR);
}