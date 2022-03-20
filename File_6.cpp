#include<stdio.h>
#include<stdlib.h>
/*Reading the contents from the user defined stream char by char and Writing them onto a standard output stream(Monitor) chat by char */ 
 
 
int main()
{
   FILE *fp = NULL;
   char ch;  //int ch;
   fp = fopen("D:\\Files\\source.txt","r"); 
   
   if(fp==NULL)
   {
   		fprintf(stderr,"File Opening Error...");
   		exit(1);
   }
    printf("\nContents of the File are ::\n\n");
    
	ch = fgetc(fp);
	while(ch != EOF) //while(ch != -1)
	{
		//putchar(ch); //associated with standard output stream
		//fputc(ch,stdout);
		 //putc(ch, stdout);
		 printf("%c", ch);
		 
		ch = fgetc(fp);
	}

	int status = fclose(fp); 

	if(status==0)
		printf("\n\nFile Closed successfully...");
	else
		printf("\n\nFile closing error...");
		
 	
    return 0;
}

