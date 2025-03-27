#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    int rollNumber;
    float marks;
};

int main()
{
    struct Student student;
    char input[50];

    // Get name
    do
    {
        printf("Enter the name of the student: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        if (strlen(input) == 0)
            printf("Name cannot be empty. Please enter a valid name.\n");
        else
        {
            strcpy(student.name, input);
            break;
        }
    } while (1);

    // Get roll number
    do
    {
        printf("Enter the roll number of the student: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &student.rollNumber) != 1)
            printf("Invalid input. Please enter a valid number.\n");
        else
            break;
    } while (1);

    // Get marks
    do
    {
        printf("Enter the marks of the student: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &student.marks) != 1)
            printf("Invalid input. Please enter a valid number.\n");
        else
            break;
    } while (1);

    printf("\nStudent Information:\n");
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Marks: %.2f\n", student.marks);

    return 0;
}