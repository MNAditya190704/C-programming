#include <stdio.h>

void endian(void *num, int size) 
{
    unsigned char *cptr = (unsigned char *)num; // Point to the start of the data
    unsigned char temp;
    
    for (int i = 0; i < (size / 2); i++) {
        temp = cptr[i];
        cptr[i] = cptr[size - 1 - i]; // Correct indexing
        cptr[size - 1 - i] = temp;
    }

    if (size == 2) {
        printf("Result: %04hx\n", *(unsigned short *)num);
    } else {
        printf("Result: %08x\n", *(unsigned int *)num);
    }
}

int main() 
{
    int size;
    unsigned int num = 0; // Initialize to avoid garbage values

    printf("Give size as 2 or 4: ");
    scanf("%d", &size);

    if (size == 2) {
        printf("Give hex number (e.g., AABB): ");
        scanf("%hx", (unsigned short *)&num);
    } else {
        printf("Give hex number (e.g., AABBCCDD): ");
        scanf("%x", &num);
    }

    endian(&num, size);
    return 0;
}
