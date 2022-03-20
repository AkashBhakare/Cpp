#include<stdio.h>
#include<stdlib.h>
//Sample code to read the contents from the file Line by Line using user defined stream. 

int main(void)
{
 	FILE *fp = fopen("D:\\Files\\ABC.txt", "r");
    char data[30];
	if(fp==NULL)
	{
		fprintf(stderr,"Unable to open file");
		exit(EXIT_FAILURE);
	}
  
   fgets(data,30,fp);
   puts(data);
   fgets(data,30,fp);
   puts(data);  	
    fgets(data,30,fp);
   puts(data);  
   
   fclose(fp);
	return(0);
}


