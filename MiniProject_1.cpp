#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int roll;
	char name[20];
	char city[20];
	float per;
}st;

void insertRecord(const char * fname)
{
	FILE *fp = fopen(fname, "ab");
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
	printf("\nEnter Roll No ::"); scanf("%d", &st.roll);
	printf("\nEnter Name ::"); scanf("%s", st.name);
	printf("\nEnter City ::"); scanf("%s", st.city);
	printf("\nEnter Percentage ::"); scanf("%f", &st.per);
	fwrite(&st, sizeof(struct student), 1, fp);
	fclose(fp);
}

void displayAllRecord(const char * fname)
{
	FILE *fp = fopen(fname, "rb");
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
	
	printf("\nRoll  Name   City    Percentage \n");
	printf("-----------------------------------\n");
	do
	{
		fread(&st, sizeof(struct student), 1, fp);
		if (!feof(fp))
		{
			printf("%d %s %s  %.2f\n", st.roll, st.name, st.city, st.per);
		}
	} while (!feof(fp));

	fclose(fp);
}

void searchByCity(const char * fname)
{
	FILE *fp = fopen(fname, "rb");
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
	
	fseek(fp, 0 ,SEEK_END);
	
	if(ftell(fp)==0)
	{
		printf("No records available. File is EMpty...\n");
		return;
	}
	
	fseek(fp, 0 ,SEEK_SET);
	char search[20];
	int flag = 0;
	printf("\nEnter city name to be searched :");
	scanf("%s", search);
	do
	{
		fread(&st, sizeof(struct student), 1, fp);
		if (!feof(fp))
		{
			if (stricmp(search, st.city) == 0)
			{
				printf("%d  %s \n", st.roll, st.name);
				flag = 1;
			}
		}
	}while(!feof(fp));
	
	if(flag==0)
		printf("\nNo records of the city %s available in the file", search);
		
		
	

	fclose(fp);
}


void updateRecord(const char * fname)
{
	FILE *fp = fopen(fname, "rb+");
	if(fp==NULL)
	{
		fprintf(stderr,"File Opening Error...");
		exit(1);
	}
	fseek(fp, 0 ,SEEK_END);
	if(ftell(fp)==0)
	{
		printf("No records available. File is EMpty...\n");
		return;
	}
	
	fseek(fp,0,SEEK_SET);
	int myroll, flag=0;
	char new_city[20];
	printf("\nEnter Roll No. to be Searched ::");
	scanf("%d", &myroll);//103

	do
	{
		fread(&st, sizeof(struct student), 1, fp);
		if (!feof(fp))
		{
			if(myroll == st.roll)
			{
				printf("\nEnter the New City Name ::");
				scanf("%s", new_city);
				strcpy(st.city,new_city);
				fseek(fp,-sizeof(struct student),SEEK_CUR);
				fwrite(&st,sizeof(struct student),1,fp);
				flag = 1;
				break;
			}
		}
	} while (!feof(fp));
		
	if(flag==0)
		printf("\nNO record with roll number %d found in the file\n", myroll);
		
	fclose(fp);
	
}



int main()
{
	const char filename[80] = "d:\\stud_record.txt";

	//insertRecord(filename);
	//insertRecord(filename);
	displayAllRecord(filename);
    searchByCity(filename);
	updateRecord(filename);
	printf("\n\n");
	printf("\nAFTER Updations::\n");
	displayAllRecord(filename);
	return 0;
}


	//remove(s.txt);
	//rename(d.txt,s.txt);

