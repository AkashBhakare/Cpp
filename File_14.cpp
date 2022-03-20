
/*
#include<stdio.h>
#include<stdlib.h>
//Program to count number of lines available in a file. 

int main(void)
{
 	FILE *fp = fopen("D:\\Files\\ABC.txt", "r");
    char data[30];
	if(fp==NULL)
	{
		fprintf(stderr,"Unable to open file");
		exit(EXIT_FAILURE);
	}
  
   int line_counter=0;
  
  while(!feof(fp))
  {
  	fgets(data,30,fp);	
  	++line_counter;
  }
   
   printf("Total Lines = %d \n", line_counter);
   
   fclose(fp);
   
	return(0);
}


*/




// new_handler example
#include <iostream>    
#include <cstdlib>      
#include <new>         

void no_memory () {
  std::cout << "Failed to allocate memory!\n";
  std::exit (1);
}

int main ()
{
  std::set_new_handler(no_memory);
  std::cout << "Attempting to allocate 1 GiB...";
  char* p = new char [1024*1024*1024];
  std::cout << "Ok\n";
  delete[] p;
  return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
