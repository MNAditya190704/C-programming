#include <stdio.h>   // standard input 
#include <string.h>  // for strings
#include "decode.h"  // user defined header for function declaration
#include "types.h"   // user defined header for preventing errors during compilation process
#include "common.h"  // user defined header file to set up guard rails
/* This function checks whether the decoding arguments entered by the user are valid.
   Checks whether the stego image contains ".bmp".
   Stores the stego image name in DecodeInfo structure.
   Checks whether output file name is provided.
   If not provided, default name "output" is used.
   Decoding can only be performed on BMP images because the hidden data is stored inside BMP pixel bytes.*/
Status validate_decode_args(int argc, char *argv[], DecodeInfo *adi)
{
    /* Validate stego image file */
    if(strstr(argv[2], ".bmp") != NULL)
    {
        adi->stego_image_fname = argv[2];
    }
    else
    {
        return failure;
    }
    /* Output file name */
    if(argc == 4)
    {
        strcpy(adi->output_fname, argv[3]);
    }
    else
    {
        strcpy(adi->output_fname, "output");
    }
    return success;
}
/* This is the main decoding controller function. It performs all decoding steps in the correct sequence.
   Opens the stego image file.
   Skips the 54-byte BMP header.
   Decodes and verifies the magic string.
   Decodes secret file extension.
   Creates output file with correct extension.
   Decodes secret file data.
   Closes all opened files.
   This function manages the complete extraction process and recreates the original hidden file.*/
Status do_decoding(char *argv[], DecodeInfo *adi)
{
    if (open_decode_files(adi) == failure)
    {
        printf("Unable to open files\n");
        return failure;
    }
    printf("file is opened successfully\n");
    /* Skip BMP header */
    fseek(adi->fptr_stego_image, 54, SEEK_SET);
    if (decode_magic_string(adi) == failure)
    {
        printf("Magic string mismatch\n");
        return failure;
    }
    printf("Magic string is decoded successfully\n");
    if (decode_secret_file_extn(adi) == failure)
    {
        printf("Failed to decode extension\n");
        return failure;
    }
    printf("Extension is decoded successfully\n");
    /* Append extension to output file */
    strcat(adi->output_fname, adi->secret_extn);
    adi->fptr_output = fopen(adi->output_fname, "wb");
    if (adi->fptr_output == NULL)
    {
        printf("Unable to create output file\n");
        return failure;
    }
    if (decode_secret_file_data(adi) == failure)
    {
        printf("Failed to decode secret data\n");
        return failure;
    }
    printf("Secret data decoded successfully\n");
    /* CLOSE FILES */
    fclose(adi->fptr_stego_image);
    fclose(adi->fptr_output);
    return success;
}
/* This function opens the stego BMP image required for decoding.
   Opens the stego image in read mode.
   Checks whether file opened successfully.
   Returns failure if file opening fails.
   The decoder must access image bytes in order to extract hidden secret information.*/
Status open_decode_files(DecodeInfo *adi)
{
    adi->fptr_stego_image = fopen(adi->stego_image_fname, "r");
    if (adi->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "Unable to open file %s\n", adi->stego_image_fname);
        return failure;
    }
    return success;
}
/* This function extracts and verifies the hidden magic string.
   Reads 8 image bytes for each character.
   Extracts one character from LSBs.
   Reconstructs the hidden magic string.
   Compares extracted string with original MAGIC_STRING.
   The magic string confirms that the image actually contains encoded secret data.*/
Status decode_magic_string(DecodeInfo *adi)
{
    char tya[8];
    char mn[3];
    for (int ida = 0; ida < strlen(MAGIC_STRING); ida++)
    {
        fread(tya, 8, 1, adi->fptr_stego_image);

        mn[ida] = decode_1byte_from_lsb(tya);
    }
    mn[strlen(MAGIC_STRING)] = '\0';
    if (strcmp(mn, MAGIC_STRING) == 0)
    {
        return success;
    }
    return failure;
}/*This function extracts the hidden secret file extension.
   Reads 32 bytes from image.
   Decodes extension size from LSBs.
   Reads extension characters one by one.
   Reconstructs the extension string.
   The extension helps recreate the original file type
   correctly during decoding. */
Status decode_secret_file_extn(DecodeInfo *adi)
{
    char ayt[32];
    fread(ayt, 32, 1, adi->fptr_stego_image);
    adi->extn_size = decode_4bytes_from_lsb(ayt);
    for (int ida = 0; ida < adi->extn_size; ida++)
    {
        char tya[8];
        fread(tya, 8, 1, adi->fptr_stego_image);
        adi->secret_extn[ida] = decode_1byte_from_lsb(tya);
    }
    adi->secret_extn[adi->extn_size] = '\0';
    return success;
}
/* This function extracts the actual hidden secret file data.
   Reads 32 image bytes to decode file size.
   Reads encoded image bytes repeatedly.
   Extracts one character from every 8 bytes.
   Writes extracted characters into output file.
   This is the main step where the hidden message is recovered from the stego image.*/
Status decode_secret_file_data(DecodeInfo *adi)
{
    char ayt[32];
    fread(ayt, 32, 1, adi->fptr_stego_image);
    adi->secret_file_size = decode_4bytes_from_lsb(ayt);
    for (long ida = 0; ida < adi->secret_file_size; ida++)
    {
        char tya[8];
        fread(tya, 8, 1, adi->fptr_stego_image);
        char mn = decode_1byte_from_lsb(tya);
        fwrite(&mn, 1, 1, adi->fptr_output);
    }
    return success;
}
/* This function extracts 1 hidden byte from 8 image bytes.
   Reads LSB from each image byte.
   Shifts bits left one by one.
   Combines extracted bits to form original character.
   During encoding, each secret character is stored inside
   8 image bytes using LSB technique.*/
char decode_1byte_from_lsb(char *tya)
{
    char mn = 0;
    for (int ida = 0; ida < 8; ida++)
    {
        mn = mn << 1;
        mn = mn | (tya[ida] & 1);
    }
    return mn;
}
/* This function extracts a 4-byte integer from 32 image bytes.
   Reads LSB from 32 image bytes.
   Shifts bits left repeatedly.
   Reconstructs the original integer value.
   File size and extension size are stored as integers during encoding and must be decoded correctly.*/
int decode_4bytes_from_lsb(char *ayt)
{
    int ida = 0;
    for (int mn = 0; mn < 32; mn++)
    {
        ida = ida << 1;
        ida = ida | (ayt[mn] & 1);
    }
    return ida;
}