/*
    Name: Matthew Williamson
    ID: 240674999

    This program calculates the roots of a quadratic equation in the
        format ax^2 + bx + c = 0
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to get valid integer coefficients from the user
int getCoefficients(int *a, int *b, int *c)
{
    char extra;
    printf("Enter coefficients a, b, c: ");

    if (scanf("%d %d %d%c", a, b, c, &extra) != 4 || extra != '\n')
    {
        printf("Invalid input format!\n");
        // Clear the input buffer
        while (getchar() != '\n')
            ;
        return 0;
    }
    return 1;
}

// Function to get the desired output format from the user
void getOutputFormat(char *format, int *precision)
{
    do
    {
        printf("Enter desired output format (f for float, e for exponential): ");
        scanf("%2s", format);
        if (strcmp(format, "f") != 0 && strcmp(format, "e") != 0)
        {
            printf("Invalid Format! Enter 'f' or 'e'\n");
        }
    } while (strcmp(format, "f") != 0 && strcmp(format, "e") != 0);

    do
    {
        printf("Enter desired precision (number of decimal places): ");
        if (scanf("%d", precision) != 1 || *precision < 0)
        {
            printf("Invalid precision. Please enter a non-negative integer.\n");
            while (getchar() != '\n')
                ;            // Clear input buffer
            *precision = -1; // Set to an invalid value
        }
    } while (*precision < 0);
}

// Function to calculate and display roots for a quadratic equation
void calculateAndDisplayRoots(int a, int b, int c, const char *format, int precision)
{
    int discriminant = b * b - 4 * a * c;
    double root1, root2, realPart, imagPart;

    if (discriminant > 0)
    {
        // Two real and distinct roots
        root1 = (-b + sqrt(discriminant)) / (2.0 * a);
        root2 = (-b - sqrt(discriminant)) / (2.0 * a);
        if (strcmp(format, "f") == 0)
        {
            printf("Roots are real and distinct: %.*lf and %.*lf\n", precision, root1, precision, root2);
        }
        else
        {
            printf("Roots are real and distinct: %.*le and %.*le\n", precision, root1, precision, root2);
        }
    }
    else if (discriminant == 0)
    {
        // One real and repeated root
        root1 = -((double)b / (2 * a));
        if (strcmp(format, "f") == 0)
        {
            printf("Root is real and repeated: %.*lf\n", precision, root1);
        }
        else
        {
            printf("Root is real and repeated: %.*le\n", precision, root1);
        }
    }
    else
    {
        // Complex roots
        realPart = -((double)b / (2 * a));
        imagPart = sqrt(-discriminant) / (2.0 * a);
        if (strcmp(format, "f") == 0)
        {
            printf("Roots are complex: %.*lf + %.*lfi and %.*lf - %.*lfi\n", precision, realPart, precision, imagPart, precision, realPart, precision, imagPart);
        }
        else
        {
            printf("Roots are complex: %.*le + %.*lei and %.*le - %.*lei\n", precision, realPart, precision, imagPart, precision, realPart, precision, imagPart);
        }
    }
}
// Function to handle the linear case
void calculateAndDisplayLinearRoot(int b, int c)
{
    printf("Linear equation: x = %.2lf\n", -((double)c / b));
}

// Function to ask the user if they want to continue (modified for y/n)
int askToContinue()
{
    char choice;
    do
    {
        printf("Do you want to evaluate another equation? (y/n): ");
        // Read a single character and ignore the rest of the line
        scanf(" %c", &choice); // space before %c to consume any leftover newline
        while (getchar() != '\n')
            ; // Clear input buffer

        choice = tolower(choice); // Convert to lowercase for case-insensitivity

        if (choice != 'y' && choice != 'n')
        {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    } while (choice != 'y' && choice != 'n');

    return (choice == 'y');
}

int main()
{
    system("clear");

    int a, b, c;
    char format[3];
    int precision;

    do
    {
        // Get coefficients, continue only if successful
        if (!getCoefficients(&a, &b, &c))
        {
            continue;
        }

        // Handle the linear or invalid equation case (a == 0)
        if (a == 0)
        {
            if (b != 0)
            {
                calculateAndDisplayLinearRoot(b, c);
            }
            else
            {
                printf("No solution (invalid equation)!\n");
            }
        }
        else
        {
            // Get output format and precision
            getOutputFormat(format, &precision); // Corrected line

            // Calculate and display roots
            calculateAndDisplayRoots(a, b, c, format, precision);
        }
    } while (askToContinue());

    printf("Exiting program.\n");
    return 0;
}