#pragma once
#include "string"
namespace my_library {
	// UDT supplied in my_library
	//composite data type
	struct Student
	{
		int roll_no;      //Premitive type 
		float percentage; //Premitive type
		std::string name; //UDT : Provided by standard library
	};

}

