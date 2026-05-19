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
#include "encode.h"
#include "types.h"
#include "common.h"

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */

 /* Check operation */
Opr_type check_operation(char *option)
{
     // strcmp compares two strings
    // returns 0 if both strings are equal

    if(strcmp(option, "-e") == 0)
    {
        // user entered -e
        // means encoding operation
        return encode;
    }
    else if(strcmp(option, "-d") == 0)
    {
        // user entered -d
        // means decoding operation

        return decode;
    }

    return unsupported;
}

/* Read and validate encode args . Purpose:

Verify command line arguments
Store filenames into structure*/
Status validate_encode_args(char *argv[], EncodeInfo *encInfo)// parameters char *argv[]
{
    /* Source image file */
    if(strstr(argv[2], ".bmp") != NULL)// searches for substring. returns pointer to bmp. if null occurs(no file name) that is 1 argument and generated filename is another argument therefore 2
    {
        encInfo->src_image_fname = argv[2];// pointer to structure.contains all encoding. store image filename using pointer 
    }
    else
    {
        return failure;
    }
}

/* Perform encoding */
Status do_encoding(char *argv[], EncodeInfo *encInfo)
{
    if(open_files(encInfo) == failure)// open all files
    {
        printf("ERROR: Unable to open files\n");
        return failure;
    }

    printf("INFO: Files opened successfully\n");

    if(check_capacity(encInfo) == failure)// check whether image has enough bytes to store secret data
    {
        printf("ERROR: Insufficient image capacity\n");
        return failure;
    }

    printf("INFO: Capacity check passed\n");

    if(copy_bmp_header(encInfo) == failure)// bmp first 54 bytes are header. must copy exactly. else image becomes corrupted
    {
        printf("ERROR: Failed to copy header\n");
        return failure;
    }

    printf("INFO: BMP header copied\n");

    if(encode_magic_string(MAGIC_STRING, encInfo) == failure)// stores speacial identifier
    {
        printf("ERROR: Failed to encode magic string\n");
        return failure;
    }

    printf("INFO: Magic string encoded\n");

    if(encode_secret_file_extn(encInfo) == failure)//Stores extension
    {
        printf("ERROR: Failed to encode extension\n");
        return failure;
    }

    printf("INFO: Secret extension encoded\n");

    if(encode_secret_file_data(encInfo) == failure)//Stores actual secret file contents.
    {
        printf("ERROR: Failed to encode file data\n");
        return failure;
    }

    printf("INFO: Secret data encoded\n");

    if(copy_remaining_img_data(encInfo) == failure)//Copies leftover image bytes unchanged.
    {
        printf("ERROR: Failed to copy remaining data\n");
        return failure;
    }

    printf("INFO: Remaining image data copied\n");

    return success;
}

Status open_files(EncodeInfo *encInfo)
{
    encInfo->src_image_fptr = fopen(encInfo->src_image_fname, "r");

    if (encInfo->src_image_fptr == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return failure;
    }

    encInfo->secret_fptr = fopen(encInfo->secret_fname, "r");

    if (encInfo->secret_fptr == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return failure;
    }

    encInfo->output_image_fptr = fopen(encInfo->output_image_fname, "w");

    if (encInfo->output_image_fptr == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->output_image_fname);

    	return failure;
    }

    return success;
}

/* Check capacity */
Status check_capacity(EncodeInfo *encInfo)
{
    unsigned int image_capacity;

    image_capacity = get_image_size_for_bmp(encInfo->src_image_fptr);// gets total available image bytes

    encInfo->secret_file_size = get_file_size(encInfo->secret_fptr);// gets secret file size

    //each character needs 8 image bytes because 1 bit stored per image byte
    int required_size =
        (strlen(MAGIC_STRING) * 8) +
        (4 * 8) +// for storing integer sizes
        (4 * 8) +
        (encInfo->secret_file_size * 8) +
        54;

    if(image_capacity > required_size)
    {
        return success;
    }

    return failure;
}

/*get the size of image for bit mapping*/
unsigned int get_image_size_for_bmp(FILE *fptr_image)
{
    unsigned int width, height;
    // Move file pointer to byte 18.
    //BMP format stores width here.
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);//read width
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);// read height
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3; //bmp uses rgb. therefore 3 bytes per pixel
}

/* Get file size */
unsigned int get_file_size(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);

    int size = ftell(fptr);

    rewind(fptr);

    return size;
}

/* Copy bmp header */
Status copy_bmp_header(EncodeInfo *encInfo)
{
    rewind(encInfo->src_image_fptr);

    char buffer[54];// temporay array for bmp header

    fread(buffer, 54, 1, encInfo->src_image_fptr);// read header from source image

    fwrite(buffer, 54, 1, encInfo->output_image_fptr);// write header to output image

    return success;
}

/* Encode magic string */
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    char image_buffer[8]; // one character= 8 bits. need 8 image bytes to store 1 character

    for(int i = 0; magic_string[i] != '\0'; i++)
    {
        fread(image_buffer, 8, 1, encInfo->src_image_fptr);// read 8 bytes from image

        encode_1byte_to_lsb(magic_string[i], image_buffer);// hide 1 character into those 8 bytes

        fwrite(image_buffer, 8, 1, encInfo->output_image_fptr);// write modified bytes
    }

    return success;
}

/* Encode secret file extension */
Status encode_secret_file_extn(EncodeInfo *encInfo)
{
    char *extn = strstr(encInfo->secret_fname, ".");// gets pointer to extension

    int extn_size = strlen(extn);// gets extension length

    char buffer[32];

    fread(buffer, 32, 1, encInfo->src_image_fptr);

    encode_4byte_to_lsb(extn_size, buffer);// stored extension size first, decoder needs this later. stored 1 by 1.

    fwrite(buffer, 32, 1, encInfo->output_image_fptr);

    char image_buffer[8];

    for(int i = 0; i < extn_size; i++)
    {
        fread(image_buffer, 8, 1, encInfo->src_image_fptr);

        encode_1byte_to_lsb(extn[i], image_buffer);

        fwrite(image_buffer, 8, 1, encInfo->output_image_fptr);
    }

    return success;
}

Status encode_secret_file_data(EncodeInfo *encInfo)
{
    char buffer[32];
    fread(buffer, 32, 1, encInfo->src_image_fptr);// Read 32 bits or 4 bytes of size 1(character size 1) and store image fptr pointer
    encode_4byte_to_lsb(encInfo->secret_file_size, buffer);// encode 4 bytes from lsb
    fwrite(buffer, 32, 1, encInfo->output_image_fptr);// write the encoded information back to the image file
    char ch;
    while(fread(&ch, 1 , 1, encInfo->secret_fptr ) > 0)// condition is as long as read data is not equal to zero
    {
        char data_buffer[8];
        fread(data_buffer, 8, 1, encInfo->src_image_fptr);// read data
        encode_1byte_to_lsb(ch,data_buffer);// encode 1 byte of lsb data
        fwrite(data_buffer, 8, 1, encInfo->output_image_fptr);// write the data back into the file
    }
        return success;
}

Status encode_1byte_to_lsb(char data, char *buffer_8)
{
    for(int i=0; i<32; i++)
    {
        buffer_8[i]=(buffer_8[i]&0xFE)|(data>>(7-i)*1);
    }
    return success;
}

Status encode_4byte_to_lsb(int data, char *buffer_32)
{
    for(int i=0; i<32; i++)
    {
        buffer_32[i]=(buffer_32[i]&0xFE)|(data>>(7-i)*1);
    }
    return success;
}
Status copy_remaining_img_data(EncodeInfo *encInfo)
{
    char ch;

    while(fread(&ch, 1, 1, encInfo->src_image_fptr)>0)
    {
        fwrite(&ch, 1, 1, encInfo->output_image_fptr);
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