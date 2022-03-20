#include<stdio.h>
#include<stdlib.h>
struct stud
{
	int roll;
	char name[20];
};
int main(void)
{
 	FILE *fp = fopen("D:\\Files\\student.txt","w");
	if(fp==NULL)
	{
		fprintf(stderr,"Unable to open file...");
		exit(1);
	}
    
 	struct stud s1 = {101,"ABC"};	
 	struct stud s2 = {102,"XYZ"};	
 		
    fprintf(fp,"%d %s\n",s1.roll,s1.name);
    fprintf(fp,"%d %s\n",s2.roll,s2.name);
      
    fclose(fp);
	printf("Data Inserted Successfully...") ;
	
      
	return 0;
}

 
