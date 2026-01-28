// Westley Yarlott
// This program loops through user entered string and determines if the word the user entered contains 3 of the same consecutive letters at more 
// than one point within the word. 

#include <stdio.h>

// 1000 is the maximum allowed number of characters to be entered
#define LENGTH 1000

int read_line(char *string, int n);
int isDoubled(char *input);

int main()
{
	// The user doesn't specify the length of their word, so the string is initialized with a large length
    char userInput[LENGTH];
	int containsDuplicate = 0;

	// Get user input
	printf("Enter input: ");
    read_line(userInput, LENGTH);
    
	// Call function, which will return 0 or 1.
    containsDuplicate = isDoubled(userInput);

	// Output result
	if(containsDuplicate)
		printf("yes\n");
	else
		printf("no\n");

    return 0;
}

// This function uses a double for loop to compare every set of 3 letters to the rest of the string, and returns 1 if it finds a match
int isDoubled(char *input)
{
	// These three variables are used to store the 3 characters that will be stored in the outer loop to be compared to every single 
	// set of 3 consecutive characters contained in the rest of the string
	char A, B, C;
	// Because it's a nested for loop, two different indexes are required 
	char *indexOuter;
	char *indexInner;
	
	// The for loop will terminate once it reaches the null character (end of the string)
	for(indexOuter = input; *indexOuter != '\0'; indexOuter++)
	{
		// A, B, and C are the 3 consecutive characters at whatever index the outer loop is at
		A = *indexOuter;
		B = *(indexOuter + 1);
		C = *(indexOuter + 2);
		// The inner index begins after those 3 consecutive characters
		indexInner = indexOuter + 3;

		// This for loop will compare the three consecutive characters to ever other 3 sets in the string
		for( ; *indexInner != '\0'; indexInner++)
		{
			if((A == *indexInner) && (B == *(indexInner + 1)) && (C == *(indexInner + 2)))
				return 1;
		}
	}

	return 0; 
}

// This function reads the user input and adds it to an array to create a string
int read_line(char *string, int n)
{
    int character, i = 0;

	// Ignores whitespace before the user enters any actual characters
    while((character = getchar()) == ' ');

    // The first character will terminate the loop, but it needs to be stored before we call getchar() again, or else we'll lose it
    *string++ = character;
    i++;

    while ((character = getchar()) != '\n')
    { 
        if (i < n)
        { 
            *string++= character;
            i++;
        }
    }

    *string = '\0'; /* terminates string */
    return i; /* number of characters stored */
}