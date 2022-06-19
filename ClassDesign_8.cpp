// ClassDesign_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include "Box.h"

int gvar{ 99 }; //Global variable
void foo() {
    double gvar{ 34.56 }; //local variable
    /*Functions give preference to local varaibles*/
    std::cout << "foo::Gvar : " << gvar << std::endl;
    /*using scope resolution operator we can instruct the compiler to access the global variable*/
    std::cout << "inside foo :: gvar " << ::gvar << std::endl;
}

void baz() {
    std::cout << "baz::Gvar : " << gvar << std::endl;;
}


int main()
{
    /* foo();
     baz();*/
    try {
        std::cout << "Default Size Box \n";
        my_lib::Box box1{};
        std::cout << "Size of box1 :" << sizeof(box1) << " bytes\n";
        std::cout << "box1 address  : " << &box1 << std::endl;
        std::cout << "Box1 Length : " << box1.getLength() << std::endl;

        //   box1.getLength(); = > Box::getLength(&box1);

        std::cout << "Box1 Height : " << box1.getHeight() << std::endl;
        std::cout << "Box1 Width : " << box1.getWidth() << std::endl;
        box1.setHeight(70);
        box1.setWidth(50);
        box1.setLength(100);
        std::cout << "Box1 Length new : " << box1.getLength() << std::endl;
        std::cout << "Box1 Height new: " << box1.getHeight() << std::endl;
        std::cout << "Box1 Width  new: " << box1.getWidth() << std::endl;

        //Method chaning
        box1.setHeight(7)->setWidth(5)->setLength(10);
        std::cout << "Box1 Length new : " << box1.getLength() << std::endl;
        std::cout << "Box1 Height new: " << box1.getHeight() << std::endl;
        std::cout << "Box1 Width  new: " << box1.getWidth() << std::endl;

        //box1.setHeight(7).setWidth(5).setLength(10); //error
         //Method chaning
        box1.set_height(17).set_width(15).set_length(30);
        std::cout << "Box1 Length new : " << box1.getLength() << std::endl;
        std::cout << "Box1 Height new: " << box1.getHeight() << std::endl;
        std::cout << "Box1 Width  new: " << box1.getWidth() << std::endl;

        std::cout << "Default Custom Box \n";
        my_lib::Box box2{ 10,5,7 };
        std::cout << "box2 address  : " << &box2 << std::endl;
        std::cout << "Box2 Length : " << box2.getLength() << std::endl;

        //    box2.getLength(); = > Box::getLength(&box2);

        std::cout << "Box2 Height : " << box2.getHeight() << std::endl;
        std::cout << "Box2 Width : " << box2.getWidth() << std::endl;
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}