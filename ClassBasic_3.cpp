// ClassBasic_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
int main()
{
	my_lib::Date date;
	date.init();
	date.printDate();
	//date.init(my_lib::Month::sep, 6, 1995);
	//date.init(6, 9 , 1995);
	//date.init(1995, 6, my_lib::Month::sep);
	date.init(6, my_lib::Month::sep, 1995);
	date.printDate();

	using my_lib::Month;

	date.init(6, Month::dec, 1995);
	date.printDate();

	//date.month = 33;
	date.month = Month::jan;
	date.printDate();
	date.day = 900;
	date.printDate();
}
