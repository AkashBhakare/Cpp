#include<stdio.h>
#include<stdlib.h>
////Program to count number of words available in a file. 

int main(void)
{
 	FILE *fp = fopen("D:\\Files\\ABC.txt", "r");
    char data[10];
	if(fp==NULL)
	{
		fprintf(stderr,"Unable to open file");
		exit(EXIT_FAILURE);
	}
 	int word_count = 0;
	while(!feof(fp))
	{
		fscanf(fp,"%s",data);
		++word_count;
	}
	
	printf("Total Words = %d \n", word_count);
	
	fclose(fp);
	return(0);
}

 
 
 
