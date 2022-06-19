#pragma once
namespace my_lib {
	struct Date
	{
		int day;
		int month;
		int year;
		/*Prints the date (day,month,year) foramt*/
		void printDate();
		/*Takes integer as a argument.
		add argument as number of days
		Returns the new date*/
		Date add_days(int number_of_days);
	};
}