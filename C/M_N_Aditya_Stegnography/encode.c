/*
main()
   ↓
check_operation()
   ↓
validate_encode_args()
   ↓
do_encoding()
   ↓
open_files()
check_capacity()
copy_bmp_header()
encode_magic_string()
encode_secret_file_extn()
encode_secret_file_data()
copy_remaining_img_data()

#include <stdio.h>      // fopen, fread, fwrite, fseek, printf etc

#include <string.h>     // strcmp, strlen, strstr etc

#include "encode.h"     // Contains EncodeInfo structure and function declarations

#include "types.h"      // Contains Status enum and operation enums

#include "common.h"     // Contains MAGIC_STRING
*/
#include <stdio.h>
#include<string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
/* This function checks the command-line option entered by the user.
If the input is -e, it returns encode; if it is -d, it returns decode.
If neither matches, it returns unsupported.*/
Opr_type check_operation(char *adi)
{
    if(strcmp(adi, "-e") == 0)
    {
        return encode;
    }
    else if(strcmp(adi, "-d") == 0)
    {
        return decode;
    }
    return unsupported;
}
/* This function checks whether the user has entered a valid BMP image file for encoding.
   It checks whether the source image name contains ".bmp".
   If yes, the file name is stored inside the EncodeInfo structure.
   If not, the function returns failure.
   If validation succeeds, success is returned.
   Encoding should only be done on BMP images because the program directly modifies pixel bytes using LSB steganography.*/
Status validate_encode_args(char *adi[], EncodeInfo *mn)
{
    /* Source image file */
    if(strstr(adi[2], ".bmp") != NULL)
    {
        mn->src_image_fname = adi[2];
    }
    else
    {
        return failure;
    }
    return success;
}
/* This is the main encoding controller function. It performs all encoding steps one after another.
   Opens all required files.
   Checks whether image has enough capacity.
   Copies BMP header to output image.
   Encodes the magic string.
   Encodes secret file extension.
   Encodes secret file data.
   Copies remaining image data.
   Closes all opened files.
   This function manages the complete encoding process in the correct sequence so the hidden data can later be decoded properly.*/
Status do_encoding(char *adi[], EncodeInfo *mn)
{
    if(open_files(mn) == failure)
    {
        printf("Unable to open files\n");
        return failure;
    }
    printf("Files opened successfully\n");
    if(check_capacity(mn) == failure)
    {
        printf("Insufficient image capacity\n");
        return failure;
    }
    printf("Capacity check passed\n");
    if(copy_bmp_header(mn) == failure)
    {
        printf("Failed to copy header\n");
        return failure;
    }
    printf("BMP header copied\n");
    if(encode_magic_string(MAGIC_STRING, mn) == failure)
    {
        printf("Failed to encode magic string\n");
        return failure;
    }
    printf("Magic string encoded\n");
    if(encode_secret_file_extn(mn) == failure)
    {
        printf("Failed to encode extension\n");
        return failure;
    }
    printf("Secret extension encoded\n");
    if(encode_secret_file_data(mn) == failure)
    {
        printf("Failed to encode file data\n");
        return failure;
    }
    printf("Secret data encoded\n");
    if(copy_remaining_img_data(mn) == failure)
    {
        printf("Failed to copy remaining data\n");
        return failure;
    }
    printf("Remaining image data copied\n");
     /* CLOSE FILES */
    fclose(mn->src_image_fptr);
    fclose(mn->secret_fptr);
    fclose(mn->output_image_fptr);
    return success;
}
/* This function opens all files required for encoding.
   Opens source BMP image in binary read mode.
   Opens secret file in binary read mode.
   Opens output stego image in binary write mode.
   Checks whether each file opened successfully.
   Returns failure if any file cannot be opened.
   BMP images contain raw binary data. Using text mode may corrupt image bytes during reading or writing.*/
Status open_files(EncodeInfo *mn)
{
    mn->src_image_fptr = fopen(mn->src_image_fname, "rb");
    if (mn->src_image_fptr == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", mn->src_image_fname);
        return failure;
    }
    mn->secret_fptr = fopen(mn->secret_fname, "rb");
    if (mn->secret_fptr == NULL)
    {
        perror("fopen");

        fprintf(stderr, "ERROR: Unable to open file %s\n", mn->secret_fname);

        return failure;
    }
    mn->output_image_fptr = fopen(mn->output_image_fname, "wb");
    if (mn->output_image_fptr == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", mn->output_image_fname);
        return failure;
    }
    return success;
}
/* This function checks whether the source image has enough space to store the secret data.
   Finds total image capacity.
   Finds secret file size.
   Finds extension size.
   Calculates total required bytes for encoding.
   Compares required capacity with available image capacity.
   If the image does not have enough space, encoding may corrupt the image or lose secret data. */
Status check_capacity(EncodeInfo *mn)
{
    unsigned int image_capacity;
    image_capacity = get_image_size_for_bmp(mn->src_image_fptr);
    mn->secret_file_size = get_file_size(mn->secret_fptr);
    char *extn = strrchr(mn->secret_fname, '.');
    if(extn == NULL)
    {
        return failure;
    }
    int extn_size = strlen(extn);
    int required_capacity = (strlen(MAGIC_STRING) * 8) + (4 * 8) + (extn_size * 8) + (4 * 8) + (mn->secret_file_size * 8) + 54;
    if(image_capacity > required_capacity)
    {
        return success;
    }
    return failure;
}
/* This function calculates the size of BMP image pixel data.
   Moves file pointer to width and height location in BMP header.
   Reads width and height values.
   Calculates image size using: width × height × 3 because each pixel uses 3 bytes (RGB).
   The program needs image capacity information before encoding data.*/
unsigned int get_image_size_for_bmp(FILE *tya)
{
    unsigned int mn, adi;
    fseek(tya, 18, SEEK_SET);
    fread(&mn, sizeof(int), 1, tya);
    printf("width = %u\n", mn);
    fread(&adi, sizeof(int), 1, tya);
    printf("height = %u\n", adi);
    return mn * adi * 3;
}
/* This function finds the total size of a file.
   Moves file pointer to end of file.
   Uses ftell() to get current position.
   Rewinds file pointer back to beginning.
   Returns file size.
   The encoder must know the secret file size before encoding it. */
unsigned int get_file_size(FILE *nm)
{
    fseek(nm, 0, SEEK_END);
    int ida = ftell(nm);
    rewind(nm);
    return ida;
}
/* This function copies the first 54 bytes of BMP header directly to the output image.
   Reads first 54 bytes from source image.
   Writes those bytes into output image unchanged.
   BMP header contains important image information such as size, resolution and color format. Modifying it may corrupt the image.*/
Status copy_bmp_header(EncodeInfo *mn)
{
    rewind(mn->src_image_fptr);
    char adi[54];
    fread(adi, 54, 1, mn->src_image_fptr);
    fwrite(adi, 54, 1, mn->output_image_fptr);
    return success;
}
/* This function hides a special identification string inside the image.
   Reads 8 bytes from image for each character.
   Encodes 1 character into LSBs of those 8 bytes.
   Writes modified bytes into output image.
   The magic string helps decoder identify whether the image actually contains hidden data.*/
Status encode_magic_string(const char *tya, EncodeInfo *mn)
{
    char adi[8];
    for(int ida = 0; tya[ida] != '\0'; ida++)
    {
        fread(adi, 8, 1, mn->src_image_fptr);
        encode_1byte_to_lsb(tya[ida], adi);
        fwrite(adi, 8, 1, mn->output_image_fptr);
    }
    return success;
}
/* This function encodes the secret file extension (.txt).
   Extracts extension from secret file name.
   Finds extension length.
   Encodes extension size into image.
   Encodes extension characters one by one.
   During decoding, the extension helps recreate the original file type correctly.*/
Status encode_secret_file_extn(EncodeInfo *mn)
{
    /* Extract extension */
    char *ext = strrchr(mn->secret_fname, '.');
    /* Check whether extension exists */
    if(ext == NULL)
    {
        return failure;
    }
    /* Validate extension */
    if(strcmp(ext, ".txt") != 0)
    {
        return failure;
    }
    /* Find extension size */
    int ext_size = strlen(ext);
    char buffer[32];
    /* Read 32 bytes from source image */
    if(fread(buffer, 32, 1, mn->src_image_fptr) != 1)
    {
        return failure;
    }
    /* Encode extension size */
    encode_4byte_to_lsb(ext_size, buffer);
    /* Write encoded data */
    if(fwrite(buffer, 32, 1, mn->output_image_fptr) != 1)
    {
        return failure;
    }
    char data[8];
    /* Encode extension characters */
    for(int i = 0; i < ext_size; i++)
    {
        if(fread(data, 8, 1, mn->src_image_fptr) != 1)
        {
            return failure;
        }
        encode_1byte_to_lsb(ext[i], data);
        if(fwrite(data, 8, 1, mn->output_image_fptr) != 1)
        {
            return failure;
        }
    }
    return success;
}
/* This function encodes the actual contents of the secret file.
   Encodes secret file size first.
   Reads secret file character by character.
   Encodes each character into 8 image bytes using LSB method.
   Writes modified bytes into output image.
   This is the main step where the hidden message is stored
   inside the BMP image.*/
Status encode_secret_file_data(EncodeInfo *mn)
{
    char adi[32];
    fread(adi, 32, 1, mn->src_image_fptr);
    encode_4byte_to_lsb(mn->secret_file_size, adi);
    fwrite(adi, 32, 1, mn->output_image_fptr);
    char ida;
    while(fread(&ida, 1, 1, mn->secret_fptr) > 0)
    {
        char ayt[8];

        fread(ayt, 8, 1, mn->src_image_fptr);

        encode_1byte_to_lsb(ida, ayt);

        fwrite(ayt, 8, 1, mn->output_image_fptr);
    }
    return success;
}
/* This function hides 1 byte of secret data inside 8 bytes of image data.
   Takes one bit from secret character.
   Replaces LSB of one image byte with that bit.
   Repeats for all 8 bits.
   Changing only the last bit causes very small color changes, making the modification invisible to human eyes.*/
Status encode_1byte_to_lsb(char adi, char *mn)
{
    for(int ida = 0; ida < 8; ida++)
    {
        mn[ida] = (mn[ida] & 0xFE) | ((adi >> (7 - ida)) & 1);
    }

    return success;
}
/* This function hides a 4-byte integer inside 32 image bytes.
   Takes integer bits one by one.
   Stores each bit inside LSB of image bytes.
   Uses 32 image bytes for 32 bits.
   File sizes and extension sizes are integers, so they must be encoded separately from normal characters.*/
Status encode_4byte_to_lsb(int adi, char *mn)
{
    for(int ida = 0; ida < 32; ida++)
    {
        mn[ida] = (mn[ida] & 0xFE) | ((adi >> (31 - ida)) & 1);
    }
    return success;
}
/* This function copies all remaining image data after encoding is completed.
   Reads remaining bytes from source image.
   Writes them directly into output image unchanged.
   Only a small portion of image data is modified for hiding data.
   The remaining image content must stay unchanged.*/
Status copy_remaining_img_data(EncodeInfo *mn)
{
    char adi;
    while(fread(&adi, 1, 1, mn->src_image_fptr) > 0)
    {
        fwrite(&adi, 1, 1, mn->output_image_fptr);
    }
    return success;
}
/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: success or failure, on file errors
 */