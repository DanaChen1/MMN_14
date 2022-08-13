#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//The user is passing the command line arguments the source files for the assembler
int main(int argc, char *argv[])
{
	FILE *input;
	int filesCounter= argc-1;
	int i=1;
	checkingForSourceFile(fileCounter); //checks if the user passed any source file to the assembler, if not then ends the program
	for(i; i<=filesCounter; i++) //opening every file that can be opened
	{
		char *file_name = get_file_name(argv[i]);
        char *file_name_as = create_file_name_as(file_name);
		char *file_name_am = create_file_name_am(file_name);
		is_dynamic_allocation_succesful(file_name, file_name_as, file_name_am);
		
		input = fopen(file_name_as, "r");
		if(input==NULL) // if the file couldn't be opened, then writes an error to the user
		{
			fprintf(stderr, "\nThe file: %s can't be opened, skipping to the next file.\n", file_name);
		}
		
		//##Compiling##
		else // the file is good to go
		{
			pre_processor(input, file_name_as, file_name_am);
			first_pass(input, file_name_am);
			second_pass();
			
		}

		fclose(input);
		free(file_name);
		free(file_name_as);
		free(file_name_am);
	}
	return 0;
}




