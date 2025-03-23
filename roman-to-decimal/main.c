#include <stdio.h>
#include <string.h>

// Function to get the decimal value of a single Roman numeral
int romanToInt(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    default:
        return 0; // Invalid character case
    }
}

// Function to convert a Roman numeral string to decimal
int convertRomanToDecimal(const char *roman)
{
    int total = 0;
    int prevValue = 0;

    for (int i = strlen(roman) - 1; i >= 0; i--)
    {
        int currentValue = romanToInt(roman[i]);
        if (currentValue < prevValue)
        {
            total -= currentValue; // Apply subtraction rule
        }
        else
        {
            total += currentValue;
        }
        prevValue = currentValue;
    }

    return total;
}

int main()
{
    char roman[20];
    printf("Enter a Roman numeral (I, V, X, L, C): ");
    scanf("%s", roman);

    int decimalValue = convertRomanToDecimal(roman);
    printf("Decimal equivalent: %d\n", decimalValue);
}