#include<stdio.h>
#include<stdlib.h>
//Reading an integer value in  a Binary File
int main(void)
{
	
	FILE *fp = fopen("D:\\Files\\data1.txt", "rb"); 
	int xnum;
	
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
	
	int cnt = fread(&xnum,sizeof(int),1,fp);
	
	printf("\nfread function read %d record(s) successfully...", cnt);
	printf("\nValue of xnum = %d \n", xnum);
	
    fclose(fp);
    
  return 0;
}




