// Westley Yarlott
// This program determines if a user inputted set of numbers are alternating in sign or not. The program counts the number of times the sign 
// has flipped, and if the count is equal to the number of elements, then it concludes that the set is alternating. 

#include <stdio.h>

int is_alternating_sequence(int *sequence, int n);

int main()
{
    int n, i, userInput, output;

    // Get user input 
    printf("Enter length of the sequence: ");
	scanf("%d", &userInput);

    // Declare array with user specified size
    n = userInput; 
    int sequence[n];
    
    // Clearing input buffer, otherwise program will fail
	while ((userInput = getchar()) != '\n'); 
    printf("Enter numbers of the sequence: ");

    // User populates array
    for (i = 0; i < n; i++)
        scanf("%d", &sequence[i]);

    // Call function 
    output = is_alternating_sequence(sequence, n);
    
    // Print output
    if(output)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}

// The function iterates through the array comparing every value to the value ahead of it. To account for the last element (which would be compared 
// to nothing), when the loop reaches the last address, an if statement compares the last element to the element before it. 
int is_alternating_sequence(int *sequence, int n)
{
    // p is the value of the current memory address being iterated, q will be set to the value directly following it
    int *p, *q;
    int numberOfFlippedSigns = 0;

    for(p = sequence; p < sequence + n; p++)
    {
        q = (p + 1);
        int *lastElementAddress = sequence + n - 1;
        int *secondToLastElementAddress = sequence + n - 2;

        // So long as we haven't reached the last element of the array, we can keep comparing each element to the one after it
        if(p != lastElementAddress)
        {
            // If p is positive AND q is negative, or vice versa, the counter will increase by 1
            if((*p > 0 && *q < 0) || (*p < 0 && *q > 0))
                numberOfFlippedSigns++;
        }
        // Once we've reached the last element, we compare it to the one before
        else
        {
            if((*p > 0 && *secondToLastElementAddress < 0) || (*p < 0 && *secondToLastElementAddress > 0))
                numberOfFlippedSigns++;
        }
    }

    if(numberOfFlippedSigns == n)
        return 1;
    else 
        return 0;    
}