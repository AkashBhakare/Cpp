#include "Student.h"
#include <cstring>
#include <fstream>
#include <limits>
#include <iostream>
std::ostream& mylib::operator<<(std::ostream& out, const Student& ref)
{
    out << "Name : " << ref.name << '\n';
    out << "Roll Number : " << ref.rollno << '\n';
    out << "Percentage  : " << ref.percentage << '\n';

    return out;
}

std::ofstream& mylib::operator<<(std::ofstream& fout, const Student& ref)
{
    fout.write(reinterpret_cast<const char*>(&ref), sizeof(ref));
    return fout;
}

std::ifstream& mylib::operator>>(std::ifstream& fin, Student& ref)
{
    fin.read(reinterpret_cast<char*>(&ref), sizeof(ref));
    return fin;
}

std::fstream& mylib::operator>>(std::fstream& fin, Student& ref)
{
    fin.read(reinterpret_cast<char*>(&ref), sizeof(ref));
    return fin;
}

std::fstream& mylib::operator<<(std::fstream& fout, const Student& ref)
{
    fout.write(reinterpret_cast<const char*>(&ref), sizeof(ref));
    return fout;
}

std::istream& mylib::operator>>(std::istream& in, Student& ref)
{
    in.ignore();
    std::cout << "Enter Student's Name : ";
    in.getline(ref.name, sizeof(ref.name), '\n');

    size_t rollno{};
    std::cout << "Enter Student's Roll number : ";
    in >> ref.rollno;

    std::cout << "Enter Student's Percentage : ";
    in >> ref.percentage;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}

mylib::Student::Student(std::string tname, size_t trollno, float tpercentage)
{
    std::memcpy(name, tname.c_str(), tname.size());
    rollno = trollno;
    percentage = tpercentage;
}