#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR_FOR_SUFFIX 4
//#################################################################################
//This file contains functions for opening the source files and checking for errors
//#################################################################################

//Checks if the user passed any source file to the assembler, if not then ends the program
checkingForSourceFile(int fileCounter)
{
	if(filesCounter< 1)
	{
        	fprintf(stderr,"\nError- No source files were received by the assembler\n");
        	exit(1);
	}	
}

// Gets the file name from argv file
char *get_file_name(char *name)
{
	char *input_file_name = (char*)malloc(strlen(name));
    strcpy(input_file_name, name);
    return input_file_name;
}

// Creates new file name from argv file name with .as suffix
char *create_file_name_as(char *name)
{
    char *input_file_name = (char*)malloc(strlen(name) + MAX_CHAR_FOR_SUFFIX);
    strcpy(input_file_name, name);
    strcat(input_file_name, ".as");
    return input_file_name;
}

// Creates new file name after the source file go throu pre processor stage 
char *create_file_name_am(char *name)
{
    char *input_file_name = (char*)malloc(strlen(name) + MAX_CHAR_FOR_SUFFIX);
    strcpy(input_file_name, name);
	strcat(input_file_name, ".am");
    return input_file_name;
}

// Checks if the dynamic memory allocation was successful
void is_dynamic_allocation_succesful(char *file_name, char *file_name_as, char *file_name_am)
{
	if (file_name == NULL || file_name_as == NULL || file_name_am == NULL)
		{
            fprintf(stderr, "\nError- can't get memory for the file name.\n");
            exit(1);
        }
}






