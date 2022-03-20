#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int main(void)
{
	
	FILE *fp = fopen("D:\\Files\\data3.txt", "rb"); 
	
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
 
 	int arr2[SIZE];
 	int cnt2 = fread(arr2,sizeof(int),5,fp); 
    
    printf("Total records read back from the file = %d \n", cnt2);
    int i;
    
    printf("\nPrinting the fetched records from the Binary File \n");
    for(i=0;i<cnt2;++i)
	{
		printf("%d  ", arr2[i]);
	}
    
    
    fclose(fp);
    
  return 0;
}

