/*
 * Program: Array Operations
 * Description: This program performs various operations on arrays,
 *              including creation, element search, and combination.
 * Name: Matthew Williamson
 * ID: 240674999
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Function: getValidInt
 * ----------------------
 * Ensures valid integer input by repeatedly prompting the user until
 * a valid integer is entered.
 *
 * Parameters:
 *      prompt - The message displayed to the user for input.
 *
 * Returns:
 *      The validated integer input.
 */
int getValidInt(const char *prompt)
{
    int num, valid;
    do
    {
        printf("%s", prompt);
        valid = scanf("%d", &num);
        while (getchar() != '\n')
            ; // Clear input buffer

        if (valid != 1)
        {
            printf("Invalid input. Please enter a valid integer.\n");
        }
    } while (valid != 1);

    return num;
}

/*
 * Function: displayArray
 * ----------------------
 * Prints the elements of an array in a formatted {1, 2, 3} style.
 *
 * Parameters:
 *      arr  - The array to be displayed.
 *      size - Number of elements in the array.
 */
void displayArray(int arr[], int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("}\n");
}

/*
 * Function: createArray
 * ----------------------
 * Dynamically allocates an array of integers and populates it with user input.
 *
 * Parameters:
 *      size - The number of elements in the array.
 *
 * Returns:
 *      A pointer to the allocated and initialized array.
 */
int *createArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        arr[i] = getValidInt("");
    }
    return arr;
}

/*
 * Function: getLargerArray
 * ----------------------
 * Determines which of two arrays is larger and returns it.
 * Also returns the smaller array and its size via pointers.
 *
 * Parameters:
 *      arr1, arr2  - The two arrays.
 *      size1, size2 - The sizes of the arrays.
 *      smallerArray - Pointer to store the smaller array.
 *      smallerSize  - Pointer to store the size of the smaller array.
 *
 * Returns:
 *      The pointer to the larger array.
 */
int *getLargerArray(int *arr1, int size1, int *arr2, int size2, int **smallerArray, int *smallerSize)
{
    if (size1 > size2)
    {
        *smallerArray = arr2;
        *smallerSize = size2;
        return arr1;
    }
    else
    {
        *smallerArray = arr1;
        *smallerSize = size1;
        return arr2;
    }
}

/*
 * Function: createKArray
 * ----------------------
 * Creates an array k based on two input arrays. Elements are summed
 * if both arrays have corresponding indices; otherwise, extra elements
 * from the larger array are appended.
 *
 * Parameters:
 *      m, n  - The two input arrays.
 *      mSize, nSize - The sizes of the input arrays.
 *      kSize  - Pointer to store the size of the resulting array.
 *
 * Returns:
 *      A dynamically allocated array k.
 */
int *createKArray(int *m, int mSize, int *n, int nSize, int *kSize)
{
    *kSize = (mSize > nSize) ? mSize : nSize;
    int *k = (int *)malloc(*kSize * sizeof(int));
    if (k == NULL)
    {
        printf("Memory allocation failed for k.\n");
        exit(1);
    }

    int smallerArraySize = (mSize < nSize) ? mSize : nSize;

    for (int i = 0; i < *kSize; i++)
    {
        if (i < smallerArraySize)
        {
            k[i] = m[i] + n[i];
        }
        else
        {
            k[i] = (mSize > nSize) ? m[i] : n[i];
        }
    }
    return k;
}

/*
 * Function: searchForElementInArray
 * ----------------------
 * Searches for an element in an array and prints whether it was found.
 * If not found, the function also prints the array.
 *
 * Parameters:
 *      arr     - The array to search.
 *      size    - The size of the array.
 *      element - The element to search for.
 */
void searchForElementInArray(int *arr, int size, int element)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            found = true;
            break;
        }
    }

    if (found)
        printf("Element %d found in the array.\n", element);
    else
    {
        printf("Element %d not found in the array: ", element);
        displayArray(arr, size);
    }
}

/*
 * Function: main
 * ----------------------
 * The main function where user input is taken to create arrays,
 * merge them, and search for a user-specified element.
 */
int main()
{
    // ============ Create m & n arrays ============ //
    int mSize = getValidInt("m array size: ");
    while (mSize <= 0)
    {
        printf("Array size must be a positive integer.\n");
        mSize = getValidInt("m array size: ");
    }

    int *m = createArray(mSize);
    printf("\nm = ");
    displayArray(m, mSize);

    int nSize = getValidInt("\nn array size: ");
    while (nSize <= 0)
    {
        printf("Array size must be a positive integer.\n");
        nSize = getValidInt("n array size: ");
    }

    int *n = createArray(nSize);
    printf("\nn = ");
    displayArray(n, nSize);

    // ============ Create k array ============ //
    int kSize;
    int *k = createKArray(m, mSize, n, nSize, &kSize);
    printf("\nCreated array k = ");
    displayArray(k, kSize);

    // ============ Input element and search ============ //
    int element = getValidInt("\nEnter an integer to search for in m & n: ");

    printf("\nSearching for %d in m = ", element);
    displayArray(m, mSize);
    searchForElementInArray(m, mSize, element);

    printf("\nSearching for %d in n = ", element);
    displayArray(n, nSize);
    searchForElementInArray(n, nSize, element);

    // Free allocated memory
    free(m);
    free(n);
    free(k);

    return 0;
}
