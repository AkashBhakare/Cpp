#include "Date.h"
#include <iostream>
#include <sstream>

namespace my_lib {

    void Date::printDate()
    {
        std::ostringstream output;
        output << "Date [" << day << ", " << month << ", " << year << " ]\n";
        std::cout << output.str();
    }

    Date Date::add_days(int number_of_days)
    {
        constexpr int max_days_in_month{ 30 };
        constexpr int max_months{ 12 };

        int m{ month };
        int y{ year };
        int d{ day + number_of_days };

        if (d > max_days_in_month) {
            m = m + (d / max_days_in_month);
            d = d % max_days_in_month;
        }

        if (m > max_months) {
            y = y + (m / max_months);
            m = m % max_months;
        }
        my_lib::Date new_date{ d, m, y };
        return new_date;
    }
}