#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int main(void)
{
	
	FILE *fp = fopen("D:\\Files\\data3.txt", "wb"); 
	
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
 
 	int arr1[SIZE] = {10,20,30,40,50}; // int arr1[5] = {10,20,30,40,50};
 	int cnt1 = fwrite(arr1,sizeof(int),SIZE,fp); 
    
    printf("fwrite function has successfully inserted %d record(s) into a file... \n", cnt1);
    fclose(fp);
    
  return 0;
}

