#include<stdio.h>
#include<stdlib.h>
//Write a C program to Write the contents onto a file and then read back the contents from the file using SINGLE FILE Pointer
//i.e. using a single User Defined Stream. 

// w+ OR wt+ ==> Write + Read mode
// r+ and a+

int main(void)
{
 	FILE *fp = fopen("D:\\Files\\ABC.txt", "w+");
    char ch;
	if(fp==NULL)
	{
		fprintf(stderr,"Unable to open file");
		exit(EXIT_FAILURE);
	}
  
  	printf("Enter the data till '#' :: ");
  	
  	ch = getchar();
  	while(ch != '#')
  	{
  		fputc(ch,fp);	
  		ch = getchar();
	}
	
    printf("Data inserted into a file...\n\n");
    
    rewind(fp); //Bringing the file pointer to the initial position of the file. 
    
    printf("\nReading back the data from the file...\n\n");
    fp = fopen("D:\\Files\\ABC.txt", "r");
    ch = fgetc(fp);
    
    while(ch!=EOF)
    {
    	putchar(ch);
        ch = fgetc(fp);	
	}
    
      fclose(fp);
      
	return(0);
}

 
