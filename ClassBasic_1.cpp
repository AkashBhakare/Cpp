// ClassBasic_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Understand how to design a class

#include <iostream>
#include "Student.h"

int main()
{
    my_library::Student obj{};
    std::cout << "Size of Student : " << sizeof(obj) << " Bytes" << std::endl;
    std::cout << "Name : " << obj.name << std::endl;
    std::cout << "Roll No : " << obj.roll_no << std::endl;
    std::cout << "Percentage : " << obj.percentage << std::endl;



    my_library::Student aman{10,88.78f,"Aman"};
    //Accessing the member using object (Direct Access)
    //object.member
    std::cout << "Name : " << aman.name << std::endl;
    std::cout << "Roll No : " << aman.roll_no << std::endl;
    std::cout << "Percentage : " << aman.percentage << std::endl;
    aman.percentage = 90.65F;
    std::cout << "Percentage : " << aman.percentage << std::endl;
    std::cout << std::endl;


    //Accessing the member inderctly using pointer
    //pointer_to_object -> member
    std::cout << "Accessing the member using pointer to object using indirect selection(->):\n";
    my_library::Student* ptr = &aman;
    std::cout << "Name : " << ptr->name << std::endl;
    std::cout << "Roll No : " << ptr->roll_no << std::endl;
    std::cout << "Percentage : " << ptr->percentage << std::endl;
    std::cout << std::endl;

    std::cout << "Accessing the member using pointer to object deference operator:\n";
    my_library::Student akash{ 10,88.78,"Akash B" };
    ptr = &akash;
    std::cout << "Name : " << (*ptr).name << std::endl;
    std::cout << "Roll No : " << (*ptr).roll_no << std::endl;
    std::cout << "Percentage : " << (*ptr).percentage << std::endl;
    std::cout << std::endl;
    
    
    
    // Oder of initializers matter
    //my_library::Student sai("Sairam",10,78.56f);

    //Accessing the member inderctly using References
    std::cout << "Accessing the member inderctly using References :\n";
    my_library::Student& ref = aman;
    std::cout << "Name : " << ref.name << std::endl;
    std::cout << "Roll No : " << ref.roll_no << std::endl;
    std::cout << "Percentage : " << ref.percentage << std::endl;
    std::cout << std::endl;

}

