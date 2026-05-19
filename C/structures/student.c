#include<stdio.h>

struct student
{
    int id;
    char name[30];
    char address[150];
};
void data(struct student s)
{
s.id=10;
}
int main()
{
    struct student s1;
    data(&s1);
    printf("%d \n", s1.id);
    return 0;
}