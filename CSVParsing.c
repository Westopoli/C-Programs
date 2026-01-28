// Westley Yarlott
// This program output's a user requested set of games to a file based on the console name entered by the user.
// File input is read from a user specified .csv file and output is written to result.csv.
    // note: .csv file was lost to the unending shores of time, I apologize for any inconvienience.
        // though, scanning function could be modified to fit your csv if needed

#include <stdio.h>
#include <string.h>

#define MAX_GAMES 1000
#define MAX_STRING 100

// This is the structure that will hold the game data, most of which isn't actually used in the program, but could be useful in the future.
struct game
{
    char name[MAX_STRING + 1]; 
    char genre[MAX_STRING + 1]; 
    int rating; 
    double price; 
    char console[MAX_STRING + 1];
    char ageRating;
    
};

// Function declarations
int search(struct game list[], int n, struct game result[], char *searchConsole);
int read_line(char *string, int n);
 
int main(void)
{
    // Asks user for input using read_line function
    char inputFileName[MAX_STRING + 1];
    printf("Enter file name: ");
    read_line(inputFileName, MAX_STRING);

    // Declares the variable pointer inputFile and opens the file for reading, ends program if it can't be opened. 
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Declares the arrays needed to hold and output data from the file. 
    struct game list[MAX_GAMES];
    struct game result[MAX_GAMES];

    // Scans and stores the data from the file into the list array.
    int i = 0; 
    while (fscanf(inputFile, "%[^,], %[^,], %d, %lf, %[^,], %[^\n]", list[i].name, list[i].genre, 
        &list[i].rating, &list[i].price, list[i].console, &list[i].ageRating) == 6) {
        i++;
        fgetc(inputFile); // Consume the newline character after each line
    }
    fclose(inputFile);

    // Asks user for console name to search
    char searchConsole[MAX_STRING + 1];
    printf("Enter console name: ");
    read_line(searchConsole, MAX_STRING);

    // Searches for user entered value from data, adds every entry that matches to the result array, and returns the number of games found in count. 
    search(list, i, result, searchConsole);

    // Print the list array to the console for debugging purposes.
    printf("\nList of games:\n");
    for (int j = 0; j < i; j++) {
        printf("%s, %s, %d, %.2f, %s, %c\n", list[j].name, list[j].genre,
               list[j].rating, list[j].price, list[j].console, list[j].ageRating);
    }

    // Declares the variable pointer outputFile and opens the file for writing, ends program if it can't be opened.
    FILE *outputFile = fopen("result.csv", "w");
    if (outputFile == NULL) {
        printf("Unable to open the output file.\n");
        return 1;
    }

    // Prints games in result array to another file named result.csv in the same format as the input file. 
    i = 0;
    while(result[i].name[0] != '\0') {
        fprintf(outputFile, "%s,%s,%d,%.2f,%s, %c\n", result[i].name, result[i].genre,
                result[i].rating, result[i].price, result[i].console, result[i].ageRating);
        i++;
        fgetc(outputFile); // Consume the newline character after each line
    }
    fclose(outputFile);

    return 0;
 }

// This function searches the list array for the user entered console name and stores all matching entries in the result array.
int search(struct game list[], int n, struct game result[], char *searchConsole)
{
    int count = 0; 
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].console, searchConsole) == 0) {
            result[count] = list[i]; 
            count++;
        }
    }
    
    return count;
}

// This function reads a line of input from the user and stores it in the string variable. It also handles whitespace and ensures that the string is null-terminated.
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