#include<stdio.h>
#include<stdlib.h>
 

// Flushing the contents of the Buffer 

int main()
{
	FILE * fp = fopen("D:\\Files\\ABC.txt", "wt");

	if (fp == NULL)
	{
		fprintf(stderr, "File Opening Error");
		exit(1);
	}

	fputs("Its magnifiscent", fp);

//	fflush(fp);

//	fclose(fp);

	
	return 0;
}

/*
cases : 
1. When you explicitly flush the buffer

2. When you disconnect the active stream by calling fclose() function

3. When program terminates (not having fflush() and fclose() functions )

4. When buffer associated with a stream gets completely filled/occupied,
then also buffer gets flushed implicitly


*/
