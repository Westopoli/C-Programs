// Westley Yarlott
// This program takes a user's input from the command line in the form of a phone number containing letters and outputs the letter equivalent

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Maximum length number the user should be entering (including special characters)
#define MAX_LENGTH 13

void convert(char *input, char *output);
char isDigit(char input);

int main(int argc, char *argv[])
{
	char output[MAX_LENGTH];
	char *p = argv[1];
	
	// This if makes sure that the user entered something other than nothing in the command line so input can be taken
	if(argc > 1)
    {
		// This loop converts the user's input to upper case characters so the convert function can be called 
		while (*p != '\0')
		{
			*p = toupper(*p);
			p++;
		}
		
		convert(argv[1], output);

		printf("%s\n", output);
    }
    else 
        printf("Invalid number of arguments"); 
	
    return 0;
}

void convert(char *input, char *output)
{
	char *indexPointer;
	char *outputPointer = output;
	int digits = 0;

	// This for loop goes through every character the user input, and adds associated nummerical values to the output array
	for(indexPointer = input; *indexPointer != '\0'; indexPointer++)
	{
		// ( ) and - are allowed as inputs and are added to the output array when input
		if(*indexPointer == '(' || *indexPointer == ')' || *indexPointer == '-')
			*outputPointer = *indexPointer;
		
		// The first three digits that represent the area coe are skipped from conversion to their letter equivalent 
		else if(digits < 3)
		{
			if(isDigit(*indexPointer))
			{
				*outputPointer = *indexPointer;
				digits++;
			}
		}
		
		// Beyond the area code, every letter the user input is converted
		else if(digits >= 3)
		{
			switch(*indexPointer)
			{
				case 'A': case 'B': case 'C':
					*outputPointer = '2';
					break; 
				case 'D': case 'E': case 'F':
					*outputPointer = '3';
					break;
				case 'G': case 'H': case 'I':
					*outputPointer = '4';
					break; 
				case 'J': case 'K': case 'L':
					*outputPointer = '5';
					break; 
				case 'M': case 'N': case 'O':
					*outputPointer = '6';
					break; 
				case 'P': case 'Q': case 'R': case 'S':
					*outputPointer = '7';
					break;
				case 'T': case 'U': case 'V':
					*outputPointer = '8';
					break;
				case 'W': case 'X': case 'Y': case 'Z':
					*outputPointer = '9';
					break; 
				default:
					break;
			}
		}
		// the output array is iterated at the end of the for loop to keep iterating with the input loop 
		outputPointer++;
	}
}

// This function returns 1 if the input is a digit and 0 if it isn't 
char isDigit(char input)
{
	if(((int)input >= '0') && ((int)input <= '9'))
		return 1;
		else
		return 0;
	}