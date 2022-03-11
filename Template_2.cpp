// Template_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <stdexcept>
#include "non_generic_stack.h"
#include "generic_stack.h"
int main()
{
	//try {
	//    mylib::Stack_Integers stack(5);
	//    stack.push(10);
	//    stack.push(20);
	//    stack.push(30);
	//    stack.push(40);
	//    stack.push(50);
	//   // stack.push(60);
	//    std::cout << "Top element : " << stack.peek() << '\n';
	//    std::cout << "Deleted : " << stack.pop() << '\n';
	//    std::cout << "Deleted : " << stack.pop() << '\n';
	//    std::cout << "Deleted : " << stack.pop() << '\n';
	//    std::cout << "Deleted : " << stack.pop() << '\n';
	//    std::cout << "Deleted : " << stack.pop() << '\n';
	//  //  std::cout << "Deleted : " << stack.pop() << '\n';

	//    mylib::Stack_Double stack_d(3);
	//    stack_d.push(45.444);
	//    stack_d.push(46.444);
	//    stack_d.push(47.444);
	//    std::cout << "Deleted : " << stack_d.pop() << '\n';
	//    std::cout << "Deleted : " << stack_d.pop() << '\n';
	//    std::cout << "Deleted : " << stack_d.pop() << '\n';
	//    stack_d.push(48.444);


	//}
	//catch (std::exception & err) {
	//    std::cerr << err.what();
	//}

	try {
		mylib::Stack<int> stack_int(3);
		stack_int.push(10);
		stack_int.push(20);
		stack_int.push(30);
		std::cout << "Top element : " << stack_int.peek() << '\n';
		std::cout << "Deleted : " << stack_int.pop() << '\n';
		std::cout << "Deleted : " << stack_int.pop() << '\n';
		std::cout << "Deleted : " << stack_int.pop() << '\n';
		//	std::cout << "Deleted : " << stack_int.pop() << '\n';

		mylib::Stack<std::string> stack_strings(3);
		stack_strings.push("Akash");
		stack_strings.push("Sayali");
		stack_strings.push("Appu");
		std::cout << "Top element : " << stack_strings.peek() << '\n';
		std::cout << "Deleted : " << stack_strings.pop() << '\n';
		std::cout << "Deleted : " << stack_strings.pop() << '\n';
		std::cout << "Deleted : " << stack_strings.pop() << '\n';
		//std::cout << "Deleted : " << stack_strings.pop() << '\n';

		mylib::Stack<> stack_ints(5);
		stack_ints.push(100);
		stack_ints.push(200);
		stack_ints.push(300);
		std::cout << "Top element : " << stack_ints.peek() << '\n';
		std::cout << "Deleted : " << stack_ints.pop() << '\n';
		std::cout << "Deleted : " << stack_ints.pop() << '\n';
		std::cout << "Deleted : " << stack_ints.pop() << '\n';
		//	std::cout << "Deleted : " << stack_ints.pop() << '\n';

		mylib::Stack stack_integer(5);
		stack_integer.push(1000);
		stack_integer.push(2000);
		stack_integer.push(3000);
		std::cout << "Top element : " << stack_integer.peek() << '\n';
		std::cout << "Deleted : " << stack_integer.pop() << '\n';
		std::cout << "Deleted : " << stack_integer.pop() << '\n';
		std::cout << "Deleted : " << stack_integer.pop() << '\n';
		std::cout << "Deleted : " << stack_integer.pop() << '\n';
	}
	catch (std::exception& err) {
		std::cerr << err.what();
	}

}