#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* prints a string with a newline */
void print(char string[]);

/* gets an input from the user within a specified range */
int getValidInput(int min, int max, char prompt[]);

/* Enum for shape choices */
typedef enum
{
    CIRCLE = 1,
    SQUARE,
    RECTANGLE,
    TRIANGLE,
    EXIT
} Shape;

/* Enum for type of calculation */
typedef enum
{
    AREA = 1,
    PERIMETER
} Calculation;

/* Function declarations */
void processShape(Shape shape);
void calculateCircle(Calculation type);
void calculateSquare(Calculation type);
void calculateRectangle(Calculation type);
void calculateTriangle(Calculation type);

int main(int argc, char const *argv[])
{
    while (1)
    {
        Shape shape = getValidInput(1, 5,
                                    "Select a shape to calculate the area or perimeter\n"
                                    "  1) Circle\n  2) Square\n  3) Rectangle\n  4) Triangle\n  5) Exit.");

        if (shape == EXIT)
        {
            print("Exiting the program.");
            exit(0);
        }

        processShape(shape);
    }
    return 0;
}

void processShape(const Shape shape)
{
    const Calculation type = getValidInput(1, 2,
                                     "Calculate area or perimeter?\n"
                                     "  1) Area\n  2) Perimeter");

    switch (shape)
    {
    case CIRCLE:
        calculateCircle(type);
        break;
    case SQUARE:
        calculateSquare(type);
        break;
    case RECTANGLE:
        calculateRectangle(type);
        break;
    case TRIANGLE:
        calculateTriangle(type);
        break;
    default:
        break;
    }
}

void calculateCircle(Calculation type)
{
    float radius;

    switch (type)
    {
    case AREA:
        print("Calculating Circle Area...");
        printf("Enter the radius of the circle (in meters): ");
        scanf("%f", &radius);
        printf("Area of Circle = %.4f square meters\n", M_PI * radius * radius);
        break;
    case PERIMETER:
        print("Calculating Circle Perimeter...");
        printf("Enter the radius of the circle (in meters): ");
        scanf("%f", &radius);
        printf("Perimeter of Circle (Circumference) = %.4f meters\n", 2 * M_PI * radius);
        break;
    }
}

void calculateSquare(Calculation type)
{
    float side;

    switch (type)
    {
    case AREA:
        print("Calculating Square Area...");
        printf("Enter the side length of the square (in meters): ");
        scanf("%f", &side);
        printf("Area of Square = %.4f square meters\n", side * side);
        break;
    case PERIMETER:
        print("Calculating Square Perimeter...");
        printf("Enter the side length of the square (in meters): ");
        scanf("%f", &side);
        printf("Perimeter of Square = %.4f meters\n", 4 * side);
        break;
    }
}

void calculateRectangle(Calculation type)
{
    float length, width;

    switch (type)
    {
    case AREA:
        print("Calculating Rectangle Area...");
        printf("Enter the length of the rectangle (in meters): ");
        scanf("%f", &length);
        printf("Enter the width of the rectangle (in meters): ");
        scanf("%f", &width);
        printf("Area of Rectangle = %.4f square meters\n", length * width);
        break;
    case PERIMETER:
        print("Calculating Rectangle Perimeter...");
        printf("Enter the length of the rectangle (in meters): ");
        scanf("%f", &length);
        printf("Enter the width of the rectangle (in meters): ");
        scanf("%f", &width);
        printf("Perimeter of Rectangle = %.4f meters\n", 2 * (length + width));
        break;
    }
}

void calculateTriangle(Calculation type)
{
    float base, height, side1, side2, side3;

    switch (type)
    {
    case AREA:
        print("Calculating Triangle Area...");
        printf("Enter the base of the triangle (in meters): ");
        scanf("%f", &base);
        printf("Enter the height of the triangle (in meters): ");
        scanf("%f", &height);
        printf("Area of Triangle = %.4f square meters\n", 0.5 * base * height);
        break;
    case PERIMETER:
        print("Calculating Triangle Perimeter...");
        printf("Enter the length of the first side (in meters): ");
        scanf("%f", &side1);
        printf("Enter the length of the second side (in meters): ");
        scanf("%f", &side2);
        printf("Enter the length of the third side (in meters): ");
        scanf("%f", &side3);
        printf("Perimeter of Triangle = %.4f meters\n", side1 + side2 + side3);
        break;
    }
}

int getValidInput(int min, int max, char prompt[])
{
    int choice;
    while (1)
    {
        print(prompt);
        printf("matthew %% ");
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max)
            return choice;
        else
            print("Invalid input. Please enter a valid number.");
        while (getchar() != '\n')
            ;
    }
}

void print(char string[])
{
    printf("%s\n", string);
}
