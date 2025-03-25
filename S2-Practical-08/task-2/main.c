#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int size;       /* size of the array */
    int validInput; /* test for a valid int */

    // Get the size of the array from the user.
    do
    {
        printf("Enter array size: ");
        validInput = scanf("%d", &size);

        // Clear the input buffer if invalid input is detected.
        if (validInput != 1 || size <= 0)
        {
            printf("Invalid input. Please enter a positive integer.\n");
            while (getchar() != '\n')
                ; // Discard invalid input
        }

    } while (validInput != 1 || size <= 0);

    printf("You entered: %d\n", size);

    // Declare the array
    int integers[size];

    // Prompt the user to enter values into the array
    for (int i = 0; i < size; i++)
    {
        do
        {
            printf("Enter element %d: ", i + 1);
            validInput = scanf("%d", &integers[i]);

            if (validInput != 1)
            {
                printf("Invalid input. Please enter an integer.\n");
                while (getchar() != '\n')
                    ; // Discard invalid input
            }

        } while (validInput != 1);
    }

    // Print the entered values
    printf("You entered: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", integers[i]);
    }
    printf("\n");

    // Remove duplicates from the array
    int unique[size];   /* Array for storing unique elements */
    int uniqueSize = 0; /* var for storing the size of the unique array */
    bool isDuplicate;   /* flag for detecting a duplicate s*/

    for (int i = 0; i < size; i++)
    {
        isDuplicate = false;

        // Check if each integer is already in the unique array
        for (int j = 0; j < uniqueSize; j++)
        {
            if (integers[i] == unique[j])
            {
                isDuplicate = true;
                break;
            }
        }

        // If this integer is not a duplicate then add it to the unique array
        if (!isDuplicate)
        {
            unique[uniqueSize] = integers[i];
            uniqueSize++;
        }
    }

    // Print out the unique array
    printf("Unique array: ");
    for (int i = 0; i < uniqueSize; i++)
    {
        printf("%d  ", unique[i]);
    }
    printf("\n");

    return 0;
}
