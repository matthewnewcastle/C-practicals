/*
    Task 1:
        Write a C program to compare two user-defined strings using pointers and
        return whether they are equal or not (without using strcmp()).
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Compares two strings for equality */
bool isEqual(char *str1, char *str2)
{
    if (strlen(str1) != strlen(str2))
        return false;

    printf("Comparing strings '%s' and '%s'...\n", str1, str2);

    for (int i = 0; i < strlen(str1); i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

int main(int argc, char const *argv[])
{
    char str1[] = "Hello";
    char str2[] = "Hello";

    if (isEqual(str1, str2))
        printf("'%s' and '%s' ARE equal.\n", str1, str2);
    else
        printf("'%s' and '%s' are NOT equal.\n", str1, str2);

    return 0;
}
