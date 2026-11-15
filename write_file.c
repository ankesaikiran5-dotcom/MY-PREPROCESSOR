#include<stdio.h>
int main()
{
	FILE *fp;

	fp=fopen("output.i","w");
	if(fp==0)
	{
		printf("File cannot be created\n");
		return 1;
	}
	fputs("MY PREPROCESSOR PROJECT\n",fp);
	fputs("Vector India\n",fp);
	fputs("File writing successful\n",fp);

	fclose(fp);
	printf("Output file created successfully\n");
	return 0;
}
