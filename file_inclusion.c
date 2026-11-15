#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp, *fheader, *fout;
    char line[200];
    char filename[100];
    char headerline[200];
    fp = fopen("input1.c", "r");//open input file

    if (fp == 0)//checks whether opening the input file failed
    {
        printf("Input file not found\n");
        return 1;
    }
    fout = fopen("output.i", "w");//open output file

    if (fout == 0)//checks whether the output file opened successfully
    {
        printf("Output file cannot be created\n");
        fclose(fp);
        return 1;
    }
    while (fgets(line, sizeof(line), fp))//read input file line by line
    {
        if (strstr(line, "#include") != 0)//check    for include statement
        {
            if (sscanf(line, " #include \"%99[^\"]\"", filename) == 1)//extract header filename
            {
                fheader = fopen(filename, "r");//open header file
                if (fheader == 0)
                {
                    printf("Header file not found: %s\n",filename);
                    continue;
                }
                while (fgets(headerline,sizeof(headerline), fheader))//read header file contents
                {
                    fputs(headerline, fout);//write header file contents
                }
                fclose(fheader);
            }
            else//if current line does not contain #include , it writes that line into output.i
            {
                fputs(line, fout);//copy unsupported include statements
            }
        }
        else
        {
            fputs(line, fout);//copy normal c code
       }
    }
    fclose(fp);
    fclose(fout);

    printf("File inclusion completed successfully!\n");

    return 0;
}
