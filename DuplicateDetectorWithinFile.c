// Westley Yarlott
// This program takes a user's input from the command line in the form of a list of food items and removes duplicates from the list. It then writes the unduplicated array of food items to a new file.
// Both input and output files are the user's choice. 

#include <stdio.h>
#include <string.h>

#define Max_Text_Size 100
#define Max_Item_Size 1000
#define Max_File_Name_Size 50
 
int main(int argc, char *argv[])
{
    int j, i = 0;
    int indexOfCurrentFood;
    char *userInputFileArg = argv[1];
    char *userOutputFileArg = argv[2];
    char inputFileName[Max_File_Name_Size]; 
    char outputFileName[Max_File_Name_Size];
    char *filePointer = inputFileName;
    char food[Max_Item_Size][Max_Text_Size];
    char currentFood[Max_Item_Size];

    // If the user enters the wrong number of arguments, the program will not run
    if((argc > 1) && (argc < 4))
    {
        // The user's input is copied to the inputFileName and outputFileName arrays, both loops use the same pointer named "filePointer" to copy the strings
        for( ; *userInputFileArg != '\0'; userInputFileArg++)
        {
            *filePointer = *userInputFileArg;
            filePointer++;
        }
        *filePointer = '\0';
        for(filePointer = outputFileName; *userOutputFileArg != '\0'; userOutputFileArg++)
        {
            *filePointer = *userOutputFileArg;
            filePointer++;
        }
        *filePointer = '\0';

        // for(i = 0; i < 4; i++)
        // {
        //     printf("%c", inputFileName[i]);
        // }
        // printf("\n");

        // Opens the user designated file 
		FILE *inputFile = fopen(inputFileName, "r");
        if(inputFile == NULL){
            printf("unable to open the file.");
            return 0;
        }

        // This while uses fgets and strcpy to read the file line by line and copy each line into the food array of strings
        i = 0; 
        while (fgets(currentFood, Max_Text_Size, inputFile) != NULL) 
        {
            // Remove the trailing newline character, if present
            unsigned int len = strlen(currentFood);
            if (len > 0 && currentFood[len - 1] == '\n') {
                currentFood[len - 1] = '\0';
            }
        
            // Copy the line into the food array
            strcpy(food[i], currentFood);
            i++;
        }
        // Input file no longer needs to be read from, so we use fclose
        fclose(inputFile);

        // This loop iterates through the food array of strings, and compares each string to every other string in the array and removes duplicates, shifting the remaining elements up
        for(i = 0; food[i][0] != '\0'; i++)
        {
            // printf("Entered outer loop\n");
            // printf("%s\n", food[i]);

            // Loops through the entire food array of strings again, starting from the next element
            for(j = i + 1; food[j][0] != '\0'; j++)
            {
                // printf("Entered inner loop\n");
                // printf("%s\n", food[j]);

                // Compares the two strings to see if a duplicate has been found
                if(strcmp(food[i], food[j]) == 0)
                {
                    // printf("Found duplicate %s\n", food[j]);

                    // Shifts every element after upward
                    for(indexOfCurrentFood = j; food[indexOfCurrentFood][0] != '\0'; indexOfCurrentFood++)
                    {
                        // printf("Removing %s\n", food[indexOfCurrentFood]);
                        // printf("Shifting %s\n", food[indexOfCurrentFood + 1]);

                        strcpy(food[indexOfCurrentFood], food[indexOfCurrentFood + 1]);
                    }
                }
            }
        }

        // Creates a new file based on user input
        FILE *outputFile = fopen(outputFileName, "w");
        if(outputFile == NULL){
            printf("unable to open the file.");
            return 0;
        }

        // This loop uses fputs to write the food array to the file
        for(i = 0; food[i][0] != '\0'; i++)
        {
            // printf("%s\n", food[i]);
            fputs(food[i], outputFile);
            fputs("\n", outputFile);
        }
        fclose(outputFile);
    }
    else 
        printf("Invalid number of arguments"); 

    // for(i = 0; i < 4; i++)
    // {
    //     printf("%c", inputFileName[i]);
    // }
    // printf("\n");
    // for(i = 0; i < 5; i++)
    // {
    //     printf("%c", outputFileName[i]);
    // }

    // print every element in food array
    // printf("Summary: \n");
    // for(i = 0; food[i][0] != '\0'; i++)
    // {
    //     printf("%s\n", food[i]);
    // }


    return 0;
 }

