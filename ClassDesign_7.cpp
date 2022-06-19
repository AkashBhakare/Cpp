// ClassDesign_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include "Date.h"

int main()
{
	try {
		my_lib::Date today{ my_lib::Day{26},my_lib::Month::aug, 2021 };
		std::cout << "Today : " << today.getDate() << std::endl;

		my_lib::Day aday1{ 26 };
		std::cout << "day1 : " << aday1.getDay() << std::endl;

		/*my_lib::Day aday2{ 35 };
		std::cout << "day2 : " << aday2.getDay() << std::endl;*/

		//aday1._day = -9999;
		//aday1.setDay(3434);
		aday1.setDay(13);
		std::cout << "day1 : " << aday1.getDay() << std::endl;

		my_lib::Date date1(aday1, my_lib::Month::aug, 2021);
		std::cout << date1.getDate() << std::endl;
		//date1.year = 0;
		//std::cout << "Year : " << date1.year << std::endl;
		std::cout << "Year  : " << date1.getYear() << std::endl;
		std::cout << "Month : " << date1.getMonth() << std::endl;
		std::cout << "Day   : " << date1.getDay() << std::endl;

		my_lib::Date date2{};
		std::cout << "today : " << date2.getDate() << std::endl;

		date1.getYear();
	}
	catch (std::invalid_argument& err) {
		std::cerr << err.what() << std::endl;
	}
	return 0;
}

