#include<stdio.h>
#include<stdlib.h>
//Writing an integer value in  a Binary File
int main(void)
{
	int num = 56781245;
	
	FILE *fp = fopen("D:\\Files\\data1.txt", "wb"); 
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
	
	int cnt = fwrite(&num,sizeof(int),1,fp);
	
	printf("\nTotal Record inserted = %d \n", cnt);
	
//	int  fwrite(const void * __restrict__ _Str, int _Size, int _Count,  FILE * __restrict__ _File);
	
    fclose(fp);
    
  return 0;
}

