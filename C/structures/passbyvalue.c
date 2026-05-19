#include <stdio.h>

struct student {
    int id;
    char name[20];
    char address[40];
};

void modify(struct student *s) {
    s->id = 5;
}

int main() {
    struct student s = {1, "Name", "bengaluru"};
    printf("before modification : %d\n", s.id);

    modify(&s);
    printf("after modification : %d\n", s.id);

    return 0;
}