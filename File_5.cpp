#include<stdio.h>
#include<stdlib.h>
/*Reading the contents from the keyboard using STDIN stream char by char and Writing them onto a FILE using 
 user defined stream chat by char */ 
 
 
int main()
{
   FILE *fp = NULL;
   char ch;  //int ch;
   fp = fopen("D:\\ABC.txt","w"); 
   
   if(fp==NULL)
   {
   		fprintf(stderr,"File Opening Error...");
   		exit(1);
   }
    printf("Write the contents onto a file till '#' :: \n");
	
	//ch = getchar();  //default associated with STDIN 
	//ch = fgetc(stdin);
	 ch = getc(stdin);   
	while(ch != '#')
	{
		//fputc(ch,fp); // fp is a user defined stream , fputc() ==> is a function
		  putc(ch,fp); //putc() ==> Macro 
		  ch = getchar();//#
	}

	int status = fclose(fp); 

	if(status==0)
		printf("Content written onto a File and File Closed successfully...");
	else
		printf("File closing error...");
		
 	
    return 0;
}
