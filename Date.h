#pragma once
#include <string>
#include <stdexcept>
inline namespace my_lib {
	enum class Month : std::int8_t { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

	class Day {

	public:
		Day() = default;
		explicit Day(int d) {
			if (is_day_valid(d)) {
				_day = d;
			}
			else {
				throw std::invalid_argument("The day is invalid! (Should be in the range of (1..30)\n");
			}
		}
		//Accessor : getter
		//Implicitely treated inline since it's defined inside the class
		int getDay() const {
			return _day;
		}

		//Modifier : setter
		void setDay(int day) {
			if (is_day_valid(day)) {
				_day = day;
			}
			else {
				throw std::invalid_argument("The day is invalid! (Should be in the range of (1..30)\n");
			}
		}

	private:
		int _day{ 19 }; //in class Initializers
		Day(float) = delete;
		Day(double) = delete;
		Day(char) = delete;
		bool is_day_valid(int d)const {
			return d >= 1 && d <= 30;
		}
	};


	class Date
	{
	public:

		/*Default constructor ; Parameterized constructor : Initialize the date instance to given date*/
		explicit Date(Day d = Day{}, Month m = Month::apr, int y = 2000);

		/*Prints the date (day,month,year) foramt*/
		std::string getDate()const;

		/*Takes integer as a argument. add argument as number of days;Returns the new date*/
		Date add_days(int number_of_days);

		/*Returns integer representing year from the date*/
		int getYear();

		/*Returns integer representing day from the date*/
		int getDay() const;

		/*Returns integer representing month from the date*/
		int getMonth() const;

	private:
		Day day;
		Month month;
		int year;
		/*Returns true if the date is valid otherwise returns false*/
		bool is_year_valid(int year)const;

	};


}
