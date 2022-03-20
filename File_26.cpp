#include<stdio.h>
#include<stdlib.h>
//Reading back an integer value followed by double value from  a Binary File
int main(void)
{
	
	FILE *fp = fopen("D:\\Files\\data2.txt", "rb"); 
	
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
 
 	int empID;
 	double empSalary;
 	
    fread(&empID,sizeof(int),1,fp);
 	fread(&empSalary,sizeof(double),1,fp);
    //fread(&empID,sizeof(int),1,fp);
    
    
    printf("ID = %d \n", empID);
    printf("Salary = %.2lf \n", empSalary);
    
    fclose(fp);
    
  return 0;
}

