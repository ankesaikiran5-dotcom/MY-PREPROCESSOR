#include<stdio.h>
int main()
{
FILE *fp;//it stores information about the opened file
char ch;

fp=fopen("input.c","r");
if(fp==0)//if file cannot be opened , fp will be null
{
printf("File Not Found\n");
return 1;
}
while((ch=fgetc(fp))!=EOF)//loop continues until file ends
{
printf("%c",ch);
}
fclose(fp);
return 0;
}

