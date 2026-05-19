/*
Name : M N Aditya
User_id = 25048_015
MP3 TAG READER AND EDITOR PROJECT
This project is designed to read and modify metadata (ID3 tags) of MP3 files.
It supports viewing and editing of important fields such as Title, Artist, Album, Year, Genre, and Comments.
The program uses command-line arguments to determine the operation: -v option is used to view the existing tag information of an MP3 file. -e option is used to edit specific tags by providing new values.
The main function acts as the controller of the program. It first validates the command-line arguments using validate_cla(), and based on the result, it calls either the view() or edit() function.
The view module reads ID3 frames and displays tag information, while the edit module updates selected frames by modifying their content safely.
The program handles binary file operations, frame parsing, and endian conversion to correctly interpret MP3 metadata structure.
This project demonstrates concepts of file handling, structures, command-line arguments, and string manipulation in C.
*/
#include "mp3_header.h"
int main(int argc, char *argv[])
{
    struct MP3 mp3 = {0};   // Structure to hold all inputs
    int ret = validate_cla(argc, argv, &mp3);  // Parse command line
    if (ret == VIEW)
    {
        view(&mp3);// Call view function
    }
    else if (ret == EDIT)
    {
        edit(&mp3);// Call edit function
    }
    else
    {
        printf("Invalid option. Use --help\n");
    }
    return 0;
}