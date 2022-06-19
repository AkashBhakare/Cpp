// BITWISEOPERATOR001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <bitset>
#include <cstdint>
#include <thread>
#include <chrono>
#include <iomanip>

int main()
{
    //unsigned int of 8 bits
    uint8_t red{ 0xFF };    //255
    uint8_t green{ 0xFF };    //255
    uint8_t blue{ 0x00 };    //0
    uint8_t alpha{ 0xFF };    //255

    std::cout << "Red   :" << std::setw(8) << red
        << " Binary : " << std::bitset<8>(red) << std::endl;
    std::cout << "Red   :" << std::setw(8) << static_cast<int>(red)
        << " Binary : " << std::bitset<8>(red) << std::endl;
    std::cout << "Green   :" << std::setw(8) << static_cast<int>(green)
        << " Binary : " << std::bitset<8>(green) << std::endl;
    std::cout << "Blue   :" << std::setw(8) << static_cast<int>(blue)
        << " Binary : " << std::bitset<8>(blue) << std::endl;
    std::cout << "Alpha   :" << std::setw(8) << static_cast<int>(alpha)
        << " Binary : " << std::bitset<8>(alpha) << std::endl;

    uint32_t color{ 0b11111111'1111111'00000000'11111111 };
    std::cout << "color :" << color
        << " Binary : " << std::bitset<32>(color) << std::endl;
    std::cout << std::endl;

    //inserting Red
    color = red; //225
    std::cout << "color   :" << std::setw(10) << color
        << " Binary : " << std::bitset<32>(color) << std::endl;

    //inserting Green
    color = (color << 8)
        bitor green;	std::cout << "color   :" << std::setw(10) << color
        << " Binary : " << std::bitset<32>(color) << std::endl;
    //inserting Blue
    color = (color << 8) bitor blue;
    std::cout << "color   :" << std::setw(10) << color
        << " Binary : " << std::bitset<32>(color) << std::endl;
    //inserting Alpha
    color = (color << 8) bitor alpha;
    std::cout << "color   :" << std::setw(10) << color
        << " Binary : " << std::bitset<32>(color) << std::endl;

    std::cout << "color   :" << std::setw(10) << color
        << " Binary : " << std::bitset<32>(color) << std::endl;

    std::cout << std::endl << "Extracting colors " << std::endl;

   /* uint32_t g = (color >> 24U);
    std::cout << "Red  :" << std::setw(8) << r
        << " Binary :" << std::bitset<8>(r) << std::endl;

        uint32_t g = ((color << 8) >> 24);
    std::cout << "Green  :" << std::setw(8) << g
        << " Binary :" << std::bitset<8>(g) << std::endl;*/

    uint32_t b = ((color << 16) >> 24);
    std::cout << "Blue  :" << std::setw(8) << b
        << " Binary :" << std::bitset<8>(b) << std::endl;

    uint32_t a = ((color << 24) >> 24U);
    std::cout << "Alpha  :" << std::setw(8) << a
        << " Binary :" << std::bitset<8>(a) << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(30));

    return 0;
}