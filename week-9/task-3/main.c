/*
    Task 3:
        Define a union named Number that can store either an integer or a floating-point number.
        The union should have two members: intValue to store an integer and floatValue to store a floating-point number.

        Write a C program that demonstrates the use of the Number union to perform conversions between integer and floating-point representations.
        The program should provide the following functionalities:

        1) Input an integer or floating-point number from the user.
        2) Store the input value in the Number union using the appropriate member.
        3) Display both the integer and floating-point representations of the stored value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <string.h>

union Number
{
    int intValue;
    float floatValue;
};

float getValidFloat(const char *prompt)
{
    char buffer[50]; // Buffer to hold user input
    char *endptr;
    float num;

    while (1)
    {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            printf("Error reading input. Try again.\n");
            continue;
        }

        // Remove newline if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // Convert input to float
        num = strtof(buffer, &endptr);

        // Check for invalid input
        if (endptr == buffer || *endptr != '\0')
        {
            printf("Invalid input. Please enter a valid floating-point number.\n");
            continue;
        }

        // Check for floating-point overflow
        if (num < -FLT_MAX || num > FLT_MAX)
        {
            printf("Number out of range. Enter a value between %.3e and %.3e.\n", -FLT_MAX, FLT_MAX);
            continue;
        }

        return num;
    }
}

int getValidInt(const char *prompt)
{
    char buffer[50]; // Buffer to hold user input
    char *endptr;
    long num;

    while (1)
    {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            printf("Error reading input. Try again.\n");
            continue;
        }

        // Remove newline if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // Convert input to integer
        num = strtol(buffer, &endptr, 10);

        // Check for invalid input
        if (endptr == buffer || *endptr != '\0')
        {
            printf("Invalid input. Please enter a valid integer.\n");
            continue;
        }

        // Check for integer overflow
        if (num < INT_MIN || num > INT_MAX)
        {
            printf("Number out of range. Enter a value between %d and %d.\n", INT_MIN, INT_MAX);
            continue;
        }

        return (int)num;
    }
}

int main(int argc, char const *argv[])
{
    union Number number;
    char choice;
    char buffer[10];

    while (1)
    {
        printf("Do you want to enter an integer (i) or a float (f)?\n> ");
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            printf("Error reading input. Try again.\n");
            continue;
        }
        choice = buffer[0]; // Take only the first character

        while (buffer[strcspn(buffer, "\n")] != '\n' && getchar() != '\n')
            ;

        if (choice == 'i' || choice == 'I')
        {
            number.intValue = getValidInt("Enter an integer: ");
            printf("%d placed into the Number union.\n", number.intValue);
            break;
        }
        else if (choice == 'f' || choice == 'F')
        {
            number.floatValue = getValidFloat("Enter a float: ");
            printf("%f placed into the Number union.\n", number.floatValue);
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 'i' for integer or 'f' for float.\n");
        }
    }

    return 0;
}
