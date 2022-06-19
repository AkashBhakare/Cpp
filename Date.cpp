#include "Date.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

inline namespace my_lib {

    Date::Date(Day d, Month m, int y)
    {
        //do input validation
        if (is_year_valid(y)) {
            year = y;
            month = m;
            day = d;
        }
        else {
            throw std::invalid_argument("The date set is invalid!");
        }
    }

    int Date::getDay() const {
        return day.getDay();
    }

    int Date::getMonth() const
    {
        return static_cast<int>(month);
    }


    inline int Date::getYear() {
        return year;
    }


    bool Date::is_year_valid(int y) const
    {
        if (!(y >= 1 and y < 2050))
            return false;

        return true;
    }


    std::string Date::getDate() const
    {
        std::ostringstream output;
        output << "Date [" << day.getDay() << ", " << static_cast<int>(month) << ", " << year << " ]\n";
        return output.str();
    }

    Date Date::add_days(int number_of_days)
    {
        constexpr int max_days_in_month{ 30 };
        constexpr int max_months{ 12 };

        int m{ static_cast<int>(month) };
        int y{ year };
        Day d{ day.getDay() + number_of_days };

        if (d.getDay() > max_days_in_month) {
            m = m + (d.getDay() / max_days_in_month);
            //     = d.getDay() % max_days_in_month;
        }

        if (m > max_months) {
            y = y + (m / max_months);
            m = m % max_months;
        }
        my_lib::Date new_date{ d, Month(m), y };
        return new_date;
    }
}