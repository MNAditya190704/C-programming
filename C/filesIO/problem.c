#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char ch;

    // Open source file for reading
    src = fopen("new.txt", "r");
    if (src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open destination file for writing
    dest = fopen("text.txt", "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return 1;
    }

    // Copy contents character by character
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);

    return 0;
}
