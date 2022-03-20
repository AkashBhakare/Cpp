#include<stdio.h>

int main()
{
	FILE *fp = fopen("B:\\c programmingNotes\\AS.txt", "wt");
	
	if (fp == NULL)
	{
		fprintf(stderr, "File Opening Error");
		exit(1);
	}
	
	fputs("Impetus", fp);
	
	fclose(fp);
	
	return 0;
	
}
