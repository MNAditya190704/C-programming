#include <stdio.h>// standard input 
#include <string.h>// for strings
#include "decode.h"// uswer defined header for function declaration
#include "types.h"//userdefined header for
#include "common.h"
Status validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    if (strstr(argv[2], ".bmp") != NULL)
    {
        decInfo->stego_image_fname = argv[2];
    }
    else
    {
        return failure;
    }
    /* Output file name */
    if (argv[3] != NULL)
    {
        strcpy(decInfo->output_fname, argv[3]);
    }
    else
    {
        strcpy(decInfo->output_fname, "output");
    }
    return success;
}
/* Perform decoding */
Status do_decoding(char *argv[], DecodeInfo *decInfo)
{
    if (open_decode_files(decInfo) == failure)
    {
        printf("ERROR: Unable to open files\n");
        return failure;
    }
    printf("INFO: Files opened successfully\n");
    /* Skip BMP header */
    fseek(decInfo->fptr_stego_image, 54, SEEK_SET);
    if (decode_magic_string(decInfo) == failure)
    {
        printf("ERROR: Magic string mismatch\n");
        return failure;
    }
    printf("INFO: Magic string decoded successfully\n");
    if (decode_secret_file_extn(decInfo) == failure)
    {
        printf("ERROR: Failed to decode extension\n");
        return failure;
    }
    printf("INFO: Extension decoded successfully\n");
    /* Append extension to output file */
    strcat(decInfo->output_fname, decInfo->secret_extn);
    decInfo->fptr_output = fopen(decInfo->output_fname, "w");
    if (decInfo->fptr_output == NULL)
    {
        printf("ERROR: Unable to create output file\n");
        return failure;
    }
    if (decode_secret_file_data(decInfo) == failure)
    {
        printf("ERROR: Failed to decode secret data\n");
        return failure;
    }
    printf("INFO: Secret data decoded successfully\n");
    return success;
}
/* Open decode files */
Status open_decode_files(DecodeInfo *decInfo)
{
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");
    if (decInfo->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n",
                decInfo->stego_image_fname);
        return failure;
    }
    return success;
}
/* Decode magic string */
Status decode_magic_string(DecodeInfo *decInfo)
{
    char image_buffer[8];
    char magic_string[3];
    for (int i = 0; i < strlen(MAGIC_STRING); i++)
    {
        fread(image_buffer, 8, 1, decInfo->fptr_stego_image);
        magic_string[i] = decode_1byte_from_lsb(image_buffer);
    }
    magic_string[strlen(MAGIC_STRING)] = '\0';
    if (strcmp(magic_string, MAGIC_STRING) == 0)
    {
        return success;
    }
    return failure;
}
/* Decode secret file extension */
Status decode_secret_file_extn(DecodeInfo *decInfo)
{
    char buffer[32];
    /* Read extension size */
    fread(buffer, 32, 1, decInfo->fptr_stego_image);
    decInfo->extn_size = decode_4bytes_from_lsb(buffer);
    for (int i = 0; i < decInfo->extn_size; i++)
    {
        char image_buffer[8];
        fread(image_buffer, 8, 1, decInfo->fptr_stego_image);
        decInfo->secret_extn[i] =
            decode_1byte_from_lsb(image_buffer);
    }
    decInfo->secret_extn[decInfo->extn_size] = '\0';
    return success;
}
/* Decode secret file data */
Status decode_secret_file_data(DecodeInfo *decInfo)
{
    char buffer[32];
    /* Decode secret file size */
    fread(buffer, 32, 1, decInfo->fptr_stego_image);
    decInfo->secret_file_size =
        decode_4bytes_from_lsb(buffer);
    for (long i = 0; i < decInfo->secret_file_size; i++)
    {
        char image_buffer[8];
        fread(image_buffer, 8, 1,
              decInfo->fptr_stego_image);
        char ch = decode_1byte_from_lsb(image_buffer);
        fwrite(&ch, 1, 1, decInfo->fptr_output);
    }
    return success;
}
/* Decode 1 byte from LSB */
char decode_1byte_from_lsb(char *buffer)
{
    char data = 0;
    for (int i = 0; i < 8; i++)
    {
        data = data << 1;
        data = data | (buffer[i] & 1);
    }
    return data;
}
/* Decode 4 bytes from LSB */
int decode_4bytes_from_lsb(char *buffer)
{
    int data = 0;
    for (int i = 0; i < 32; i++)
    {
        data = data << 1;

        data = data | (buffer[i] & 1);
    }
    return data;
}