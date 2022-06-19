// ClassBasic_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Date.h"
int main()
{
    // 3 args missing from RHS
    my_lib::Date today;
    std::cout << "today : " << today.getDate() << std::endl;

    // 2 args missing from RHS
    my_lib::Date tomorrow{ 21 };
    std::cout << "tomorrow : " << tomorrow.getDate() << std::endl;

    //1 args missing from RHS
    my_lib::Date dob{ 21 ,my_lib::Month::feb };
    std::cout << "Date of birth : " << dob.getDate() << std::endl;

    // 0 args missing from RHS
    my_lib::Date bday{ 30,my_lib::Month::jan,2001 };
    std::cout << "B'day : " << bday.getDate() << std::endl;

    // 1 args missing from LHS :error
    //my_lib::Date d1{ ,my_lib::Month::jan,2001 };

     // 2nd args missing //not allowed
    //my_lib::Date d1{21 , ,2001 };
}
