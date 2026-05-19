#include "mp3_header.h"
void view(struct MP3 *mp3)// pointer to structur containng file name, file pointer, and metadata
{
    char header[4];
    mp3->org_mp3_fptr = fopen(mp3->mp3_filename, "rb");
    if(mp3->org_mp3_fptr == NULL)// error handling
    {
        printf("Error : unable to open %s\n", mp3->mp3_filename);
        return;
    }
    fread(header, 1, 3, mp3->org_mp3_fptr);//read 3 bytes from file
    header[3] = '\0';

    if (strcmp(header, "ID3") == 0)// check mp3 signature
    {
        printf("Yes, it is an MP3 file\n");

    print_tag_data(mp3->org_mp3_fptr, "TIT2");// extract tags
    print_tag_data(mp3->org_mp3_fptr, "TPE1");
    print_tag_data(mp3->org_mp3_fptr, "TALB");
    print_tag_data(mp3->org_mp3_fptr, "TYER");
    print_tag_data(mp3->org_mp3_fptr, "TCON");
    print_tag_data(mp3->org_mp3_fptr, "COMM");

    fclose(mp3->org_mp3_fptr);// close the file
    }
    else
    {
        printf("It is not an MP3 file\n");
        fclose(mp3->org_mp3_fptr);
        return;
    }
    fseek(mp3->org_mp3_fptr, 7 , SEEK_CUR);
}
void print_tag_data(FILE *org_mp3_fptr, char *tag)
{
    char frame[5];// store id
    int size;// store frame id
    char data[100];// size of frame data

    rewind(org_mp3_fptr);// move pointer to begining

    fseek(org_mp3_fptr, 10, SEEK_SET); //skip 10 bytes od data
    while (fread(frame, 1, 4, org_mp3_fptr))
    {
        frame[4] = '\0';// convert to string

        /* Read frame size */
        fread(&size, 4, 1, org_mp3_fptr);

        /* Convert big endian to little endian */
        toggle_endianess(NULL, &size);

        /* Skip 2 bytes flag + 1 byte encoding */
        fseek(org_mp3_fptr, 3, SEEK_CUR);

        if (strcmp(frame, tag) == 0)// frame match
        {
            fread(data, 1, size - 1, org_mp3_fptr);
            data[size - 1] = '\0';// read content

            tag_to_name(frame);

            printf(" : %s\n", data);

            break;
        }
        else
        {
            
            fseek(org_mp3_fptr, size - 1, SEEK_CUR);
        }
    }
}
void tag_to_name(char *tag)//readable names
{
    if (!strcmp(tag, "TIT2"))
    {
        printf("Title");
    }
    else if (!strcmp(tag, "TPE1"))
    {
        printf("Artist");
    }
    else if (!strcmp(tag, "TALB"))
    {
        printf("Album");
    }
    else if (!strcmp(tag, "TYER"))
    {
        printf("Year");
    }
    else if (!strcmp(tag, "TCON"))
    {
        printf("Music");
    }
    else if (!strcmp(tag, "COMM"))
    {
        printf("Comment");
    }
}