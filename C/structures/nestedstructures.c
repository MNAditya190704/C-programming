#include<stdio.h>
struct college
{
    struct student
    {
        int id;
        char name[20];
        char address[60];
    }s1;
    struct faculty
    {
        int id;
        char name[20];
        char address[60];
    }f1;
};
int main()
{
    struct college member;
    member.s1.id=10;
    member.f1.id=20;
    printf("%d \n", member.s1.id);
    printf("%d \n", member.f1.id);
    printf("%zu \n", sizeof(struct college));
    printf("%zu \n", sizeof(struct student));
    return 0;
}