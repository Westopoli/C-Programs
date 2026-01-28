// Westley Yarlott
// This program takes a set of user inputs symbolizing TA numbers that have already been assigned and outputs the number associated with the missing assigned TA

#include <stdio.h>

void selection_sort(int a[], int n);
int find_largest(int a[], int n);
int find_missing(int a[], int n);

int main(void)
{
    int i;
    int numTAs;
    int userInput;
    int missingTA = 0;

    // The size of the array of assigned TAs is user specified
    printf("Enter number of TAs: ");
	scanf("%d", &userInput);
    // The array is created size 1 smaller than the user inputted, as we are looking for one single missing number
    numTAs = userInput - 1;
    int TAs[numTAs];

    // Clearing input buffer, otherwise program will fail
	while ((userInput = getchar()) != '\n'); 
    printf("Enter TAs already assigned: ");

    // User populates array
    for (i = 0; i < numTAs; i++)
    {
        scanf("%d", &TAs[i]);
    }
        
    // The array is sorted from lowest to highest values
    selection_sort(TAs, numTAs);
    
    // The array is used to find the missing number
    missingTA = find_missing(TAs, numTAs);    

    printf("TA has not been assigned: %d", missingTA);
    printf("\n");
    
    return 0;
}

// This recursive function sorts the array from smallest to largest
void selection_sort(int a[], int n)
{
    int index_largest = 0, temp;

    // The other function will iterate down the array till n is 1
    if (n == 1)
    {
        return;
    }

    index_largest = find_largest(a, n);

    // The largest value of the array is always put at the end, since it's sorted from largest to smallest
    temp = a[index_largest];
    a[index_largest] = a[n - 1];
    a[n - 1] = temp;

    selection_sort(a, n - 1);

}

// 
int find_largest(int a[], int n)
{
    int largest = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > a[largest])
        {
            largest = i;
        }
    }
    return largest;
}

int find_missing(int a[], int n)
{
    int check;
    int missingTA;

    for(int i = 0; i <= n; i++)
    {
        check = i + 1;

        if(check != a[i])
        {
            missingTA = check;
            break;
        }
    }
    return missingTA;
}