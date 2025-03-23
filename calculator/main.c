#include <stdio.h>
#include <stdlib.h> // For system()
#include <math.h>   // For floor()

void clearScreen()
{
    system("clear");
}

void printNumber(double num)
{
    if (floor(num) == num)
    {
        printf("%.0lf", num); // Print as integer if no decimal part
    }
    else
    {
        printf("%.2lf", num);
    }
}

int main()
{
    clearScreen();

    double num1, num2, result;
    char op;

    // Read input in the format "2.5 * 3.2"
    printf("Enter an expression: ");
    if (scanf("%lf %c %lf", &num1, &op, &num2) != 3)
    {
        printf("Invalid input format!\n");
        return 1;
    }

    // Perform the operation
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Error: Division by zero!\n");
            return 1;
        }
        result = num1 / num2;
        break;
    default:
        printf("Invalid operator!\n");
        return 1;
    }

    // Print the result
    printf("Result: ");
    printNumber(num1);
    printf(" %c ", op);
    printNumber(num2);
    printf(" = ");
    printNumber(result);
    printf("\n");

    return 0;
}
