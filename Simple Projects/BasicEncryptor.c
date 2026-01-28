// Westley Yarlott
// This program encrypts a user's number by accepting the number of digits they want their number to be, the actual number, and their encryption array
// The logic exchanges the actual user entered number with that specific number's position within the encryption array 

#include <stdio.h>
#define N 9

int main(void)
{
    int i;
    int j;
    int digits;
    int userInput;
    int encryption[N];
    
    // User decides how many digits their number to be encrypted will be
    printf("Enter the number of digits: ");
	scanf("%d", &userInput);
    
    // Two arrays are declared, one to house the number and other to house to encrypted message
    digits = userInput;
    int number[digits];
    int message[digits];

    // Clearing the input buffer to avoid input problems 
    getchar(); 

    // Each number the user wants to encrypt is added as a singular element in the array
    printf("Enter the number: ");
    for(i = 0; i < digits; i++)
    {
        // getchar() is used so that each individual number is treated as it's own element, scanf would combine every entry into one long number
        userInput = getchar();
        number[i] = (userInput - '0');
    }

    // Clearing the input buffer to avoid input problems 
    while ((userInput = getchar()) != '\n'); 

    // The user enters their own specific encryption array 
    printf("Enter the encryption array: ");
    for(i = 0; i <= N; i++)
    {
        scanf("%d", &encryption[i]);
    }

    // Nested for loops allow the program to compare each element in the number array to each element in the encryption array, and add the respective
    // value to the new array
    for(i = 0; i < digits; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(number[i] == encryption[j])
            {
                // The new value is the index location of the number within the encryption array
                message[i] = j;
            }
        }  
    }

    // Print the new array 
    for(i = 0; i < digits; i++)
    {
        printf("%d", message[i]);
    }
    printf("\n");

    return 0;
}