/*M N Aditya
25048_015
start time 11-05-2026 23:00 
This project implements LSB Steganography in C. Steganography is the process of hiding secret information inside another file. In this program, a secret text file is hidden inside a BMP image without visibly changing the image.
The program supports two operations:
-e: Encode (hide data inside image)
-d: Decode (extract hidden data)
The main.c file controls the flow of the program. It checks command-line arguments, identifies whether the user wants encoding or decoding, validates inputs, and calls the required functions.
During encoding, the program:
Opens the source BMP image and secret text file.
Checks whether the image has enough space to store the secret data.
Copies the BMP header (first 54 bytes) directly to the output image.
Encodes a magic string (#*) to identify that the image contains hidden data.
Encodes the secret file extension and file size.
Encodes the actual secret file contents into the image using LSB encoding.
Copies the remaining image data unchanged.
LSB encoding works by modifying the least significant bit of each image byte. Since changing the last bit causes only a tiny change in color, the image appears visually unchanged.
For decoding, the program:
Opens the stego image.
Skips the BMP header.
Reads and verifies the magic string.
Extracts the hidden file extension and file size.
Reads the hidden data bit-by-bit and reconstructs the original secret file.
The project uses structures (EncodeInfo and DecodeInfo) to store file names, file pointers, sizes, and other related information. Functions are separated into encoding and decoding modules for better organization and readability.*/
#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"
#include "common.h"
int main(int argc, char *argv[])
{
    EncodeInfo encodeInfo;// Structure variable used to store all encoding related information
    DecodeInfo decodeInfo;// Structure variable used to store all decoding related information
    if(argc < 2)// Check whether minimum command line arguments are provided
    {
        printf("ERROR: Invalid arguments\n");
        printf("\nEncoding:\n");
        printf("./a.out -e <source.bmp> <secret.txt> [output.bmp]\n");
        printf("\nDecoding:\n");
        printf("./a.out -d <stego.bmp> [output_file]\n");
        return 1;
    }
    Opr_type opr = check_operation(argv[1]);// Check whether user selected encode(-e) or decode(-d)
    /* Encoding operation */
    if(opr == encode)
    {
        // Encoding requires:
        // argv[0] = program name
        // argv[1] = -e
        // argv[2] = source bmp image
        // argv[3] = secret file
        // argv[4] = optional output image
        // Check whether correct number of arguments are given
        if(argc < 4 || argc > 5)
        {
            printf("ERROR: Invalid number of arguments for encoding\n");

            printf("Usage:\n");
            printf("./a.out -e <source.bmp> <secret.txt> [output.bmp]\n");

            return 1;
        }
        // Store secret file name entered by user
        encodeInfo.secret_fname = argv[3];
        // If output image name is given by user
        if(argc == 5)
        {
            encodeInfo.output_image_fname = argv[4];
        }
        else
        {
            encodeInfo.output_image_fname = "stego.bmp";// Default output image name
        }
        /* Validate encode arguments */
        if(validate_encode_args(argv, &encodeInfo) == failure)// Validate source image and secret file
        {
            printf("ERROR: Validation failed\n");
            return 1;
        }
        printf("INFO: Encoding started\n");
        /* Perform encoding */
        if(do_encoding(argv, &encodeInfo) == success)// Start encoding process
        {
            printf("INFO: Encoding completed successfully\n");
        }
        else
        {
            printf("ERROR: Encoding failed\n");
            return 1;
        }
    }
    /* Decoding operation */
    else if(opr == decode)
    {
        // Decoding requires:
        // argv[0] = program name
        // argv[1] = -d
        // argv[2] = stego image
        // argv[3] = optional output file name
        // Check whether correct number of arguments are given
        if(argc < 3 || argc > 4)
        {
            printf("ERROR: Invalid number of arguments for decoding\n");

            printf("Usage:\n");
            printf("./a.out -d <stego.bmp> [output_file]\n");

            return 1;
        }
        if(validate_decode_args(argc, argv, &decodeInfo) == failure) // Validate decoding arguments
        {
            printf("ERROR: Validation failed\n");
            return 1;
        }
        printf("INFO: Decoding started\n");
        if(do_decoding(argv, &decodeInfo) == success)// Start decoding process
        {
            printf("INFO: Decoding completed successfully\n");
        }
        else
        {
            printf("ERROR: Decoding failed\n");
            return 1;
        }
    }
    else//If user enters invalid option
    {
        printf("ERROR: Unsupported operation\n");
        printf("\nEncoding:\n");// Show correct encoding command
        printf("./a.out -e <source.bmp> <secret.txt> [output.bmp]\n");
        printf("\nDecoding:\n");// Show correct decoding command
        printf("./a.out -d <stego.bmp> [output_file]\n");
        return 1;
    }
    return 0;
}