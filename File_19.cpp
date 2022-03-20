#include<stdio.h>
#include<stdlib.h>
//Writing the contents into  a file using fprintf() function 

struct stud
{
	int roll;
	char name[20];
}s;
int main(void)
{
 	FILE *fp = fopen("D:\\Files\\student.txt","a");
	if(fp==NULL)
	{
		fprintf(stderr,"Unable to open file...");
		exit(1);
	}
    
    char wish;
	
	do
	{
		printf("\nEnter Records ::");
		printf("\nEnter Roll No.::"); scanf("%d", &s.roll);
		printf("\nEnter Name ::"); scanf("%s", s.name);
		fprintf(fp,"%d %s\n",s.roll,s.name);
		printf("\nWould like to insert another record(y/n) ? ::");
		wish = getche();
	}while(wish=='y' || wish=='Y');  
      

    fclose(fp);
	printf("Data Inserted Successfully...") ;
	
      
	return 0;
}

 
 
 
