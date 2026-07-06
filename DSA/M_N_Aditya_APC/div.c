/*Algorithm:

Bring down digits one by one.
Repeatedly subtract divisor.
Count subtractions.
Store quotient digit.

Time Complexity:

O(n²)*/
#include "apc.h"

void division(node *head1,
              node *head2,
              node **headR,
              node **tailR)
{
    node *tail2 = head2;

    while (tail2->next)
        tail2 = tail2->next;

    if (compare_list(head1, head2) == OPERAND2)
    {
        insert_first(headR, tailR, 0);
        return;
    }

    node *headT = NULL;
    node *tailT = NULL;

    while (head1)
    {
        insert_last(&headT,
                    &tailT,
                    head1->data);

        remove_pre_zeros(&headT);

        int mn = 0;

        while (compare_list(headT, head2) != OPERAND2)
        {
            node *headX = NULL;
            node *tailX = NULL;

            subtraction(tailT,
                         tail2,
                         &headX,
                         &tailX);

            delete_list(&headT, &tailT);

            headT = headX;
            tailT = tailX;

            mn++;
        }

        insert_last(headR,
                    tailR,
                    mn);

        head1 = head1->next;
    }

    remove_pre_zeros(headR);

    delete_list(&headT, &tailT);
}