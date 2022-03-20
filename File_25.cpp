#include<stdio.h>
#include<stdlib.h>
//Writing an integer value followed by double value in a Binary File
int main(void)
{
	
	FILE *fp = fopen("D:\\Files\\data2.txt", "wb"); 
	int roll = 101;
	double salary = 45788.24;
	
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
 
 	fwrite(&roll,sizeof(int),1,fp);
 	fwrite(&salary,sizeof(double),1,fp);
    
    fclose(fp);
    
  return 0;
}




