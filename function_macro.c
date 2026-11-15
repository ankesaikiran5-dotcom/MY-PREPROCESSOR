#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int substitute_function_macro()
{
    char macro[200];//stores macro definition
    char name[50];//stores macro name
    char params[100];//stores formal params
    char replacement[100];//stores replacement expression
    char input[200];//stores function like macro call
    char output[500] = "";//stores expanded expression

    char actual[10][50];//stores actual arguments
    char formal[10][50];//stores formal arguments

    int i, j;//used for counting and looping
    int count = 0;//it tracks the number of formal arguments

    printf("Enter macro definition:\n");//reading input from user
    fgets(macro, sizeof(macro), stdin);

    printf("Enter input expression:\n");//reads function call
    fgets(input, sizeof(input), stdin);

    sscanf(macro, "#define %49[^ (]", name);
char *open = strchr(macro, '(');
char *close = NULL;

if (open != NULL)//finding the closing parantheses,checks whether the opening parantheses was found
    close = strchr(open + 1, ')');

if (open == NULL || close == NULL)//opening parantheses was not found,closing parantheses was not found
{
    printf("Invalid macro definition\n");
    return 1;//terminates the program with an error status
}

int param_len = close - open - 1;//calculates the no, of chars between the opening and closing parantheses

if (param_len >= sizeof(params))//checking parameter buffer size
{
    printf("Invalid macro definition\n");
    return 1;
}

strncpy(params, open + 1, param_len);//copying parameters
params[param_len] = '\0';

for (i = 0; params[i] != '\0'; i++)
{
    if (!(isalnum((unsigned char)params[i]) || params[i] == '_' || params[i] == ',' || isspace((unsigned char)params[i])))
    {
        printf("Invalid macro definition\n");
        return 1;
    }
}

strcpy(replacement, close + 1);    

    strcpy(replacement, close + 1);//it copies the replacement expression into replacement

    memmove(replacement, replacement + strspn(replacement, " \t"),strlen(replacement + strspn(replacement, " \t")) + 1);
    
    char *token = strtok(params, ",");//splitting formal arguments

    while (token != NULL && count < 10)//repeats while a token exists and fewer than 10 parameters have been stored
    {
        sscanf(token, " %49s", formal[count]);//copies the token into the formal parameter array
        count++;//increases the count
        token = strtok(NULL, ",");//gets the next token
    }
//finding actual arguments
    char *arg_open = strchr(input, '(');//finds the first opening parantheses
    char *arg_close = strrchr(input, ')');//finds the last closing parantheses

    if (arg_open == NULL || arg_close == NULL || arg_close < arg_open)//checks whether the input expression contains the required parantheses
    {
        printf("Invalid input expression\n");
        return 1;
    }

    char arg_text[200];//creates a character array to store actual arguments

    strncpy(arg_text, arg_open + 1, arg_close - arg_open - 1);//copies the text inside the parantheses
    arg_text[arg_close - arg_open - 1] = '\0';
    // Split actual arguments
    int actual_count = 0;//counts the actual arguments
    token = strtok(arg_text, ",");//it separates aruments using commas

    while (token != NULL && actual_count < 10)//stores actual arguments
    {
        sscanf(token, " %49s", actual[actual_count]);
        actual_count++;
        token = strtok(NULL, ",");
    }

    if (actual_count != count)//checking argument count
    {
        printf("Argument count mismatch\n");
        return 1;
    }
    // Perform substitution
    for (i = 0; replacement[i] != '\0';)//this reads the replacement expression char by char until it reaches end
    {
        if (isalpha((unsigned char)replacement[i]) || replacement[i] == '_')//checks whether the current char is a letter or underscore
        {
            char word[50];//stores current identifier
            int len = 0;//count its character

            while (isalnum((unsigned char)replacement[i]) || replacement[i] == '_')//it collects the complete identifier
            {
                if (len < 49)
                    word[len++] = replacement[i];

                i++;
            }

            word[len] = '\0';//terminates the extracted word

            int found = 0;//creates a flag

            for (j = 0; j < count; j++)//actual replacement process
            {
                if (strcmp(word, formal[j]) == 0)
                {
                    strcat(output, actual[j]);
                    found = 1;
                    break;
                }
            }

            if (!found)//if word is not a formal parameter,it is copied unchanged
                strcat(output, word);
        }
        else//this handles non identifier chars
        {
            int len = strlen(output);
            output[len] = replacement[i];
            output[len + 1] = '\0';
            i++;
        }
    }

    printf("\nMacro name: %s", name);
    printf("\nExpanded expression: %s\n", output);

    return 0;
}
