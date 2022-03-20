#include<stdio.h>
#include<stdlib.h>
//Write a C program to Write the contents onto a file and then read back the contents from the file using SINGLE FILE Pointer
//i.e. using a single User Defined Stream. 


int main(void)
{
 	FILE *fp = fopen("D:\\Files\\ABC.txt", "w");
    
	if(fp==NULL)
	{
		fprintf(stderr,"Unable to open file");
		exit(EXIT_FAILURE);
	}
  
  	char data[50] = "This is my smart city Pune.Bazinga...I'm kidding...";
   
   	fputs(data,fp);
   	
    fclose(fp);
    
    system("pause");
    
    printf("\n\nContents of the File are-->\n\n");
    fp = fopen("D:\\Files\\ABC.txt", "r");
    fgets(data,50,fp);
    printf("%s", data);
    
    fclose(fp);
	return(0);
}

 
 
