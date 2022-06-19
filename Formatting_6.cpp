// Formatting_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<sstream>


std::ostream&  endl_tab(std::ostream& out) {
    out << "\n\t";
    //out << "\n--------------------------------------------------------------------\n";
    return out;
}

std::ostream& currency(std::ostream& out) {
    out.setf(std::ios::showpoint);
    out.setf(std::ios::fixed, std::ios::floatfield);
    out.precision(2);
    out << "Rs ";
    return out;
}

std::istream& pw(std::istream& in) {
    in.width(5);
    return in;
}


int main()
{
    std::cout << "Hello" << std::endl << "World!" <<std::endl;
    std::cout << "Hello" << endl_tab << "World!" << endl_tab;
    std::cout << std::endl;
    double amount{ 1234 };
    std::cout << "Amount : " << amount << std::endl;
    amount = 1234.56678;
    std::cout << "Amount : " << amount << std::endl;
    
    amount = 1234;
    std::cout << "Amount : " << currency << amount << std::endl;
    amount = 1234.56678;
    std::cout << "Amount : " << currency << amount << std::endl;


    std::string passphrase;
    std::cout << "Enter Password (not more that 5 characters ) :";
    std::cin >> pw >> passphrase;
    std::cout << "Password is : " << passphrase << std::endl;

    std::ostringstream ocout{};
    ocout << std::endl << "Hello" << std::endl << "world" << std::endl;
    ocout << endl_tab << "Hello" << endl_tab << "world" << std::endl;
    std::cout << "osting : " << ocout.str();

}





