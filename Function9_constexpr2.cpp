// Function9_constexpr2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <stdexcept>
const int array_size1(int x) {
	return x + 1;
}

constexpr int array_size2(int x) {
	return x + 1;
}

void constant_variable_demo();
void constexpr_function_demo1();
void constexpr_function_branching();

int main()
{
	/*constant_variable_demo();
	constexpr_function_demo1();*/
	constexpr_function_branching();

	return EXIT_SUCCESS;
}

void constant_variable_demo()
{
	constexpr int a{ 10 };
	std::cout << "a:" << a << std::endl;
	//you cannot assign to a variable that is const
	// a = 20;  
	//std::cout << "a:" << a << std::endl;

	const int b{ 10 };
	std::cout << "b:" << b << std::endl;
	//you cannot assign to a variable that is const
	//b = 20;
	//std::cout << "b:" << b << std::endl;
}

void constexpr_function_demo1() {
	std::cout << "Calling array_size1(4) :" << array_size1(4) << std::endl;

	int a[10];  //literal : constant used to sepcify the size of array

	int size1{};
	std::cin >> size1;
	//expression did not evaluate to a constant
	int array1[size1]; //Error 

	const int size2{ 10 };
	int array2[size2]; //Ok

	constexpr int size3{ 10 };
	int array3[size3]; //Ok
	std::cout << "Calling array_size2(4) :" << array_size2(4) << std::endl;

	/*expression did not evaluate to a constant
	* Array size has to be specified at Compile time; whereas the functions
	* get executed at Runtime
	*  Error, constant expression required in array declaration
	*/
	//int array4[array_size1(4)];

	//Will get evaluated at compile time since the argument is constant
	int array5[array_size2(9)];
	std::cout << "Array5 size : " << sizeof(array5) << " Bytes\n";

	int size5{ 9 };
	//Will get evaluated at runtime since the argument is non-constant

	// OK, constexpr functions can be evaluated at compile time
   // and used in contexts that require constant expressions.
	std::cout << array_size2(size5);
	/*
	* ‘‘should be usable in a constant expression when given constant
		expressions as arguments”
		int array6[array_size2(size5)]; //Erorr
		Bcoz the argument to constexpr is ont const
	*/


	return;
}

/*
A branch of a conditional expression that is not taken in a constexpr
function is not evaluated.
This implies that a branch not taken can require run-time evaluation.
*/
constexpr int check(int i)
{
	constexpr int low{ 10 };
	constexpr int high{ 21 };
	return (low <= i && i < high) ? i : throw std::out_of_range("value is out of range");
}

void constexpr_function_branching() {
	constexpr int n1{ 15 };
	constexpr int n2{ 25 };

	try {
		//Call will get executed at compile time
		std::cout << "Calling Check with n1 : " << check(n1) << "\n";
		//Call will get executed at runtime time
		std::cout << "Calling Check with n2 : " << check(n2) << "\n";
	}
	catch (std::out_of_range& err) {
		std::cerr << err.what();
	}
}