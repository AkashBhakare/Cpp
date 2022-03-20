#include<stdio.h>
#include<stdlib.h>
//Sample code to read the contents from the file string by string using user defined stream. 

int main(void)
{
 	FILE *fp = fopen("D:\\Files\\ABC.txt", "r");
    char data[10];
	if(fp==NULL)
	{
		fprintf(stderr,"Unable to open file");
		exit(EXIT_FAILURE);
	}
 
 	//scanf("%s", data);
 	fscanf(fp,"%s",data);
	puts(data);
	fscanf(fp,"%s",data);	
	puts(data);
	fscanf(fp,"%s",data);	
	puts(data);	
	fscanf(fp,"%s",data);	
	puts(data);	
		
	fclose(fp);
	return(0);
}

 
