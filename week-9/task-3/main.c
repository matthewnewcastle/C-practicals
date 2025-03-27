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
#include <string.h>

union Number
{
    int intValue;
    float floatValue;
};

// Generic function to get valid numeric input
void getValidInput(const char *prompt, union Number *number, int isFloat)
{
    char buffer[50];
    char *endptr;

    while (1)
    {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            printf("Error reading input. Try again.\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (isFloat)
        {
            number->floatValue = strtof(buffer, &endptr);
            if (endptr == buffer || *endptr != '\0')
            {
                printf("Invalid input. Please enter a valid floating-point number.\n");
                continue;
            }
            if (number->floatValue < -FLT_MAX || number->floatValue > FLT_MAX)
            {
                printf("Number out of range. Enter a value between %.3e and %.3e.\n", -FLT_MAX, FLT_MAX);
                continue;
            }
        }
        else
        {
            long num = strtol(buffer, &endptr, 10);
            if (endptr == buffer || *endptr != '\0')
            {
                printf("Invalid input. Please enter a valid integer.\n");
                continue;
            }
            if (num < INT_MIN || num > INT_MAX)
            {
                printf("Number out of range. Enter a value between %d and %d.\n", INT_MIN, INT_MAX);
                continue;
            }
            number->intValue = (int)num;
        }
        break;
    }
}

int main()
{
    union Number number;
    char choice;

    while (1)
    {
        printf("Enter 'i' for integer or 'f' for float: ");
        choice = getchar();
        while (getchar() != '\n')
            ; // Clear input buffer

        if (choice == 'i' || choice == 'I')
        {
            getValidInput("Enter an integer: ", &number, 0);
            printf("\nInteger representation: %d\n", number.intValue);
            printf("Floating-point representation: %f\n", (float)number.intValue);
            break;
        }
        else if (choice == 'f' || choice == 'F')
        {
            getValidInput("Enter a float: ", &number, 1);
            printf("\nFloating-point representation: %f\n", number.floatValue);
            printf("Integer representation: %d\n", (int)number.floatValue);
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
