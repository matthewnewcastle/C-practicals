#include <stdio.h>
#include <stdlib.h>

/* Function to ensure valid integer input for array elements */
int getValidInt(const char *prompt)
{
    int num, valid;
    do
    {
        printf("%s", prompt);
        valid = scanf("%d", &num);
        while (getchar() != '\n')
            ; // Clear the buffer

        if (valid != 1)
        {
            printf("Invalid input. Please enter a valid integer.\n");
        }
    } while (valid != 1);

    return num;
}

/* Function to display an array in {1, 2, 3, 4} format */
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

/* Function to create and return an array */
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

/* Function to get the larger array */
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

/* Function to create and return the k array */
int *createKArray(int *m, int mSize, int *n, int nSize, int *kSize)
{
    // Determine the larger size for k
    *kSize = (mSize > nSize) ? mSize : nSize;
    int *k = (int *)malloc(*kSize * sizeof(int));
    if (k == NULL)
    {
        printf("Memory allocation failed for k.\n");
        exit(1);
    }

    // Get the smaller array's size
    int smallerArraySize = (mSize < nSize) ? mSize : nSize;

    // Populate the elements of k
    for (int i = 0; i < *kSize; i++)
    {
        if (i < smallerArraySize)
        {
            k[i] = m[i] + n[i];
        }
        else
        {
            // Once i is larger than the smaller array, fill the remaining elements from the larger array
            k[i] = (mSize > nSize) ? m[i] : n[i];
        }
    }
    return k;
}

int main()
{
    // ============ Create m & n arrays ============ //

    int mSize = getValidInt("\nm array size: ");
    while (mSize <= 0) // Ensure the size is positive
    {
        printf("Array size must be a positive integer.\n");
        mSize = getValidInt("m array size: ");
    }

    int *m = createArray(mSize);
    printf("\nm = ");
    displayArray(m, mSize);

    int nSize = getValidInt("\nn array size: ");
    while (nSize <= 0) // Ensure the size is positive
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

    int element = getValidInt("\nEnter an int to search for: ");
    // Check for element in m

    // Check for element in n

    // Free allocated memory
    free(m);
    free(n);
    free(k);

    return 0;
}
