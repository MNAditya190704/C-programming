#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>
#include "common.h"


typedef struct DecodeInfo
{
    /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

    /* Output File Info */
    char output_fname[20];
    FILE *fptr_output;

    /* Secret File Extension */
    char secret_extn[10];
    int extn_size;

    /* Secret File Size */
    long secret_file_size;

} DecodeInfo;

/*validate decode arguments */
Status validate_decode_args(int argc, char *argv[], DecodeInfo *adi);

/*perform decoding */
Status do_decoding(char *argc[], DecodeInfo *decinfo);

/*open decode files */
Status open_decode_files(DecodeInfo *decInfo);

/*decode magic string */
Status decode_magic_string(DecodeInfo *decInfo);

/*decode secret file extension */
Status decode_secret_file_extn(DecodeInfo *decInfo);

/*decode secret file data */
Status decode_secret_file_data(DecodeInfo *decInfo);

/*decode 1 byte from lsb */
char decode_1byte_from_lsb(char *buffer);

/*decode 4 bytes from lsb */
int decode_4bytes_from_lsb(char *buffer);

#endif