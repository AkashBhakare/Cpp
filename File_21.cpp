#include<stdio.h>
#include<stdlib.h>
//Reading the contents from a file using fscanf() function 

struct stud
{
	int roll;
	char name[20];
}s;

int main(void)
{
 	FILE *fp = fopen("D:\\Files\\student.txt","r");
	if(fp==NULL)
	{
		fprintf(stderr,"Unable to open file...");
		exit(1);
	}
	printf(": SUMMARY :\n");
    printf("Roll   Name \n");
    printf("------------------\n");

	while((fscanf(fp,"%d %s",&s.roll,s.name)) != EOF)
	{
		printf("%d  %s \n",s.roll,s.name);
	}

   fclose(fp);
 
      
	return 0;
}

 
