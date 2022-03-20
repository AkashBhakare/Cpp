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
    printf("Roll   Name \n");
    printf("------------------\n");
    fscanf(fp,"%d %s",&s.roll,s.name);
    printf("%d %s \n",s.roll,s.name);
	fscanf(fp,"%d %s",&s.roll,s.name);
    printf("%d %s \n",s.roll,s.name); 
	fscanf(fp,"%d %s",&s.roll,s.name);
    printf("%d %s \n",s.roll,s.name);
	fscanf(fp,"%d %s",&s.roll,s.name);
    printf("%d %s \n",s.roll,s.name);
	fscanf(fp,"%d %s",&s.roll,s.name);
    printf("%d %s \n",s.roll,s.name);
    
    
   fclose(fp);
 
      
	return 0;
}

