#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"Insuff. arguments passed....");
		exit(1);
	}
	
	printf("SUCCESS");
	
	return 0;
}
