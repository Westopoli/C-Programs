// Westley Yarlott
// This program converts the letters in a phone number to the alphabetical equivalent.

#include <stdio.h>
#include <ctype.h>

int main()
{
	// initialize necessary variables 
	char userNumber[30];
	int i = 0;
	int digits = 0;
	int letters = 0;

	// we only want to ask for the phone number once, so it isn't included in the do-while loop
	printf("Enter phone number: ");

	// this loop reads the user input and adds it to the userNumber array, as well as recording the number of letters and digits with respective counters
	do
	{
		userNumber[i] = toupper(getchar());
		if(isdigit(userNumber[i]))
		{
			digits++;
		}
		if(isalpha(userNumber[i]))
		{
			letters++;
		}
		
		i++;
	}while (letters < 7);

	// this loop goes through the array. Every letter gets changed to its associated number with the switch statement
	for(i = 0; i < 30; i++)
	{
		// this if statement bypasses the area code the user enters
		if(digits == 3)
		{
			switch(userNumber[i])
			{
				case 'A':
				case 'B': 
				case 'C':
					userNumber[i] = '2';
					break; 
				case 'D':
				case 'E':
				case 'F':
					userNumber[i] = '3';
					break;
				case 'G':
				case 'H':
				case 'I':
					userNumber[i] = '4';
					break; 
				case 'J':
				case 'K':
				case 'L':
					userNumber[i] = '5';
					break; 
				case 'M':
				case 'N':
				case 'O':
					userNumber[i] = '6';
					break; 
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
					userNumber[i] = '7';
					break;
				case 'T':
				case 'U':
				case 'V':
					userNumber[i] = '8';
					break;
				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
					userNumber[i] = '9';
					break; 
				default:
					break;
			}
		}

		// these if statements print only the digits, alphabetic charaters, and specified special charaters such as parentheses and dashes that are typically inlucded in phone
		// numbers from the userNumber array. 
		if(isdigit(userNumber[i]))
		{
			printf("%c", userNumber[i]);		
		}
		if(isalpha(userNumber[i]))
		{
			printf("%c", userNumber[i]);
		}
		if(userNumber[i] == '(' || userNumber[i] == ')' || userNumber[i] == '-')
		{
			printf("%c", userNumber[i]);
		}
	}
	printf("\n");
	
	return 0;
}
