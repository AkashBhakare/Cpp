// explicit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <iomanip>
#include <thread>
#include <conio.h>
using namespace std;

int main()
{
    const unsigned feet_per_yard{ 3 };
    const unsigned inches_per_foot{ 12 };
    double length{};       //length as decimal yards
    unsigned int yards{};  //whole yards
    unsigned int feet{};   //whole feet
    unsigned int inchese{};//whole inches
    std::cout << "Enter a length in yards as a decimal: ";
    std::cin >> length;
    //Get the length as yards, feet, and inches
    yards = static_cast<unsigned>(length);
    feet = static_cast<unsigned>(length) - yards * feet_per_yard;
    inches = static_cast<unsigned>(length) * feet_per_yard * inches_per_foot % inches_per_foot;
    std::cout << length << "yards converts to "
        << yards << " yards "
        << feet << "'feet"
        << inches << "inches." << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(10));
}



