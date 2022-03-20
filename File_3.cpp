#include<stdio.h>
#include<stdlib.h>

int main()
{
   FILE *fp = NULL;
   fp = fopen("D:\\Files\\lmn.txt","a"); //fp = fopen("D:\Files\abc.txt","at");
   
   if(fp==NULL)
   {
   		fprintf(stderr,"File Opening Error...");
   		exit(1);
   }
   
        //fputs("World",fp);
   
    	printf("File opened successfully...\n");
    //	printf("Contents written to a file...");
   		fclose(fp);

 	
    return 0;
}

