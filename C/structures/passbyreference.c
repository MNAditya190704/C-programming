#include<stdio.h>
struct student
{
    int id;
    char name[30];
    char address[150];
};
void read_data(struct student s[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("Enter id, name, address for student %d:\n", i+1);
        scanf("%d", &s[i].id);
        scanf("%s", s[i].name);
        scanf("%s", s[i].address);
    }
}
void print_data(struct student s[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("id: %d\n", s[i].id);
        printf("name: %s\n", s[i].name);
        printf("address: %s\n\n", s[i].address);
    }
}
int main()
{
    struct student s[5];
    printf("give 5 elements \n");
    read_data(s, 5);
    print_data(s, 5);
    return 0;
}