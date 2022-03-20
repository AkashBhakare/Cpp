#include<stdio.h>
#include<stdlib.h>
//Reading the contents from a file using fscanf() function 
//Searching Program roll number-wise. 

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

	rewind(fp); //bringing the file pointer to the beginning of the file 
	
	int search;
	int flag=0;
	
	printf("\nEnter the Roll number to be searched :: ");
	scanf("%d", &search);//108
	
	while((fscanf(fp,"%d %s",&s.roll,s.name)) != EOF)
	{
		if(s.roll==search)
		{
			printf("Roll   Name \n");
    		printf("------------------\n");
			printf("%d  %s \n",s.roll,s.name);
			flag = 1;
			break;
		}	
	}
	
	if(flag==0)
		printf("\nRecord with roll number %d does not exist\n", search);

   fclose(fp);
 
      
	return 0;
}

 
 
 
 
