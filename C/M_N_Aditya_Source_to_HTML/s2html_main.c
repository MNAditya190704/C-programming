/*M N Aditya
25048_015
project start date 2 June 2026*/
// main()
//   │
//   ├── html_begin()
//   │
//   ├── source_to_html()
//   │       │
//   │       └── get_parser_event()
//   │                │
//   │                ├── pstate_idle_handler()
//   │                ├── pstate_comment_handler()
//   │                ├── pstate_string_handler()
//   │                ├── pstate_numeric_handler()
//   │                ├── pstate_keyword_handler()
//   │                └── pstate_header_handler()
//   │
//   └── html_end()
// #include <stdio.h>
// #include "s2html_event.h"
// #include "s2html_conv.h"


    //         START
    //            │
    //            ▼
    //  Read command-line arguments
    //            │
    //            ▼
    //   Open source (.c) file
    //            │
    //            ▼
    //   Open destination (.html) file
    //            │
    //            ▼
    //       html_begin()
    //            │
    //            ▼
    //   source_to_html()
    //            │
    //            ▼
    //       html_end()
    //            │
    //            ▼
    //       Close files
    //            │
    //            ▼
    //          END

    //              START
    //                 │
    //                 ▼
    //       Call get_parser_event()
    //                 │
    //                 ▼
    //          Event returned?
    //                 │
    //       ┌─────────┴─────────┐
    //       │                   │
    //       ▼                   ▼
    //      Yes                  EOF
    //       │                   │
    //       ▼                   ▼
    //   Switch(event type)      END
    //       │
    //       ├──────────────► Preprocessor Directive
    //       │                     │
    //       │                     ▼
    //       │             Write HTML span tag
    //       │
    //       ├──────────────► Comment
    //       │                     │
    //       │                     ▼
    //       │             Write comment span
    //       │
    //       ├──────────────► String
    //       │                     │
    //       │                     ▼
    //       │             Write string span
    //       │
    //       ├──────────────► Header File
    //       │                     │
    //       │                     ▼
    //       │             Write header span
    //       │
    //       ├──────────────► Numeric Constant
    //       │                     │
    //       │                     ▼
    //       │             Write number span
    //       │
    //       ├──────────────► Reserved Keyword
    //       │                     │
    //       │                     ▼
    //       │             Write keyword span
    //       │
    //       └──────────────► Regular Text
    //                             │
    //                             ▼
    //                      Write directly
    //                             │
    //                             ▼
    //                  Call get_parser_event()
/********** main **********/

int main (int argc, char *argv[])
{
	FILE * sfp, *dfp; // source and destination file descriptors 
	pevent_t *event;
	char dest_file[100];

	if(argc < 2)
	{
		printf("\nError ! please enter file name and mode\n");
		printf("Usage: <executable> <file name> \n");
		printf("Example : ./a.out abc.txt\n\n");
		return 1;
	}
#ifdef DEBUG
	printf("File to be opened : %s\n", argv[1]);
#endif

	/* opnen the file */

	if(NULL == (sfp = fopen(argv[1], "r")))
	{
		printf("Error! File %s could not be opened\n", argv[1]);
		return 2;
	}
	/* Check for output file */
	if (argc > 2)
	{
		sprintf(dest_file, "%s.html", argv[2]);
	}
	else
	{
		sprintf(dest_file, "%s.html", argv[1]);
	}
	/* open dest file */
	if (NULL == (dfp = fopen(dest_file, "w")))
	{
		printf("Error! could not create %s output file\n", dest_file);
		return 3;
	}

	/* write HTML starting Tags */
	html_begin(dfp, HTML_OPEN);

	/* Read from src file convert into html and write to dest file */

	do
	{
		event = get_parser_event(sfp);
		/* call sourc_to_html */
		source_to_html(dfp, event);
//		printf("In main : Event = %d\n", event);
	} while (event->type != PEVENT_EOF);

	/* Call start_or_end_conv function for ending the convertation */
	html_end(dfp, HTML_CLOSE);
	
	printf("\nOutput file %s generated\n", dest_file);
/* close file */
	fclose(sfp);
	fclose(dfp);

	return 0;
}
