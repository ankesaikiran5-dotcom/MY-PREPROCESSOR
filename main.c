#include <stdio.h>

int remove_comments();
int include_files();
int substitute_macros();
int substitute_function_macro();

int main()
{
    int choice;

    printf("\n===== MY PREPROCESSOR PROJECT =====\n");
    printf("1. Comment Removal\n");
    printf("2. File Inclusion\n");
    printf("3. Object-like Macro Substitution\n");
    printf("4. Function-like Macro Substitution\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
        case 1:
            remove_comments();
            break;

        case 2:
            include_files();
            break;

        case 3:
            substitute_macros();
            break;

        case 4:
            substitute_function_macro();
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

