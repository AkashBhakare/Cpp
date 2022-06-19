// ClassDesign_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <typeinfo>
#include <cstdio>
#include "Date.h"

void getUserDetails(my_lib::User user) {
    std::cout << "ID :" << user._id << "\tScore :" << user._score << "\n";
    return;
}

void getImprovedUserDetails(my_lib::UserImproved user) {
    std::cout << "ID :" << user._id << "\tScore :" << user._score << "\n";
    return;
}

int main()
{
    my_lib::Day  day1;
    std::cout << "Day = " << day1._day << std::endl;

    my_lib::Day  day2{ 20 };
    std::cout << "Day = " << day2._day << std::endl;

    std::cout << "Type name : " << typeid('\n').name() << "\n";

    // my_lib::Day  day3('\n'); // illegal 
     //std::cout << "Day = " << day3._day << std::endl;
     /*
     my_lib::Day  day4{ 14.56 };
     std::cout << "Day = " << day4._day << std::endl;

     my_lib::Day  day5{ 3.14F };
     std::cout << "Day = " << day5._day << std::endl;

     my_lib::Day  day6( 14.56 );
     std::cout << "Day = " << day4._day << std::endl;

     my_lib::Day  day7( 3.14F );
     std::cout << "Day = " << day5._day << std::endl;

     my_lib::Day  day7 = 45;
     */
    my_lib::Date somedate;
    std::cout << somedate.getDate() << std::endl;

    //kanishkaDOB 17th Feb 20
    //my_lib::Date kanishkaDOB(17, my_lib::Month::feb, 20);
    my_lib::Date kanishkaDOB{ my_lib::Day{ 17 }, my_lib::Month::feb, 20 };
    std::cout << "Kanashika's B'day :" << kanishkaDOB.getDate() << std::endl;

    using my_lib::Month;
    using my_lib::Day;
    try {
        my_lib::Date kanishkaDOC{ Day{ 3 }, Month::jan, 40 };
        std::cout << "Kanashika's Coronation Day :" << kanishkaDOC.getDate() << std::endl;
        /*  my_lib::Date kanishkaDOB1(20, my_lib::Month::feb, 17);*/
        //  std::cout << "Kanashikas B'day :" << kanishkaDOB1.getDate() << std::endl;
    }
    catch (std::invalid_argument& err) {
        std::cout << err.what() << std::endl;
    }

    my_lib::User u1{ 10,88.88f };
    getUserDetails(u1);
    getUserDetails(4); //Wrong : works boc of implicit conversion
    getUserDetails(5.45); //Wrong : works boc of implicit conversion
    getUserDetails({ 5,6 }); //Wrong : works boc of implicit conversion
    u1 = 5;
    u1 = 5.5;

    my_lib::UserImproved iu{ 4,90.45f };
    getImprovedUserDetails(iu);
    /*iu = 6;
    getImprovedUserDetails(45);
    getImprovedUserDetails({ 4,67.6F });*/
    return EXIT_SUCCESS;
}