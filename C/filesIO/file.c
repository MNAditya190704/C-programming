#include <stdio.h>
#include <stdlib.h>

int main() {
    char source_name[100], dest_name[100];
    FILE *source_ptr, *dest_ptr;
    unsigned char buffer[100000000]; // 4KB buffer for efficient copying
    size_t bytes_read;

    // 1. Get filenames from the user
    printf("Enter source image filename (e.g., input.jpg): ");
    scanf("%s", source_name);
    printf("Enter destination image filename (e.g., copy.jpg): ");
    scanf("%s", dest_name);

    // 2. Open source file in Binary Read mode ("rb")
    source_ptr = fopen(source_name, "rb");
    if (source_ptr == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // 3. Open/Create destination file in Binary Write mode ("wb")
    dest_ptr = fopen(dest_name, "wb");
    if (dest_ptr == NULL) {
        perror("Error creating destination file");
        fclose(source_ptr);
        return 1;
    }

    // 4. Copy data block by block using fread and fwrite
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_ptr)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_ptr);
    }

    printf("Image copied successfully to %s\n", dest_name);

    // 5. Clean up
    fclose(source_ptr);
    fclose(dest_ptr);

    return 0;
}
