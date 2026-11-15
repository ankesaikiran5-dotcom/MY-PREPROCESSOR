#include <stdio.h>
#include <string.h>//it provides string handling functions
#include <ctype.h>//it provides character handling functions

int substitute_macros()
{
    FILE *fp, *fout;

    char line[200];//creates a char array
    char macro_name[20][50];//2d char array to store 20 macro names
    char macro_value[20][50];//to store corresponding macro value

    char token[200];//store one complete identifier extracted from the input line

    int count = 0;//to count number of macro macro definitions are stored
    int i, j, k;
    int found;//to check macro found or not
    fp = fopen("input2.c", "r");
    fout = fopen("output1.i", "w");
    if (fp == 0 || fout == 0)
    {
        printf("File opening failed\n");
        if (fp != 0)//check whether input file was opened successfully
            fclose(fp);//closes the input file it was opened 
        if (fout != 0)
            fclose(fout);
        return 1;
    }
    while (fgets(line, sizeof(line), fp))//reads the input file one line at a time
    {
        if (strncmp(line, "#define", 7) == 0)//checks whether the current line begins with #define
        {
            if (count < 20 && sscanf(line, "#define %49s %49s",macro_name[count],macro_value[count]) == 2)
            {
                count++;//increases the macro count by one
            }
        }
    }
    rewind(fp);//Move file pointer to beginning
    while (fgets(line, sizeof(line), fp))//read the input file again, one line at a time
    {
        if (strncmp(line, "#define", 7) == 0)//check whether the current line is a macro definition
        {
            continue;
        }
        i = 0;//start reading the current line from the first character
        while (line[i] != '\0')//continues until the null character is reached, \0 marks the end of a string
        {
            if (isalpha((unsigned char)line[i]) || line[i] == '_')//check whether current character starts a C identifier
            {
                j = 0;//starts storing the identifier from the beginning of the token array
                while (isalnum((unsigned char)line[i]) || line[i] == '_')//continues reading chars while they are alphabets,numbers,underscore
                {
                    token[j++] = line[i++];//copies the current character into token then increases both j and i by one
                }
                token[j] = '\0';//adds the string ending character
                found = 0;//initially assume that the identifier is not a macro
                for (k = 0; k < count; k++)//check all stored macro names one by one
                {
                    if (strcmp(token, macro_name[k]) == 0)//compares the extracted identifier with the stored macro name
                    {
                        fputs(macro_value[k], fout);//writes corresponding macro value into the output file 
                        found = 1;//it indicates that a matching macro was found
                        break;//stops the for loop after finding the matching macro
                    }
                }
                if (found == 0)//if no macro matches write original identifier into the output file
                {
                    fputs(token, fout);
                }
            }
            else
            {
                fputc(line[i], fout);//copy other characters
                i++;
            }
        }
    }

    fclose(fp);
    fclose(fout);

    printf("Macro substitution completed successfully\n");

    return 0;
}
