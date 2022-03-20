#include<stdio.h>
#include<stdlib.h>

int main()
{
   FILE *fp = NULL;
   fp = fopen("D:\\ABC.txt","r"); 
   
   if(fp==NULL)
   {
   		fprintf(stderr,"File Opening Error...");
   		exit(1);
   }
    
	printf("File opened successfully...\n");
   	
	int status = fclose(fp); //ON Success, return the value ZERO, else other value on Failure
	
	printf("Value of status = %d \n", status);
	
	if(status==0)
		printf("File closed successfully...");
	else
		printf("File closing error...");
		
 	
    return 0;
}
