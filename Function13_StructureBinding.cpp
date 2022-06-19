// Function13_StructureBinding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*  Write a function which takes a float value as its argument and returns
     1. largest integer not greater than the argument
     2. Smallest ingeter not smaller than the argument
     minmax(12.5F)
         max =  12
         min =  13
     */

#include <iostream>
#include <cstdlib>
#include <tuple>
#include <string>
#include <cmath>


std::tuple<int, int>  minmax_magic1(float); //using structure binding

//auto minmax_magic2(float);
auto minmax_magic2(float f_var)
{
    int imax = static_cast<int>(std::ceil(f_var));
    int imin = static_cast<int>(std::floor(f_var));
    return std::make_tuple(imin, imax);
}


int main()
{
    float f_var{};
    std::cout << "Please enter a float value : ";
    std::cin >> f_var;
    //Structure binding
    auto [imax1, imin1] = minmax_magic1(f_var);
    std::cout << "Maximum : " << imax1 << "\tMinimum : " << imin1 << "\n";

    std::cout << "Please enter a float value : ";
    std::cin >> f_var;
    //Structure binding
    auto [imax2, imin2] = minmax_magic2(f_var);
    std::cout << "Maximum : " << imax2 << "\tMinimum : " << imin2 << "\n";
    return EXIT_SUCCESS;
}

std::tuple<int, int> minmax_magic1(float f_var)
{
    int imax = static_cast<int>(std::ceil(f_var));
    int imin = static_cast<int>(std::floor(f_var));
    return std::make_tuple(imin, imax);

}
