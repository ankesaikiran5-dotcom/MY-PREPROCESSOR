#include <stdio.h>

int remove_comments()
{
    FILE *fp, *out;//fp is the pointer for input file , out is the pointer for output file
    int ch, next;//ch stores current character and next stores next character
    int in_comment = 0;//it identifies the program is currently inside a multi-line comment   0 means outside comment
    
    fp = fopen("input.c", "r");//opening files

    if (fp == 0)//checking file was succesfully opened
    {
        printf("Input file not found\n");
        return 1;
    }

    out = fopen("clean.i", "w");

    if (out == 0)
    {
        printf("Output file cannot be created\n");
        fclose(fp);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (in_comment == 0)
        {
            if (ch == '/')//checks current character 
            {
                next = fgetc(fp);//reads next character and store it into next

                if (next == '/')
                {
                    while ((ch = fgetc(fp)) != EOF && ch != '\n')//it reads and ignores all characters until the newline or end of file
                    {
                    }

                    if (ch == '\n')//preserves line break in the output
                        fputc('\n', out);
                }
                else if (next == '*')//multiline comment
                {
                    in_comment = 1;
                }
                else//normal slash
                {
                    fputc(ch, out);//writes /

                    if (next != EOF)
                        ungetc(next, fp);//pushes the next character back into the input stream so it can be read again
                }
            }
            else//if current character is not a comment marker , the program writes it directly into the output file 
            {
                fputc(ch, out);
            }
        }
        else//this executes in_comment = 1
        {
            if (ch == '*')//checks current character is *
            {
                next = fgetc(fp);

                if (next == '/')//if next character is /, this means comment has ended
                {
                    in_comment = 0;//returns to the normal reading mode
                }
                else
                {
                    if (ch == '\n')
                        fputc('\n', out);//it ignores comment characters but preserves newline characters

                    if (next != EOF)
                        ungetc(next, fp);//it pushes back the character that was read for checking
                }
            }
            else if (ch == '\n')
            {
                fputc('\n', out);//this preserves the line structure even after removing comments
            }
        }
    }
    fclose(fp);
    fclose(out);

    printf("Comments removed successfully!\n");
    printf("Output file: clean.i\n");

    return 0;
}
