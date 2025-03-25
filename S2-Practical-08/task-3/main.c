#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    printf("Pre-swap: a=%d, b=%d\n", *a, *b);

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

    printf("Post-swap: a=%d, b=%d\n", *a, *b);
}

/* Function to ensure valid integer input */
void getValidInt(const char *prompt, int *num)
{
    int valid;
    do
    {
        printf("%s", prompt);
        valid = scanf("%d", num);
        while (getchar() != '\n')
            ; // Clear the buffer
    } while (valid != 1);
}

int main()
{
    bool running = true;
    char response;

    while (running)
    {
        printf("Do you want to perform the swap? (y/n): ");
        scanf(" %c", &response); // Space before %c to skip any leading whitespace

        if (response == 'n' || response == 'N')
        {
            running = false;
            break;
        }
        else if (response == 'y' || response == 'Y')
        {
            int a, b;
            getValidInt("a: ", &a);
            getValidInt("b: ", &b);

            swap(&a, &b);
        }
        else
        {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }

    return 0;
}
