// Function14_struct_intro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
/*defining a userdefined type*/
struct student_rec {
	std::string name;
	int roll;
	float per;
};

struct datapack {
	int imax;
	int imin;
};


void structure_intro();
void print_student_rec(struct student_rec);
datapack minmax_magic(float f_var);
void structure_binding_demo();

int main()
{
	//structure_intro();
	structure_binding_demo();
	return EXIT_SUCCESS;
}

void structure_intro() {


	/*Creating structure variables*/
	struct student_rec s1 {};
	print_student_rec(s1);
	struct student_rec s2 { "Tejas", 12, 77.89F };
	print_student_rec(s2);
	//We can initialize one structure with another structure variable of same type
	student_rec s3 = s2;
	print_student_rec(s3);
	student_rec r4{};
	//We can assign one structure with another structure variable of same type
	r4 = s2;
	print_student_rec(r4);
	auto s4 = s2;
	print_student_rec(s4);



}

void print_student_rec(student_rec rec) {
	std::cout << "Name : " << rec.name
		<< "\tRoll no : " << rec.roll
		<< "\tPercentage : " << rec.per << "\n";
}


void structure_binding_demo() {
	float f_var{};
	std::cout << "Please enter a float value : ";
	std::cin >> f_var;
	//Structure binding
	auto [imax1, imin1] = minmax_magic(f_var); //c++17
	std::cout << "Maximum : " << imax1 << "\tMinimum : " << imin1 << "\n";
	datapack result = minmax_magic(f_var);   //C++98
	std::cout << "Maximum : " << result.imax
		<< "\tMinimum : " << result.imin << "\n";
}

//auto minmax_magic2(float);
datapack minmax_magic(float f_var)
{
	int imin_value = static_cast<int>(std::ceil(f_var));
	int imax_value = static_cast<int>(std::floor(f_var));
	return  { imax_value,imin_value };
}