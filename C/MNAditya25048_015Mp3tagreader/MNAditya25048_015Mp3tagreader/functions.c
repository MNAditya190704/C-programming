#include "mp3_header.h"// Includes struct definitions, macros (VIEW/EDIT), and function prototypes
int validate_cla(int argc, char *argv[], struct MP3 *mp3)// Function to validate command line arguments (CLA = Command Line Arguments)
    if( argc == 1 )// If no arguments are passed (only program name exists)
    {
        printf("ERROR: ./a.out : INVALID ARGUMENTS\n"); // Print error and usage instructions
        printf("USAGE : To view please pass like: ./a.out -v mp3filename\n");
        printf("        To edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c \"text\" mp3filename\n");
        printf("        To get help pass like : ./a.out --help\n");
        return 0;// Return 0 → indicates failure / invalid input
    if( (strcmp(argv[1], "--help") == 0) )// Check if user requested help
    {
        printf("------------------------------->HELP<-----------------------------------------\n");// Display help menu
        printf("1. -v -> to view mp3 file contents\n");
        printf("2. -e -> to edit mp3 file contents\n");
        printf("\t\t2.1. -t -> to edit song title\n");
        printf("\t\t2.2. -a -> to edit artist name\n");
        printf("\t\t2.3. -A -> to edit album name\n");
        printf("\t\t2.4. -y -> to edit year\n");
        printf("\t\t2.5. -m -> to edit content\n");
        printf("\t\t2.6. -c -> to edit comment\n");
        return 0; // Return 0 → help shown, no operation to perform
    }
    // VIEW OPTION
    if(!strcmp(argv[1], "-v"))// Check if user selected view mode
    {
        if(argc != 3)// Expect exactly 3 arguments:./a.out -v file.mp3
        {
            printf("ERROR: Invalid arguments for viewing\n");
            printf("USAGE: ./a.out -v file.mp3\n");
            return 0;// Invalid input
        }
        mp3->mp3_filename = argv[2];   // assign filename
        return VIEW;// Return macro value (1), indicates view operation
    }
    // EDIT OPTION
    if(!strcmp(argv[1], "-e"))// Check if user selected edit mode
    {
        if(argc < 5)   // allow text with spaces
        {
            printf("ERROR: Invalid arguments for editing\n");// Minimum required arguments: ./a.out -e -t "text" file.mp3; argc < 5 means insufficient arguments
            printf("USAGE: ./a.out -e -t/-a/-A/-y/-m/-c \"text\" file.mp3\n");
            return 0;
        }
        mp3->edit_option = argv[2];// Assign edit option (e.g., "-t", "-a")
        mp3->new_text = argv[3];// new tag value
        mp3->mp3_filename = argv[4];// filename
        return EDIT;
    }
    printf("ERROR: Invalid option\n");// If none of the valid options matched
    printf("Use ./a.out --help for usage\n");
    return 0;// Invalid command
}
//Convert endian format (big ↔ little)
void toggle_endianess(struct MP3 *mp3, int *size)
{
    char *ptr = (char *)size;
    char temp = ptr[0];
    ptr[0] = ptr[3];
    ptr[3] = temp;
    temp = ptr[1];
    ptr[1] = ptr[2];
    ptr[2] = temp;
}