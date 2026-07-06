/*Algorithm:

Start from both tails.
Add digits.
Add carry.
Store result.
Move left.

Time Complexity:

O(max(n,m))*/
#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int mn = 0;
    int adi;
    int ida;

    while (tail1 || tail2 || mn)
    {
        adi = mn;

        if (tail1)
        {
            adi += tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2)
        {
            adi += tail2->data;
            tail2 = tail2->prev;
        }

        ida = adi % 10;
        mn = adi / 10;

        insert_first(headR, tailR, ida);
    }
}