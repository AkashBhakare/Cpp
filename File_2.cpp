#include<stdio.h>
#include<stdlib.h>

int main()
{
   FILE *fp = NULL;
   fp = fopen("D:\\Files\\abc.txt","r"); //fp = fopen("D:\Files\abc.txt","rt");
   
   if(fp==NULL)
   {
   		fprintf(stderr,"File Opening Error...");
   		exit(1);
   }
   else
   {
   		printf("File opened successfully...");
   		fclose(fp);
   }
 	
    return 0;
}

