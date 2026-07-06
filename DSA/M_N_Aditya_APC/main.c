/*M N Aditya
25048_015
start date 19/06/2026
Perform arithmetic operations on integers of any length, overcoming the limitations of built-in C data types such as int, long, and long long.
The program stores each digit separately in a doubly linked list and performs arithmetic digit by digit, similar to manual calculations.

Program flowchart:
main()
│
├── cla_validation()
│
├── create_list()
│
├── remove_pre_zeros()
│
│
├── if '+'
│       └── addition()
│
├── if '-'
│       └── subtraction()
│
├── if 'x'
│       └── multiplication()
│              └── addition()
│
└── if '/'
        └── division()
               └── subtraction()
*/
#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL;
    node *tail1 = NULL;
    node *head2 = NULL;
    node *tail2 = NULL;
    node *headR = NULL;
    node *tailR = NULL;

    /*Checks whether:
        Correct number of arguments are given.
        Operands contain only digits and optional signs.
        Operator is valid.*/
    if (cla_validation(argc, argv) == FAILURE)
    {
        printf("Invalid arguments\n");
        return 0;
    }

    int sign1 = 1;
    int sign2 = 1;

    if (argv[1][0] == '-')
        sign1 = -1;

    if (argv[3][0] == '-')
        sign2 = -1;

    //Converts the input string into a doubly linked list.
    create_list(argv[1], &head1, &tail1);

    create_list(argv[3], &head2, &tail2);

    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    char oper = argv[2][0];

    switch (oper)
    {
        case '+':
        {
            if (sign1 == sign2)
            {
                addition(tail1, tail2, &headR, &tailR);

                if (sign1 == -1 && !(headR->data == 0 && headR->next == NULL))
                    printf("-");
            }
            else
            {
                int mn = compare_list(head1, head2);//Compares two numbers.

                if (mn == SAME)
                {
                    insert_first(&headR, &tailR, 0);//Inserts a digit at the beginning of a list.
                }
                else if (mn == OPERAND1)
                {
                    subtraction(tail1, tail2, &headR, &tailR);

                    if (sign1 == -1)
                        printf("-");
                }
                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);

                    if (sign2 == -1)
                        printf("-");
                }
            }
            break;
        }

        case '-':
        {
            if (sign1 != sign2)
            {
                addition(tail1, tail2, &headR, &tailR);

                if (sign1 == -1 && !(headR->data == 0 && headR->next == NULL))
                    printf("-");
            }
            else
            {
                int mn = compare_list(head1, head2);

                if (mn == SAME)
                {
                    insert_first(&headR, &tailR, 0);
                }
                else if (mn == OPERAND1)
                {
                    subtraction(tail1, tail2, &headR, &tailR);

                    if (sign1 == -1)
                        printf("-");
                }
                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);

                    if (sign1 == 1)
                        printf("-");
                }
            }
            break;
        }

        case 'x':
        case 'X':
        {
            multiplication(tail1, tail2, &headR, &tailR);

            if ((sign1 * sign2) < 0 && !(headR->data == 0 && headR->next == NULL))
                printf("-");

            break;
        }

        case '/':
        {
            if (head2->data == 0 &&
                head2->next == NULL)
            {
                printf("ERROR: Division by zero\n");
                return 0;
            }

            division(head1, head2, &headR, &tailR);

            if ((sign1 * sign2) < 0 && !(headR->data == 0 && headR->next == NULL))
                printf("-");

            break;
        }
    }

    print_list(headR);//print all nodes

    delete_list(&head1, &tail1);//Frees all nodes.
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return 0;
}