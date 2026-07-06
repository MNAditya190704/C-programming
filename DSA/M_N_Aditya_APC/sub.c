/*Algorithm:

Start from tails.
Subtract digits.
Borrow if necessary.
Store result.

Time Complexity:

O(max(n,m))*/
#include "apc.h"

void subtraction(node *tail1,
                 node *tail2,
                 node **headR,
                 node **tailR)
{
    int mn = 0;
    int adi;
    int ida;

    while (tail1)
    {
        adi = tail1->data - mn;

        if (tail2)
        {
            adi -= tail2->data;
            tail2 = tail2->prev;
        }

        if (adi < 0)
        {
            adi += 10;
            mn = 1;
        }
        else
        {
            mn = 0;
        }

        ida = adi;
        insert_first(headR, tailR, ida);

        tail1 = tail1->prev;
    }

    remove_pre_zeros(headR);
}