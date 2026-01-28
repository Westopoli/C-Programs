// Westley Yarlott
// This program forms 3 tiers of students based on input point values, each student is associated with the index of entry. In short, the first 
// student's score is represented as a one while the second student's score is represented as a two. If the students score was closest to 30, they 
// will be put in tier 1. If their score was closest to 75, they'll be put in tier 2. If their score was closest to 120, they'll be tier 3.  

#include <stdio.h>
#include <stdlib.h>

// Each tiers value is defined
#define T1 30
#define T2 75
#define T3 120

void assign_tier(int *points, int *tier, int n);

int main()
{
    // j is used to populate the tier array with numbers 1 through n incrementing upward by 1, as you can see in the for loop below
    int n, i, userInput, j = 1;

    printf("Enter number of students: ");
	scanf("%d", &userInput);

    n = userInput; 
    int points[n];
    int tier[n];

    for(i = 0; i < n; i++)
    {
        tier[i] = j;
        j++;
    }
    
    // Clearing input buffer, otherwise program will fail
	while ((userInput = getchar()) != '\n'); 
    printf("Enter points for each student: ");

    // User populates array
    for (i = 0; i < n; i++)
        scanf("%d", &points[i]);

    // Call function
    assign_tier(points, tier, n);

    return 0;
}

void assign_tier(int *points, int *tier, int n)
{
    // 
    int difference1, difference2, difference3;
    int numberOfT1s = 0, numberOfT2s = 0, numberOfT3s = 0;
    int *p;

    // The loop will increment through the points[] array, using memory addresses to do so, counting how many of each tier the user entered
    // This information will be useful for both indexing and output 
    for(p = points; p < points + n; p++)
    {
        // For each value in each address, the value of the difference between each tier is calculated 
        difference1 = abs(*p - T1);
        difference2 = abs(*p - T2);
        difference3 = abs(*p - T3);

        // These if's determine which tier the value in the current p address is 
        if((difference1 < difference2) && (difference1 < difference3))
            numberOfT1s++;
        
        else if((difference2 < difference1) && (difference2 < difference3))
            numberOfT2s++;
        
        else
            numberOfT3s++;
        
    }

    // These pointers point to the index addresses of where each teir will begin in the tier array
    int *t1, *t2, *t3;
    // Tier 1 pointer will point to the start of the array since Tier 1 will start at the beginning
    t1 = tier;
    // Tier 2 pointer will point to the element immediately following the last Tier 1 element
    t2 = tier + n - numberOfT3s - numberOfT2s;
    // Tier 3 pointer points to the element immediately following the last Tier 2 element
    t3 = tier + n - numberOfT3s;

    // Now we increment through the points[] array again to populate the tier array now that we have enough information about the 
    // organization of the tier array with regards to it's indexing and where each tier will begin and end so we can accurately output 
    // the information to the user
    for(p = points; p < points + n; p++)
    {
        // The difference is calculated twice as a result of two different iterations occuring
        difference1 = abs(*p - T1);
        difference2 = abs(*p - T2);
        difference3 = abs(*p - T3);

        // each statement uses the index calculated above to determine where to place each student. Each student is just 
        // represented as the index within the pointer array. Thus, we set the value in the tier array to the index of that student within 
        // the pointer array. (The + 1 is because the student at the 0th position within the array is the "1st" student)
        if((difference1 < difference2) && (difference1 < difference3))
        {
            // The index is calculated by subtracted the current address by the address of the first element in the array 
            // (The + 1 is purely visual and does not effect the calculations at all)
            *t1 = (p - points) + 1;
            t1++;
        }
        else if((difference2 < difference1) && (difference2 < difference3))
        {
            
            *t2 = (p - points) + 1;
            t2++;
        }
        else
        {
            
            *t3 = (p - points) + 1;
            t3++;
        }
    }

    // Since these values were used as indexes and incremented to iterate through the last loop, but we still need them, they're reset to
    // the first index of every tier respectively 
    t1 = tier;
    t2 = tier + n - numberOfT3s - numberOfT2s;
    t3 = tier + n - numberOfT3s;

    // Now that the array is properly arranged and the indexes of each tier are recorded, we can print each tier. With each for loop the 
    // "index" is set to p and the p is set to the index of the first element of each tier, and iterates until it reaches the end of the next tier 
    printf("Tier 1: student ");
    for(p = tier; p < t2; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");

    printf("Tier 2: student ");
    for(p = t2; p < t3; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");

    printf("Tier 3: student ");
    for(p = t3; p < tier + n; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");
}