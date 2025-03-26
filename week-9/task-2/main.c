/*
    Task 2:
        Write a C program to concatenate two user-defined strings
        using a) strcat() function, b) pointers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Concatenates two strings using strcat() */
char *concat_strcat(const char *s1, const char *s2)
{
    int size = strlen(s1) + strlen(s2) + 1; // +1 for '\0'
    char *result = malloc(size);

    if (result == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strcpy(result, s1); // Copy first string
    strcat(result, s2); // Then append the second string

    return result;
}

/* Concatenates two strings using pointers */

char *concat_pointers(const char *s1, const char *s2)
{
    int size = 0;

    // Find lengths manually using pointers
    const char *temp = s1;
    while (*temp++)
        size++; // Length of s1

    temp = s2;
    while (*temp++)
        size++; // Length of s2

    char *result = malloc(size + 1); // Allocate memory for concatenated string

    if (result == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    char *ptr = result;

    // Copy s1 using pointer
    while (*s1)
    {                   // Loop until we reach the null terminator of s1
        *ptr++ = *s1++; // Copy current character from s1 to result, then move both pointers
    }

    // Copy s2 using pointer
    while (*s2)
        *ptr++ = *s2++;

    *ptr = '\0'; // Null-terminate the result

    return result;
}
int main(int argc, char const *argv[])
{
    char s1[] = "Hello";
    char s2[] = ", World!";

    printf("\nConcatenating strings '%s' and '%s' using strcat()...\n", s1, s2);

    char *result = concat_strcat(s1, s2);
    if (result != NULL)
    {
        printf("Concatenated String: %s\n\n", result);
        free(result); // Free dynamically allocated memory
    }

    char s3[] = "Hello";
    char s4[] = ", World!";

    printf("\nConcatenating strings '%s' and '%s' using pointers...\n", s1, s2);
    char *result2 = concat_pointers(s3, s4);
    if (result2 != NULL)
    {
        printf("Concatenated String: %s\n\n", result2);
        free(result2); // Free dynamically allocated memory
    }

    return 0;
}
