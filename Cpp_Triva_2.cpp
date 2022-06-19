// Cpp_Triva_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <sstream>

struct foo {};

std::ostream& operator << (std::ostream& os, const foo&) {
    os << "foo ostream\n";
    return os;
}
std::stringstream& operator << (std::stringstream& ss, const foo&) {
    ss << "foo string stream\n";
    return ss;
}

int main(void) {
    std::stringstream ss;
    ss << std::boolalpha << foo();
    std::cout << ss.str();
    return 0;
}
