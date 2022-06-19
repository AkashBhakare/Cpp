// ClassBasic_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include "Date.h"

int main() {
	my_lib::Date yesterday;
	std::cout << "Yesterday : " << yesterday.getDate();

	/*3-arg ctor called*/
	my_lib::Date today{ 20,my_lib::Month::aug, 2021 };
	std::cout << "Today : " << today.getDate();

	/*Single-arg ctor called*/
	my_lib::Date tomorrow{ 21 };
	std::cout << "Tomorrow : " << tomorrow.getDate();

	/*copy ctor called*/
	my_lib::Date now{ today };
	std::cout << "Now : " << now.getDate();
	return EXIT_SUCCESS;
}