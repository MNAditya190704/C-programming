#include "mp3_header.h"// Includes structure definitions, prototypes, and required libraries
void edit(struct MP3 *mp3)// Function to edit a specific ID3 tag in an MP3 file
{
    FILE *src, *dest; // src → original file pointer, dest → temporary output file
    char frame[5];// Buffer to store 4-byte frame ID + null terminator
    int size;// Stores size of current ID3 frame
    char ch;// Temporary variable for byte-wise copy
    char tag[5];// Stores target frame ID (e.g., "TIT2")
    if (!strcmp(mp3->edit_option, "-t")) strcpy(tag, "TIT2"); // Map CLI option to frame
    else if (!strcmp(mp3->edit_option, "-a")) strcpy(tag, "TPE1");
    else if (!strcmp(mp3->edit_option, "-A")) strcpy(tag, "TALB");
    else if (!strcmp(mp3->edit_option, "-y")) strcpy(tag, "TYER");
    else if (!strcmp(mp3->edit_option, "-m")) strcpy(tag, "TCON");
    else if (!strcmp(mp3->edit_option, "-c")) strcpy(tag, "COMM");
    else
    {
        printf("Invalid edit option\n");// Invalid CLI argument
        return; // Exit function early
    }
    src = fopen(mp3->mp3_filename, "rb");// Open original MP3 file in binary read mode
    dest = fopen("temp.mp3", "wb");// Create a temporary file to write modified data
    if (!src || !dest)// Check if file opening failed
    {
        printf("File open error\n");
        return;
    }
    for (int i = 0; i < 10; i++)// Copy ID3 header
    {
        fread(&ch, 1, 1, src);// Read 1 byte from source
        fwrite(&ch, 1, 1, dest); // Write same byte to destination
    }
    while (1)// Process all ID3 frames sequentially
    {
        if (fread(frame, 1, 4, src) != 4)// Read 4-byte frame identifier (e.g., "TIT2", "TPE1")
            break;
        frame[4] = '\0';// Convert to C string for comparison
        fread(&size, 4, 1, src);// Read 4-byte frame size (stored in big-endian format)
        toggle_endianess(mp3, &size);// correct endian handling
        if (size <= 0)// If size is invalid, stop processing
            break;
        char flags[2]; // Frame flags (2 bytes)
        fread(flags, 1, 2, src);// Read flags from source
        fwrite(frame, 1, 4, dest);// Write frame ID to destination file
        if (strcmp(frame, tag) == 0)// Check if this is the target tag to modify
        {
            int new_size = strlen(mp3->new_text) + 1;// Compute new data size (+1 for encoding byte)
            int temp = new_size;
            toggle_endianess(mp3, &temp);// Convert new size to big-endian before writing
            fwrite(&temp, 4, 1, dest);// Write updated size
            fwrite(flags, 1, 2, dest); // Preserve original flags
            ch = 0; // encoding
            fwrite(&ch, 1, 1, dest);
            fwrite(mp3->new_text, 1, new_size - 1, dest); // Write new tag text
            fseek(src, size, SEEK_CUR);// correct skipping
        }
        else
        {
            int temp = size;// If not target frame → copy frame as-is
            toggle_endianess(mp3, &temp);// Convert size back to big-endian for writing
            fwrite(&temp, 4, 1, dest); // Copy frame data byte-by-byte
            fwrite(flags, 1, 2, dest);
            for (int i = 0; i < size; i++)
            {
                fread(&ch, 1, 1, src);
                fwrite(&ch, 1, 1, dest);
            }
        }
    }
    while (fread(&ch, 1, 1, src))// Copy remaining part of file (audio data after ID3 tags)
    {
        fwrite(&ch, 1, 1, dest);
    }
    fclose(src);// Close both files
    fclose(dest);
    remove(mp3->mp3_filename);// Delete original file
    rename("temp.mp3", mp3->mp3_filename);
    printf("Tag updated successfully!\n");
}