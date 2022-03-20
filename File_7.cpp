#include<stdio.h>
#include<stdlib.h>

//File Copy Program

int main(void)
{
 	FILE *sf = fopen("D:\\ABC.txt", "r");
 	FILE *df = fopen("D:\\ABC.txt", "w");
	char ch;
	
	if(sf==NULL || df==NULL)
	{
		fprintf(stderr,"Unable to open file");
		exit(EXIT_FAILURE);
	}
	
	//code to read the contents from the file 
	
	ch = fgetc(sf);
	while(ch != EOF)
	{
		fputc(ch,df);
		ch = fgetc(sf);
	}
	
	int st1 = fclose(sf);
	int st2 = fclose(df);
	
	if(st1==0 && st2==0)
		printf("Data Copied and Streams are closed...\n");
	else
		printf("File Closing Error...\n");
	
	return(0);
}

 
