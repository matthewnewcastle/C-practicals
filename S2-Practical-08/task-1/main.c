/*
    This program calculates the area and perimeter of various shapes.
*/

#include <stdio.h>

void print(char string[])
{
    printf("%s\n", string);
}

int getValidChoice();

void optionCircle();
void optionSquare();
void optionRectangle();
void optionTriangle();

int main(int argc, char const *argv[])
{
    int choice;

    while (1)
    {
        print("Select a shape to calculate the area or perimeter");
        print("  1) Circle");
        print("  2) Square");
        print("  3) Rectangle");
        print("  4) Triangle");

        // Keep prompting the user until a valid choice is entered.
        printf("matthew %% ");
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 4)
            break;
        else
            print("Invalid input. Please enter a number between 1 and 4.");
        while (getchar() != '\n')
            ;
    }

    switch (choice)
    {
    case 1: // Circle
        optionCircle();
        break;
    case 2: // Square
        optionSquare();
        break;
    case 3: // Rectangle
        optionRectangle();
        break;
    case 4: // Triangle
        optionTriangle();
        break;
    default:
        break;
    }

    return 0;
}
