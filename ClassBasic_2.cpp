// ClassBasic2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// UTD hagin structure(fields) and methods (behaviour)

#include <iostream>
#include "Date.h"

//my_lib::Date add_days(my_lib::Date start_date, int number_of_days) {
//
//    constexpr int max_days_in_month{ 30 };
//    constexpr int max_months{ 12 };
//
//    int month{ start_date.month};
//    int year{ start_date.year };
//    int day{ start_date.day + number_of_days };
//
//    if (day > max_days_in_month) {
//         month = month + (day / max_days_in_month);
//         day = day % max_days_in_month;
//    }
//
//    if (month > max_months) {
//        year = year + (month / max_months);
//        month = month % max_months;
//    }
//   my_lib::Date new_date{ day, month, year };
//   return new_date;
//}


int main()
{
    my_lib::Date today{ 18,8,2021 };
    std::cout << "\nToday Date : " << std::endl;
    std::cout << "Day   : " << today.day << std::endl;
    std::cout << "Month : " << today.month << std::endl;
    std::cout << "Year  : " << today.year << std::endl;

    int days{ 15 }; //{40}
   /* today.day += days;
    std::cout << "Day   : " << today.day << std::endl;*/
    std::cout << "\nParty Date : " << std::endl;
    /* my_lib::Date party_date = add_days(today, days);*/
    my_lib::Date party_date = today.add_days(days);
    party_date.printDate();
    my_lib::Date* ptr = &party_date;
    ptr->printDate();
    my_lib::Date booking_date = today.add_days(5);
    booking_date.printDate();
}