#include "apc.h"

static int check_operand(char *str)
{
    int mn = 0;

    if (str[0] == '+' || str[0] == '-')
        mn = 1;

    if (str[mn] == '\0')
        return FAILURE;

    for (; str[mn]; mn++)
    {
        if (str[mn] < '0' || str[mn] > '9')
            return FAILURE;
    }

    return SUCCESS;
}

int cla_validation(int argc, char *argv[])/*Checks whether:

Correct number of arguments are given.
Operands contain only digits and optional signs.
Operator is valid.*/
{
    if (argc != 4)
        return FAILURE;

    if (check_operand(argv[1]) == FAILURE)
        return FAILURE;

    if (check_operand(argv[3]) == FAILURE)
        return FAILURE;

    char adi = argv[2][0];

    if (adi != '+' &&
        adi != '-' &&
        adi != 'x' &&
        adi != 'X' &&
        adi != '/')
        return FAILURE;

    return SUCCESS;
}

void create_list(char *opr, node **head, node **tail)//Converts the input string into a doubly linked list.
{
    int mn = 0;

    if (opr[0] == '+' || opr[0] == '-')
        mn = 1;

    for (; opr[mn]; mn++)
    {
        insert_last(head, tail, opr[mn] - '0');
    }
}

int insert_first(node **head, node **tail, int data)//Inserts a digit at the beginning of a list
{
    node *adi = malloc(sizeof(node));

    if (adi == NULL)
        return FAILURE;

    adi->data = data;
    adi->prev = NULL;
    adi->next = *head;

    if (*head)
        (*head)->prev = adi;
    else
        *tail = adi;

    *head = adi;

    return SUCCESS;
}

int insert_last(node **head, node **tail, int data)//Inserts a digit at the end of a list.
{
    node *adi = malloc(sizeof(node));

    if (adi == NULL)
        return FAILURE;

    adi->data = data;
    adi->next = NULL;
    adi->prev = *tail;

    if (*tail)
        (*tail)->next = adi;
    else
        *head = adi;

    *tail = adi;

    return SUCCESS;
}

int delete_list(node **head, node **tail)//Frees all nodes.
{
    node *mn;

    while (*head)
    {
        mn = *head;
        *head = (*head)->next;
        free(mn);
    }

    *tail = NULL;

    return SUCCESS;
}

void print_list(node *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}

int list_len(node *head)
{
    int mn = 0;

    while (head)
    {
        mn++;
        head = head->next;
    }

    return mn;
}

void remove_pre_zeros(node **head)//Removes leading zeros.
{
    while (*head &&
           (*head)->data == 0 &&
           (*head)->next)
    {
        node *adi = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(adi);
    }
}

int compare_list(node *head1, node *head2)//Compares two numbers.
{
    int mn = list_len(head1);
    int adi = list_len(head2);

    if (mn > adi)
        return OPERAND1;

    if (adi > mn)
        return OPERAND2;

    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return OPERAND1;

        if (head2->data > head1->data)
            return OPERAND2;

        head1 = head1->next;
        head2 = head2->next;
    }

    return SAME;
}